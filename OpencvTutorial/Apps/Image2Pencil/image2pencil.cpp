
#include "opencv2/imgprocs.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s image_file\n", argv[0]);
		return -1;
	}

	const char* window_src = "Source image";
	const char* window_dst = "Output image";

	Mat src, dst;
	Mat src_hsv;
	
	src = imread(argv[1], IMREAD_COLOR);
	
	cvtColor(src, src_hsv, COLOR_BGR2HSV);	// Convert from RGB to HSV

	if (src.empty())
	{
		return -1;
	}

	namedWindow( window_src, CV_WINDOW_AUTOSIZE);
	namedWindow( window_dst, CV_WINDOW_AUTOSIZE);

	imshow(window_src, src_hsv);
	waitKey(0);

	return 0;
}