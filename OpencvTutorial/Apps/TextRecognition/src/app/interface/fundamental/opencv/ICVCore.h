#ifndef TEXTRECOGNITION_APP_INTERFACE_FUNDAMENTAL_OPENCV_ICVCORE_H_
#define TEXTRECOGNITION_APP_INTERFACE_FUNDAMENTAL_OPENCV_ICVCORE_H_

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class ICVCore
{
public:
    virtual ~ICVCore() {};

    virtual void scanImgPixels(cv::Mat& I) = 0;
    virtual void scanImgPixels_Iterator_(cv::Mat& I) = 0;
    virtual void scanImgPixels_Reference(cv::Mat& I) = 0;

    virtual void filter2D(cv::InputArray src, 
                            cv::OutputArray dst, 
                            int ddepth,
                            cv::InputArray kernel,
                            cv::Point anchor,
                            double delta = 0,
                            int borderType = cv::BORDER_DEFAULT) = 0;
};

#endif
