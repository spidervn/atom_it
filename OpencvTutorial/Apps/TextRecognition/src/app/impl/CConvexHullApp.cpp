#include "CConvexHullApp.h"
#include <iostream>
using namespace cv;
using namespace std;

int CConvexHullApp::run(int argc, char* argv[])
{
    rng = RNG(12345);
    thresh_ = 100;
    max_thresh_ = 255;

    const char* sz_WindowName = "Source";
    CommandLineParser parser( argc, argv, "{@input | ../data/stuff.jpg | input image}" );

    src = imread( parser.get<String>( "@input" ), IMREAD_COLOR );
    if( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    
    cvtColor( src, srcGray, COLOR_BGR2GRAY );   // Convert to GrayScale Mode
    blur( srcGray, srcGray, Size(3,3) );        // Blurring Image

    namedWindow(sz_WindowName, WINDOW_AUTOSIZE);
    imshow(sz_WindowName, src);

    createTrackbar(" Threshold:", sz_WindowName, &thresh_, max_thresh_, trackbar_Callback, this);   
    trackbar_Callback( 0, this);
    waitKey(0);
    return 0;
}

void CConvexHullApp::trackbar_Callback(int val, void* pData)
{
    CConvexHullApp* p_App = (CConvexHullApp*) pData;

    if (p_App)
    {
        p_App->onThresholdChange();
    }
}

void CConvexHullApp::onThresholdChange()
{
    Mat threshold_output;
    Mat imgDraw;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;


    imgDraw = Mat::zeros(srcGray.size(), CV_8UC3);
    threshold( srcGray, threshold_output, thresh_, 255, THRESH_BINARY );
    findContours( threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

    vector<vector<Point> >hull( contours.size() );
    for( size_t i = 0; i < contours.size(); i++ )
    {   
        convexHull( contours[i], hull[i], false ); 
    }

    Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
    for( size_t i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
        drawContours( drawing, contours, (int)i, color, 1, 8, vector<Vec4i>(), 0, Point() );
        drawContours( drawing, hull, (int)i, color, 1, 8, vector<Vec4i>(), 0, Point() );

        drawContours( imgDraw, hull, (int)i, color, 2, 8, vector<Vec4i>(), 0, Point());
    }

    namedWindow( "Hull demo", WINDOW_AUTOSIZE );
    namedWindow( "ManualDraw", WINDOW_AUTOSIZE );
    imshow( "Hull demo", drawing );    
    imshow( "ManualDraw", imgDraw);

    // Make random convexHull
    Mat img_Random_;
    vector<Point> v_PointRand;
    vector<Point> v_Hull_Rand;
    Scalar color_Blue = Scalar(0xFF, 0 , 0); // BGR
    Scalar color_Yellow_ = Scalar(0, 0xFF , 0xFF); // BGR

    int wRand  = 500;
    int hRand = 500;
    int nPoints = 100;

    img_Random_ = Mat::zeros(cv::Size(wRand, hRand), CV_8UC3);
    for (size_t i = 0; i < nPoints; i++)
    {
        v_PointRand.push_back(Point( rng.uniform(0, hRand), rng.uniform(0, hRand)));        
    }

    convexHull(v_PointRand, v_Hull_Rand, false);
    for (size_t i = 0; i < v_Hull_Rand.size(); i++)
    {
        if (i==v_Hull_Rand.size()-1)
        {
            cv::line(img_Random_, v_Hull_Rand[i], v_Hull_Rand[0], color_Yellow_, 2);
        }
        else
        {
            cv::line(img_Random_, v_Hull_Rand[i], v_Hull_Rand[i+1], color_Yellow_, 2);
        }
    }    
    for (size_t i = 0; i < nPoints; i++)
    {        
        cv::line(img_Random_, v_PointRand[i], v_PointRand[i], color_Blue, 2);
    }

    namedWindow("Random", WINDOW_AUTOSIZE);
    imshow("Random", img_Random_);
}
