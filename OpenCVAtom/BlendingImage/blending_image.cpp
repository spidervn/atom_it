
#include <cv.h>
#include <highgui.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	double alpha = 0.5;
	double beta;
	double inp;

	Mat src1, src2, dst;

	cout << "Simple Linear Blender" << endl;
	cout << "--------------------" << endl;
	cout << "* Enter alpha [0-1]: " << endl;
	cin >> inp;

	if (inp >= 0 && inp <= 1) {
		alpha = inp;
	}

	src1 = imread("/home/spider/Pictures/Images/friendly_08_03.jpg");
	src2 = imread("/home/spider/Pictures/Images/friendly_08_02.jpg");

	if (!src1.data) {
		printf("Error loading src1 \n");
		return -1;
	}

	if (!src2.data) {
		printf("Error loading src2 \n");
		return -1;
	}

	namedWindow("Linear Blend", 1);

	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);

	imshow("Linear Blend", dst);
	waitKey(0);
	
	return 0;
}