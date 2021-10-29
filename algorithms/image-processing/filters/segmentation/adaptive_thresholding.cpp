void adaptiveThresholdingSegmentation(Mat & image, const int kernelSize)
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

    int totalKernelElements = kernelSize * kernelSize;

    vector kernel(totalKernelElements, 1.0 / totalKernelElements);

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

            long averageValue = inner_product(begin(values), end(values), begin(kernel), 0.0);

            unsigned char * pixelValuePtr = image.ptr(i) + j;

            *pixelValuePtr = *pixelValuePtr > averageValue ? 0 : 255;
        }
    }
}
