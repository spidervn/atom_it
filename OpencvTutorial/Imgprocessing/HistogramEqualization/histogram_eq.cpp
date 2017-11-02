
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

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

	Mat src, dst;
	const char* source_window = "Source Image";
	const char* equalized_window = "Equalized Image";

	src = imread(argv[1], IMREAD_COLOR);

	if (src.empty())
	{
		return -1;
	}

	cvtColor(src, src, COLOR_BGR2GRAY);
	equalizeHist(src, dst);

	namedWindow(source_window, WINDOW_AUTOSIZE);
	namedWindow(equalized_window, WINDOW_AUTOSIZE);

	imshow(source_window, src);
	imshow(equalized_window, dst);

	waitKey(0);
	return 0;
}