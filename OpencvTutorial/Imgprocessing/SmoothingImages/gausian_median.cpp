
/*
	In this tutorial you will learn how to apply diverse linear filters to smooth images using OpenCV functions such as:
		cv::blur
		cv::GaussianBlur
		cv::mediaBlur
		cv::bilateralFilter
	Theory
		- Smoothing = blurring & 
		- Perform, we apply filter to our image.
			g(i,j) = sum(k,l) f(i+k, j+l)h(k,l)

				h(k,l) is called kernel.

			g(i,j) output
			f(i+k, j+l) input

	Normalized box filter
		Filter => Simplest of all
		Kernel is below 	
				K = 1/(K_width*K_height) [ [1 1 1 ... 1], [1 1 1 ... 1], ..., [1 1 1 ... 1]]

	Gaussian filter
		Most useful (Not fastest)
		Done by convolving each point in the input array with a Gaussian kernel
 		Just make the picture clearer, remember how a 1D Gaussian kernel look like ?
			G(x)
		Note
			G0(x,y) = Ae^( -(x-mx)^2/2_delta_x^2 + -(y-m_y)^2/2_delta_y^2 )
		
		Where m is the mean (peak) and delta represent the variance (per each of the variables x and y)

	Median filter 
 */

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;

Mat src; Mat dst;
char window_name[] = "Smoothing Demo";

int display_caption(const char* caption);
int display_dst(int delay);

int main(int argc, char** argv)
{
	namedWindow(window_name, WINDOW_AUTOSIZE);

	if (argc < 2) {
		printf("Usage %s img\n", argv[0]);
		return -1;
	}

	// src = imread("../data/lena.jpg", IMREAD_COLOR);
	src = imread(argv[1], IMREAD_COLOR);

	if (display_caption("Original Image") != 0) {
		return 0;
	}

	dst = src.clone();
	if (display_dst(DELAY_CAPTION) != 0) {
		return 0;
	}

	if (display_caption("Homegeneous Blur") != 0) {
		return 0;
	}

	for (int i=1; i < MAX_KERNEL_LENGTH; i+=2)
	{
		blur(src, dst, Size(i,i), Point(-1,-1));
		if (display_dst(DELAY_BLUR) != 0) {
			return 0;
		}
	}

	if (display_caption("Gaussian Blur") != 0) {
		return 0;
	}

	for (int i = 1; i < MAX_KERNEL_LENGTH; i+=2)
	{
		GaussianBlur(src, dst, Size(i, i), 0, 0);
		if (display_dst(DELAY_BLUR) != 0) {
			return 0;
		}
	}

	if (display_caption("Median Blur") != 0) {
		return 0;
	}

	for (int i = 1; i < MAX_KERNEL_LENGTH; i += 2)
	{
		medianBlur(src, dst, i);
		if (display_dst(DELAY_BLUR) != 0) {
			return 0;
		}
	}

	if (display_caption("Bilateral Blur") != 0) {
		return 0;
	}

	for (int i = 1; i < MAX_KERNEL_LENGTH; i += 2)
	{
		bilateralFilter(src, dst, i, i*2, i/2);
		if (display_dst(DELAY_BLUR) != 0) {
			return 0;
		}
	}

	display_caption("End: Press a key!");

	waitKey(0);
	return 0;
}

int display_caption(const char* caption)
{
	dst = Mat::zeros(src.size(), src.type());

	putText(dst, caption, 
				Point(src.cols/4, src.rows/2),
				FONT_HERSHEY_COMPLEX, 1, 
				Scalar(255,255,255));

	imshow(window_name, dst);
	int c = waitKey(DELAY_CAPTION);
	if (c >= 0) {
		return -1;
	}
	return 0;
}

int display_dst(int delay)
{
	imshow(window_name, dst);
	int c = waitKey(delay);
	if (c >= 0) {
		return -1;
	}

	return 0;
}