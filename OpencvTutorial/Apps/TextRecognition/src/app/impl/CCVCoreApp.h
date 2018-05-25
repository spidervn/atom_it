#ifndef TEXTRECOGNITION_APP_IMPL_CCVCOREAPP_H_
#define TEXTRECOGNITION_APP_IMPL_CCVCOREAPP_H_

#include "app/interface/IApplication.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class CCVCoreApp : public IApplication
{
public:
    CCVCoreApp() {};
    virtual ~CCVCoreApp() {};

    int run(int, char*[]);
};

#endif

