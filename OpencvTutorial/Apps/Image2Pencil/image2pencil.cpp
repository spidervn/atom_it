
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>

using namespace cv;
using namespace std;

int imageDodge(Mat& img, Mat& mask, Mat& imgRes)
{
	// Scan through every pixels of an image
	CV_Assert(img.depth() == CV_8U);
	
	Mat empty_Image(img.size().width, img.size().height, CV_8UC3, Scalar(0, 0, 0));

	int countChanel = img.channels();
	int nRows = img.rows;
	int nCols = img.cols * countChanel;

	if (img.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}

	int i,j;
	uchar* p;

	for (i=0; i<nRows;i++)
	{
		p = img.ptr<uchar>(i);
		for (j=0; j < nCols; ++j)
		{
			if (p[j] == 255)
			{
				
			}
		}
	}
	
	return 0;
}

int accessPixel(Mat& img, Mat& img_Res)
{
	printf("Image size=(%d,%d); (%d,%d)\r\n", img.size().width, img.size().height, img_Res.size().width, img_Res.size().height);

	printf("Image01: ChannelCount = %d, isContinous = %d\r\n", img.channels(), img.isContinuous());
	printf("Image02: ChannelCount = %d, isContinous = %d\r\n", img_Res.channels(), img_Res.isContinuous());

	CV_Assert(img_Res.size().width == img.size().width && img_Res.size().height == img.size().height);

	int countChannels = img.channels();
	int nRows = img.rows;
	int nCols = img.cols * countChannels;
	int n_PixelCols = img.cols;

	uchar* pixel;
	uchar* pixel_2;

	if (img.isContinuous())
	{
		nCols *= nRows;
		n_PixelCols = img.cols * img.rows;
		nRows = 1;
	}

	for (int i=0; i< nRows; i++)	
	{
		pixel = img.ptr<uchar>(i);
		pixel_2 = img_Res.ptr<uchar>(i);

		for (int j=0; j<nCols;j+= countChannels)
		{
			for (int k=0;k<countChannels;++k)
			{
				pixel_2[j+k] = pixel[j+k];
			}
		}
	}

	return 0;
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s image_file\n", argv[0]);
		return -1;
	}

	const char* window_src = "Source image";
	const char* window_dst = "Output image";
	const char* window_Invert = "Inverted window";
	const char* window_Blur = "Blurred (Gaussian Blur)";
	const char* window_Dodged = "Dodge Window";

	Mat src, dst;
	Mat src_hsv;
	Mat srcGray;
	Mat srcInverted;
	Mat srcBlur;
	
	src = imread(argv[1], IMREAD_COLOR);
	if (src.empty())
	{
		return -1;
	}
	
	
	cvtColor(src, srcGray, COLOR_BGR2GRAY);	// Convert from RGB to HSV

	// Mat srcDodgeImg;
	Mat srcDodgeImg(srcGray.size().height, srcGray.size().width, srcGray.type(), Scalar(0, 0, 0));	// Gray scale image	

	// Two ways for inverting an image
	// cv::subtract(cv::Scalar::all(255), srcGray, srcInverted);
	bitwise_not(srcGray, srcInverted);

	// Blur the image
	GaussianBlur(srcInverted, srcBlur, Size(21,21), 0, 0);

	// srcDodgeImg = src.clone();
	// imageDodge(srcDodgeImg);
	accessPixel(srcGray, srcDodgeImg);

	namedWindow( window_src, CV_WINDOW_AUTOSIZE);
	namedWindow( window_dst, CV_WINDOW_AUTOSIZE);
	namedWindow( window_Invert, CV_WINDOW_AUTOSIZE);
	namedWindow( window_Blur, CV_WINDOW_AUTOSIZE);
	namedWindow( window_Dodged, CV_WINDOW_AUTOSIZE);

	imshow(window_src, src);
	imshow(window_dst, srcGray);
	imshow(window_Invert, srcInverted);	
	imshow(window_Blur, srcBlur);
	imshow(window_Dodged, srcDodgeImg);

	waitKey(0);
	return 0;
}