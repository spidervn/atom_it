#ifndef TEXTRECOGNITION_APP_IMPL_CIMAGESEGMENTATIONAPP_H_
#define TEXTRECOGNITION_APP_IMPL_CIMAGESEGMENTATIONAPP_H_

#include "app/interface/IApplication.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class CImageSegmentationApp : public IApplication
{
public:
    CImageSegmentationApp() {};
    virtual ~CImageSegmentationApp() {};

    int run(int argc, char* argv[]);
};

#endif