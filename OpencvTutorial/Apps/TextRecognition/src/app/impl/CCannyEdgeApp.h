
#ifndef TEXTRECOGNITION_APP_IMPL_CCANNYEDGEAPP_H_
#define TEXTRECOGNITION_APP_IMPL_CCANNYEDGEAPP_H_

#include "app/interface/IApplication.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class CCannyEdgeApp : public IApplication
{
public:
    CCannyEdgeApp() {};
    virtual ~CCannyEdgeApp() {};

    int run(int, char*[]);
private:
    static void CannyThreshold(int, void*);

private:
    cv::Mat src, src_gray;
    cv::Mat dst, detected_edges;
    int edgeThresh;
    int lowThreshold;
    int max_lowThreshold;
    int ratio;
    int kernel_size;
    char* window_name;
};

#endif // TEXTRECOGNITION_APP_IMPL_CCANNYEDGEAPP_H_

