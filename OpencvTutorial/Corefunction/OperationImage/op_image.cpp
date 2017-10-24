
#include <iostream>
#include <opencv2/core/utility.hpp>

using namespace std;
using namespace cv;

int main()
{
	// Load an image from a file
	Mat img = imread(filename);

	// Load grayscale image 
	Mat img = imread(filename, 0);

	// Save an image to a file
	imwrite(filename, img);

	// Accessing pixel intensity values
	Scalar intensity = img.at<uchar>(y,x);
	Scalar intensity = img.at<uchar>(Point(x, y));

	// Consider a 3 channel image with BGR color ordering 
	Vec3b intensity = img.at<Vec3b>(y,x);
	uchar blue = intensity.val[0];
	uchar green = intensity.val[1];
	uchar red = intensity.val[2];

	// You can use the same method for floating-point images
	Vec3f intensity = img.at<Vec3f>(y,x);
	float blue = intensity.val[0];
	float green = intensity.val[1];
	float red = intensity.val[2];

	// The same method can be used to change pixel intensities
	img.at<uchar>(y, x) = 128;

	vector<Point2f> points;
	Mat pointsMat = Mat(points);
	Point2f point = pointsMat.at<Point2f>(i, 0);	// One can access A point

	// Memory management and reference counting
	std::vector<Point3f> points;
	Mat pointsMat = Mat(points).reshape(1);

	Mat img = imread("image.jpg");
	Mat img1 = img.clone();

	Mat img = imread("image.jpg");
	Mat sobelx;
	Sobel(img, sobelx, CV_32F, 1, 0);

	// Primitive op
	img = Scalar(0);
	Rect r(10, 10, 100, 100);

	// A conversion from Mat to C API data structure
	Mat img = imread("image.jpg");
	IplImage img1 = img;
	CvMat m = img;

	Mat img = imread("image.jpg");
	Mat grey;
	cvtColor(img, grey, COLOR_BGR2GRAY);

	// Convert from 8UC1 to 32FC1
	src.convertTo(dst, CV_32F);

	// Visualizing images 
	Mat img = imread("image.jpg");
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", img);
	waitKey();

	// A call waitKey() starts a message passing cycle that waits for a key stroke in the "image" window; 
	//	A 32F image needs to be converted to 8U type
	Mat img = imread("image.jpg");
	Mat grey;
	cvtColor(img, grey, COLOR_BGR2GRAY);

	Mat sobelx;
	Sobel(grey, sobelx, CV_32F, 1, 0);

	double minVal, maxVal;
	minMaxLoc(sobelx, &minVal, &maxVal);
	Mat draw;
	sobelx.convertTo(draw, CV_8U, 255.0/(maxVal-minVal), -minVal*255.0/(maxVal-minVal));

	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", draw);
	waitKey();
}