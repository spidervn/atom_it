#include "CHistogramApp.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;

int CHistogramApp::run(int argc, char* argv[])
{
    // return histogramEqualize(argc, argv);
    return histogramCalc(argc, argv);
}

int CHistogramApp::histogramEqualize(int argc, char* argv[])
{
    Mat src;
    Mat dst;

    const char* source_window = "Source image";
    const char* equalized_window = "Equalized Image";
    CommandLineParser parser( argc, argv, "{@input | ../data/lena.jpg | input image}" );
    
    src = imread( parser.get<String>( "@input" ), IMREAD_COLOR );
    if( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    
    cvtColor( src, src, COLOR_BGR2GRAY );       // Convert to GrayScale
    equalizeHist( src, dst );                   // EqualizeHistogram

    namedWindow( source_window, WINDOW_AUTOSIZE );
    namedWindow( equalized_window, WINDOW_AUTOSIZE );

    imshow( source_window, src );
    imshow( equalized_window, dst );

    waitKey(0);
    return 0;
}

int CHistogramApp::histogramCalc(int argc, char* argv[])
{
    Mat src, dst;
    String imageName( "../data/lena.jpg" ); // by default
    if (argc > 1)
    {
        imageName = argv[1];
    }
    src = imread( imageName, IMREAD_COLOR );
    if( src.empty() )
    { return -1; }
    vector<Mat> bgr_planes;
    split( src, bgr_planes );
    int histSize = 256;
    float range[] = { 0, 256 } ;
    const float* histRange = { range };
    bool uniform = true; bool accumulate = false;
    Mat b_hist, g_hist, r_hist;
    int* arrHistogram = new int[(int)range[1]];
    
    calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
    manuallyHistogram(&bgr_planes[0], arrHistogram, histSize, (float*)histRange);
    
    // Draw the histograms for B, G and R
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );
    
    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );
    Mat hist_Manual_Image( hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

    for( int i = 1; i < histSize; i++ )
    {
        line(hist_Manual_Image, Point( bin_w* (i-1), hist_h - cvRound( arrHistogram[i-1]) ), 
                                Point( bin_w*(i), hist_h - cvRound( arrHistogram[i-1]) ),
                                Scalar( 255, 255, 0), 2, 8, 0  );        

        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                        Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                        Scalar( 255, 0, 0), 2, 8, 0  );
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                        Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                        Scalar( 0, 255, 0), 2, 8, 0  );
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                        Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                        Scalar( 0, 0, 255), 2, 8, 0  );
    }
    namedWindow("calcHist Demo", WINDOW_AUTOSIZE );
    imshow("calcHist Demo", histImage );

    namedWindow("Manually Histogram", WINDOW_AUTOSIZE);
    imshow("Manually Histogram", hist_Manual_Image);

    waitKey(0);

    delete []arrHistogram;
    return 0;    
}

int CHistogramApp::manuallyHistogram(Mat* img, int* arrHistogram, int histSize, float* histRange)
{
    CV_Assert(img->depth() == CV_8U);

    uchar* p;
    int n_Channel__ = img->channels();
    int nRows = img->rows;
    int nCols = img->cols * n_Channel__;

    int start_Range = histRange[0];
    int endOf_Range = histRange[1];

    //int* arrHistogram = new int[endOf_Range];                   // Histogram result
    memset(arrHistogram, sizeof(arrHistogram), 0);

    if (img->isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    for (size_t i = 0; i < nRows; i++)
    {
        p = img->ptr<uchar>(i); // Row i 
        for (int j=0;j<nCols;++j)
        {
            if (p[j]>=start_Range && p[j] < endOf_Range)
            {
                arrHistogram[p[j]]++;
            }
        }
    }

    return 0;
}