
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s image\n", argv[0]);
		return -1;
	}

	Mat src, src_gray;
	Mat grad;
	const char* window_name = "Sobel Demo - Simple Edge Detector";
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

	src = imread(argv[1], IMREAD_COLOR);	// Load an image
	if (src.empty())
	{
		return -1;
	}

	GaussianBlur(src, src, Size(3,3), 0, 0, BORDER_DEFAULT);
	cvtColor(src, src_gray, COLOR_BGR2GRAY);

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	Sobel(src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);

	Sobel(src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);

	convertScaleAbs(grad_x, abs_grad_x);
	convertScaleAbs(grad_y, abs_grad_y);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
	imshow(window_name, grad);
	waitKey(0);

	return 0;
}