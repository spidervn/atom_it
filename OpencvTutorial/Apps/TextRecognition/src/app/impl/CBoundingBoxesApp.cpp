#include "CBoundingBoxesApp.h"
#include <iostream>

using namespace cv;
using namespace std;

int CBoundingBoxesApp::run(int argc, char* argv[])
{
    const char* szWindow_Name = "Source";
    rng = RNG(12345);
    thresh_ = 100;
    max_thresh_ = 255;
    
    CommandLineParser parser( argc, argv, "{@input | ../data/stuff.jpg | input image}" );
    src = imread( parser.get<String>( "@input" ), IMREAD_COLOR );
    if( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }

    cvtColor( src, srcGray, COLOR_BGR2GRAY );           // Convert image to Gray
    blur( srcGray, srcGray, Size(3,3) );                // Blurring the image
    
    namedWindow( szWindow_Name, WINDOW_AUTOSIZE );      // 
    imshow( szWindow_Name, src );                       // 

    createTrackbar( " Threshold:", "Source", &thresh_, max_thresh_, Trackbar_Callback, this);
    Trackbar_Callback( 0, this);

    waitKey(0);
    return(0);    
}

void CBoundingBoxesApp::Trackbar_Callback(int , void* data)
{
    CBoundingBoxesApp* p_App = (CBoundingBoxesApp*) data;

    if (p_App)
    {
        p_App->onThresholdChange();
    }
}

void CBoundingBoxesApp::onThresholdChange()
{
    Mat threshold_output;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    threshold( srcGray, threshold_output, thresh_, 255, THRESH_BINARY );            // Thresholding the image
    findContours( threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );

    vector<vector<Point> > contours_poly( contours.size() );
    vector<Rect> boundRect( contours.size() );
    vector<Point2f>center( contours.size() );
    vector<float>radius( contours.size() );

    for( size_t i = 0; i < contours.size(); i++ )
    {
        approxPolyDP( contours[i], contours_poly[i], 3, true );                     // approxPolyDP
        boundRect[i] = boundingRect( contours_poly[i] );
        minEnclosingCircle( contours_poly[i], center[i], radius[i] );               // minEnclosingCircle
    }

    Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
    for( size_t i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );           
        drawContours( drawing, contours_poly, (int)i, color, 1, 8, vector<Vec4i>(), 0, Point() );
        rectangle( drawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
        circle( drawing, center[i], (int)radius[i], color, 2, 8, 0 );
    }

    namedWindow( "Contours", WINDOW_AUTOSIZE );
    imshow( "Contours", drawing );
}