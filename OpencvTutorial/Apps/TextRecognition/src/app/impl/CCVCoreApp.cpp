#include "CCVCoreApp.h"
#include <iostream>

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include "app/impl/fundamental/opencv/CCVCore.h"

using namespace cv;
using namespace std;

int CCVCoreApp::run(int argc, char* argv[])
{
    cv::Mat src;

    src = imread( argv[1], IMREAD_COLOR );
    if( src.empty() )
    { 
        printf("Usage: ./%s <path_to_image>\r\n", argv[0]);
        return -1;
    }

    ICVCore* pCore = new CCVCore();
    // pCore->scanImgPixels(src);
    // pCore->scanImgPixels_Iterator_(src);
    pCore->scanImgPixels_Reference(src);

    delete pCore;
    return 0;
}