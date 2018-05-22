#ifndef TEXTRECOGNITION_APP_IMPL_CBOUNDINGBOXESAPP_H_
#define TEXTRECOGNITION_APP_IMPL_CBOUNDINGBOXESAPP_H_

#include "app/interface/IApplication.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class CBoundingBoxesApp : public IApplication
{
public:
    CBoundingBoxesApp() {};
    virtual ~CBoundingBoxesApp() {};

    int run(int argc, char* argv[]);
protected:
    static void Trackbar_Callback(int , void* data);
    void onThresholdChange();
private:
    cv::Mat src; 
    cv::Mat srcGray;
    cv::RNG rng;        // (12345);
    int thresh_;        // = 100;
    int max_thresh_;    // = 255;
};

#endif