// Using OpenCV to blur an image.

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("jeep.jpg", CV_LOAD_IMAGE_UNCHANGED);

    // Check for no data
    if (! image.data )
    {
        cout << "Could not open or find the image.\n";
        return -1; // unsuccessful
    }

    blur(image,image,Size(10,10));

    namedWindow( "jeep", CV_WINDOW_AUTOSIZE );
    imshow( "jeep", image );

    waitKey(0);

    return 0;
}
