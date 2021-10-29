void gaussianNoise(Mat & image, const unsigned char mean, const unsigned char sigma)
{
	default_random_engine generator;

	normal_distribution distribution(mean, sigma);

	int imageChannels = image.channels();

	for (int row = 0; row < image.rows; row++)
	{
		for (int column = 0; column < image.cols; column++)
		{
			for (int channel = 0; channel < imageChannels; channel++)
			{
				unsigned char * pixelValuePtr = image.ptr(row) + (column * imageChannels) + channel;

				long newPixelValue = *pixelValuePtr + distribution(generator);

				*pixelValuePtr = newPixelValue > 255 ? 255 : newPixelValue < 0 ? 0 : newPixelValue;
			}
		}
	}
}
