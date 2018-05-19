#include "CBackProjectApp.h"
#include <iostream>

using namespace std;
using namespace cv;

int CBackProjectApp::run(int argc, char* argv[])
{
    bins = 25;
    src = imread( argv[1], IMREAD_COLOR );

    if( src.empty() )
    { 
        cout << "Usage: ./calcBackProject_Demo1 <path_to_image>" << endl;
        return -1;
    }

    cvtColor( src, hsv, COLOR_BGR2HSV );
    hue.create( hsv.size(), hsv.depth() );

    int ch[] = { 0, 0 };
    mixChannels( &hsv, 1, &hue, 1, ch, 1 );
    const char* window_image = "Source image";

    namedWindow( window_image, WINDOW_AUTOSIZE );
    createTrackbar("* Hue  bins: ", window_image, &bins, 180, Hist_and_Backproj, this );
    Hist_and_Backproj(0, 0);

    imshow( window_image, src );
    waitKey(0);

    return 0;
}

void CBackProjectApp::Hist_and_Backproj(int , void* data)
{
    CBackProjectApp* p_App = (CBackProjectApp*) data;

    if (p_App)
    {
        MatND hist;
        int histSize = MAX( p_App->bins, 2 );
        float hue_range[] = { 0, 180 };
        const float* ranges = { hue_range };
        calcHist( &p_App->hue, 1, 0, Mat(), hist, 1, &histSize, &ranges, true, false );
        normalize( hist, hist, 0, 255, NORM_MINMAX, -1, Mat() );
        MatND backproj;
        calcBackProject( &p_App->hue, 1, 0, hist, backproj, &ranges, 1, true );
        imshow( "BackProj", backproj );
        int w = 400; int h = 400;
        int bin_w = cvRound( (double) w / histSize );
        Mat histImg = Mat::zeros( w, h, CV_8UC3 );
        for( int i = 0; i < p_App->bins; i ++ )
            { rectangle( histImg, Point( i*bin_w, h ), Point( (i+1)*bin_w, h - cvRound( hist.at<float>(i)*h/255.0 ) ), Scalar( 0, 0, 255 ), -1 ); }
        imshow( "Histogram", histImg );
    }
}