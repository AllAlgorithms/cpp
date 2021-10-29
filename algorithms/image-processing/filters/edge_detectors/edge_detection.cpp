void edgeDetection(Mat & image, vector & xKernel, vector & yKernel)
{
	Mat tempImage;

	if (image.channels() != 1)
	{
		cvtColor(image, tempImage, COLOR_BGR2GRAY);

		tempImage.copyTo(image);
	}
	else
	{
		image.copyTo(tempImage);
	}

	int kernelSize = sqrt (xKernel.size());

	vector values;

	int halfSize{ kernelSize / 2 };

	for (int i{ halfSize }; i < tempImage.rows - halfSize; i++)
	{
		for (int j{ halfSize }; j < tempImage.cols - halfSize; j++)
		{
			values.clear();

			for (int x = { -halfSize }; x <= halfSize; x++)
			{
				for (int y = { -halfSize }; y <= halfSize; y++)
				{
					unsigned char * pixelValuePtr = tempImage.ptr(i + x) + (j + y);

					values.push_back(*pixelValuePtr);
				}
			}

			long gX = inner_product(begin(values), end(values), begin(xKernel), 0);

			long gY = inner_product(begin(values), end(values), begin(yKernel), 0);

			long newPixelValue = abs(gX) + abs(gY);

			unsigned char * pixelValuePtr = image.ptr(i) + j;

			*pixelValuePtr = newPixelValue > 255 ? 255 : newPixelValue < 0 ? 0 : newPixelValue;
		}
	}
}
