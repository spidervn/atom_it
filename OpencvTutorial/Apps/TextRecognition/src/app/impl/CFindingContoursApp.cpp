#include "CFindingContoursApp.h"
#include <iostream>

using namespace cv;
using namespace std;

int CFindingContoursApp::run(int argc, char* argv[])
{
    rng = RNG(12345);                           // RNG: Random Number Generator
    thresh = 100;                               
    max_thresh = 255;
    retrieCount = 4;
    const char* source_window = "Source";    
    String imgName("../data/happyfish.jpg");    // by default
    
    if (argc > 1)
    {
        imgName = argv[1];
    }

    src = imread(imgName, IMREAD_COLOR);
    if (src.empty())
    {
        cerr << "No image supplied ..." << endl;
        return -1;
    }

    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    blur( src_gray, src_gray, Size(3,3) );
    
    namedWindow( source_window, WINDOW_AUTOSIZE );
    imshow( source_window, src );

    createTrackbar("Canny thresh:", source_window, &thresh, max_thresh, thresh_callback, this);    
    createTrackbar("RetrievalModes:\r\n0-RETR_EXTERNAL\r\n1-RETR_LIST\r\n2-RETR_CCOMP\r\n3-RETR_TREE\r\n4-RETR_FLOODFILL", source_window, &thresh, max_thresh, thresh_callback, this);
    thresh_callback( 0, this);
    waitKey(0);
    return(0);    
}

void CFindingContoursApp::thresh_callback(int val, void* data)
{
    CFindingContoursApp* p_App = (CFindingContoursApp*) data;

    if (p_App)
    {
        p_App->myThresh_callback(val);
    }
}

void CFindingContoursApp::myThresh_callback(int)
{
    const char* sz_WindowContours = "Contours";
    const char* sz_WindowManualDraw = "Manual Drawing Contours";

    Mat canny_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    
    Canny( src_gray, canny_output, thresh, thresh*2, 3 );
    findContours( canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
    
    Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
    Mat drawingManual = Mat::zeros( canny_output.size(), CV_8UC3 );

    for( size_t i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        drawContours( drawing, contours, (int)i, color, 2, 8, hierarchy, 0, Point() );

        
        for (size_t j = 0; j < contours[i].size(); j++)
        {
            if (j==contours[i].size() - 1)
            {
                cv::line(drawingManual,contours[i][j], contours[i][0], color, 2);
            }
            else 
            {
                cv::line(drawingManual,contours[i][j], contours[i][j+1], color, 2);
            }
        }
    }

    namedWindow( sz_WindowContours, WINDOW_AUTOSIZE);
    namedWindow( sz_WindowManualDraw, WINDOW_AUTOSIZE);
    imshow(sz_WindowContours, drawing);
    imshow(sz_WindowManualDraw, drawingManual);
}