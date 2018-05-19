#ifndef TEXTRECOGNITION_APP_IMPL_CREMAPAPP_H_
#define TEXTRECOGNITION_APP_IMPL_CREMAPAPP_H_

#include "app/interface/IApplication.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class CRemapApp : public IApplication
{
public:
    CRemapApp() {};
    virtual ~CRemapApp() {};

    int run(int, char*[]);
};

#endif