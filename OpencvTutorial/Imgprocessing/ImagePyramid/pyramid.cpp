
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

Mat src, dst, tmp;

const char* window_name = "Pyramids Demo";

int main(int argc, char const *argv[])
{
	printf("\n Zoom In-Out demo \n");
	printf("----------\n");
	printf(" * [u] -> Zoom in \n");
	printf(" * [d] -> Zoom out \n");
	printf(" * [ESC] -> Close program \n \n");

	if (argc != 2) {
		printf("Usage: %s imag_file\n", argv[0]);
		return -1;
	}

	src = imread(argv[1]);	// Loads the test image
	if (src.empty()) {
		printf(" No data! -- Exiting the program \n");
		return -1;
	}

	tmp = src;
	dst = tmp;

	imshow( window_name, dst);

	for (;;) 
	{
		char c = (char)waitKey(0);

		if (c == 27) {
			break;
		}
		if (c == 'u') {
			pyrUp(tmp, dst, Size(tmp.cols*2, tmp.rows*2));
			printf("** Zoom In: Image x 2\n");
		}
		else if (c == 'd') 
		{
			pyrDown(tmp, dst, Size(tmp.cols/2, tmp.rows/2));
			printf("** Zoom out: Image /2\n");
		}

		imshow( window_name, dst);
		tmp = dst;
	}

	return 0;
}