
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <stdio.h>
#include <stdlib.h>

using namespace cv;

int threshold_value = 0;
int threshold_type = 3;

int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;

Mat src, src_gray, dst;
char* window_name = "Threshold Value";
char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted\n 2: Truncate\n 3: To Zero\n 4: To Zero Inverted";
char* trackbar_value = "Value";

// Function headers
void Threshold_Demo(int, void*);

int main(int argc, char const *argv[])
{
	if (argc != 2) 
	{
		printf("Usage: %s image_file\n", argv[0]);
		return -1;
	}

	src = imread(argv[1], 1);

	cvtColor(src, src_gray, CV_BGR2GRAY);

	namedWindow( window_name, CV_WINDOW_AUTOSIZE);

	createTrackbar(trackbar_type, 
					window_name, &threshold_type,
					max_type, Threshold_Demo);
	createTrackbar(trackbar_value, 
					window_name, &threshold_value,
					max_value, Threshold_Demo);

	Threshold_Demo( 0, 0);

	// Wait until user finishes program 
	while (true)
	{
		int c;
		c = waitKey(20);

		if ((char)c == 27) 
		{
			break;
		}
	}
	return 0;
}

void Threshold_Demo(int, void*)
{
	/*
		0: Binary
		1: Binary Inverted 
		2: Threshold Truncated
		3: Threshold To Zero
		4: Threshold To Zero Inverted
	 */

	threshold( src_gray, dst, threshold_value, max_BINARY_valuem threshold_type);

	imshow( window_name, dst);
}