
#include <opencv2/core/utility.hpp>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	double alpha; /* Simple contrast control */
	int beta;	/* Simple brightness control */

	Mat image = imread(argv[1]);
	Mat new_image = Mat::zeros(image.size(), image.type());

	cout << "Basic linear Transform " << endl;
	cout << "--------------------" << endl;
	cout << "* Enter the alpha value [1.0-3.0]: ";
	cin >> alpha;
	cout << "* Enter the beta value [0-100]: ";
	cin >> beta;

	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; ++x)
		{
			for (int c = 0; c < 3; ++c)
			{
				new_image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha* (image.at<Vec3b>(y,x)[c]) + beta);
			}
		}
	}

	namedWindow("Original Image", 1);
	namedWindow("New Image", 1);

	imshow("Original Image", image);
	imshow("New Image", new_image);

	waitKey();
	return 0;
}