
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>

using namespace cv;
const int alpha_slider_max = 100;

int alpha_slider;
double alpha;
double beta;
Mat src1;
Mat src2;
Mat dst;

static void on_trackbar( int, void* )
{
   alpha = (double) alpha_slider/alpha_slider_max ;
   beta = ( 1.0 - alpha );
   addWeighted( src1, alpha, src2, beta, 0.0, dst);
   imshow( "Linear Blend", dst );
}

int main( int argc, char** argv)
{
	if (argc != 3)
	{
		printf("Usage: %s <image1> <image2>\r\n", argv[0]);

	}

	src1 = imread(argv[1]);
   	src2 = imread(argv[2]);

   	if( src1.empty() ) 
   	{ 
   		printf("Error loading src1 \n"); 
   		return -1; 
   	}

   	if( src2.empty() ) 
	{ 
		printf("Error loading src2 \n"); 
		return -1; 
	}

   	alpha_slider = 0;
   	namedWindow("Linear Blend", WINDOW_AUTOSIZE); // Create Window

   	char TrackbarName[50];
   	sprintf( TrackbarName, "Alpha x %d", alpha_slider_max );

   	createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar );
   	on_trackbar( alpha_slider, 0 );

   	waitKey(0);
   	return 0;
}