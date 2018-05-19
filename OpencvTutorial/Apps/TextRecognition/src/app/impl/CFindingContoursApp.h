#ifndef TEXTRECOGNITION_APP_IMPL_CFindingContoursApp_H_
#define TEXTRECOGNITION_APP_IMPL_CFindingContoursApp_H_

#include "app/interface/IApplication.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class CFindingContoursApp : public IApplication
{
public:
    CFindingContoursApp() {};
    virtual ~CFindingContoursApp() {};

    int run(int, char*[]);
private:
    cv::Mat src; 
    cv::Mat src_gray;
    int thresh;
    int max_thresh;
    int retrievalMode;
    int retrieCount;
    cv::RNG rng;
protected:
    static void thresh_callback(int, void* );
    void myThresh_callback(int);
};

#endif

