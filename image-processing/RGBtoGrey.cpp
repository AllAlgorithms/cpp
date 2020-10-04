#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat RGBimage=("cat.jpg");
	Mat Greyimage(RGBimage.rows,RGBimage.cols,CV_8UC1);
	for(int i=0;i<RGBimage.rows;++i)
	{
		for(int j=0;j<RGBimage.cols;++j)
		{
			Greyimage.at<uchar>(i,j)=(RGBimage.at<Vec3b>(i,j)[0]+RGBimage.at<Vec3b>(i,j)[1]+RGBimage.at<Vec3b>(i,j)[2])/3;
		}
	}
	imshow("RGBimage",RGBimage);
	imshow("Greyimage",Greyimage);
	waitKey(0);
	return 0;
}
