#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
	double alpha = 0.5;
	double beta;
	double input;

	Mat src1, src2, dst;

	cout << "Simple Linear Blender " << endl;
	cout << "--------------------" << endl;
	cout << "* Enter alpha [0.0-1.0]: ";
	cin >> input;

	if (input >= 0 && input <= 1)
	{
		alpha = input;
	}

	//![load]
	// Read images (both have to be one of the same size and type)
	src1 = imread("./a1.jpg");
	src2 = imread("./a3.jpg");
	//! [load]

	if (src1.empty()) 
	{
		cout << "Error loading src1" << endl;
		return -1;
	}

	if (src2.empty())
	{
		cout << "Error loading src2" << endl;
		return -1;
	}

	//![blend_images]
	beta = (1.0 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);
	//![blend_images]

	//![display]
	imshow("Linear Blend", dst);
	waitKey(0);
	//![display]

	return 0;
}