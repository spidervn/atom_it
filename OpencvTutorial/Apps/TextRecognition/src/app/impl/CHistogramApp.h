#ifndef TEXTRECOGNITION_APP_IMPL_CHISTOGRAMAPP_H_
#define TEXTRECOGNITION_APP_IMPL_CHISTOGRAMAPP_H_

#include "app/interface/IApplication.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class CHistogramApp : public IApplication
{
public:
    CHistogramApp() {};
    virtual ~CHistogramApp() {};

    int run(int, char*[]);
protected:
    int histogramEqualize(int argc, char* argv[]);
    int histogramCalc(int argc, char* argv[]);

    int manuallyHistogram(cv::Mat* img, int* arrHistogram, int histSize, float* histRange);
};

#endif