#include "CCannyEdgeApp.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

void CCannyEdgeApp::CannyThreshold(int choice, void* data)
{
    CCannyEdgeApp* p_App = (CCannyEdgeApp*)data;
    
    blur( p_App->src_gray, p_App->detected_edges, Size(3,3) );
    Canny( p_App->detected_edges, p_App->detected_edges, p_App->lowThreshold, p_App->lowThreshold*p_App->ratio, p_App->kernel_size );
    p_App->dst = Scalar::all(0);
    p_App->src.copyTo( p_App->dst, p_App->detected_edges);
    imshow( p_App->window_name, p_App->dst );
}

int CCannyEdgeApp::run(int argc, char* argv[])
{
    edgeThresh = 1;    
    max_lowThreshold = 100;
    ratio = 3;
    kernel_size = 3;
    window_name = "Edge Map";

    CommandLineParser parser( argc, argv, "{@input | ../data/fruits.jpg | input image}" );
    src = imread( parser.get<String>( "@input" ), IMREAD_COLOR ); // Load an image
    if( src.empty() )
    {
        std::cout << "Could not open or find the image!\n" << std::endl;
        std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
        return -1;
    }
    dst.create( src.size(), src.type() );
    cvtColor( src, src_gray, COLOR_BGR2GRAY );
    namedWindow( window_name, WINDOW_AUTOSIZE );
    createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CCannyEdgeApp::CannyThreshold, this );
    CannyThreshold(0, (void*)this);
    waitKey(0);   
    return 0;
}