#ifndef TEXTRECOGNITION_APP_IMPL_C2DFILTERAPP_H_
#define TEXTRECOGNITION_APP_IMPL_C2DFILTERAPP_H_

#include "app/interface/IApplication.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class C2DFilterApp : public IApplication
{
public:
    C2DFilterApp() {};
    virtual ~C2DFilterApp() {};

    int run(int, char*[]);
};

#endif