void meanFiltering(Mat & image, const int kernelSize)
{
	Mat tempImage;

	image.copyTo(tempImage);

	int totalKernelElements = kernelSize * kernelSize;

	vector kernel(totalKernelElements, 1.0 / totalKernelElements);

	int imageChannels = image.channels();

	vector<vector> values(imageChannels);

	int halfSize{ kernelSize / 2 };

	for (int i{ halfSize }; i < tempImage.rows - halfSize; i++)
	{
		for (int j{ halfSize }; j < tempImage.cols - halfSize; j++)
		{
			for (int channel = 0; channel < imageChannels; channel++)
			{
				values[channel].clear();
			}

			for (int x = { -halfSize }; x <= halfSize; x++)
			{
				for (int y = { -halfSize }; y <= halfSize; y++)
				{
					for (int channel = 0; channel < imageChannels; channel++)
					{
						unsigned char * pixelValuePtr = tempImage.ptr(i + x) + ((j + y) * imageChannels) + channel;

						values[channel].push_back(*pixelValuePtr);
					}
				}
			}

			for (int channel = 0; channel < imageChannels; channel++)
			{
				vector channelValues = values[channel];

				long newPixelValue = inner_product(begin(channelValues), end(channelValues), begin(kernel), 0.0);

				unsigned char * pixelValuePtr = image.ptr(i) + (j * imageChannels) + channel;

				*pixelValuePtr = newPixelValue > 255 ? 255 : newPixelValue < 0 ? 0 : newPixelValue;
			}
		}
	}
}
