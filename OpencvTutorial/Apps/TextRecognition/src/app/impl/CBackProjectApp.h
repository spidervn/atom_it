
#ifndef TEXTRECOGNITION_APP_IMPL_CBACKPROJECTAPP_H_
#define TEXTRECOGNITION_APP_IMPL_CBACKPROJECTAPP_H_

#include "app/interface/IApplication.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class CBackProjectApp : public IApplication
{
public:
    CBackProjectApp() {};
    virtual ~CBackProjectApp() {};

    int run(int argc, char* argv[]);
protected:
    static void Hist_and_Backproj(int , void* data);
private:
    cv::Mat src; 
    cv::Mat hsv; 
    cv::Mat hue;
    int bins;    
    
};

#endif