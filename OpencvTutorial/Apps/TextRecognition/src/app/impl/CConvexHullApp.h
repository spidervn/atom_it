#ifndef TEXTRECOGNITION_APP_IMPL_CConvexHullApp_H_
#define TEXTRECOGNITION_APP_IMPL_CConvexHullApp_H_

#include "app/interface/IApplication.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class CConvexHullApp : public IApplication
{
public:
    CConvexHullApp() {};
    virtual ~CConvexHullApp() {};

    int run(int, char*[]);
private:        
    cv::Mat src; 
    cv::Mat srcGray;
    cv::RNG rng;             // (12345);
    int thresh_;             // = 100;
    int max_thresh_;         // = 255;
protected:
    static void trackbar_Callback(int val, void* pData);
    void onThresholdChange();
};

#endif

