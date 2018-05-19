#ifndef TEXTRECOGNITION_APP_IMPL_CTemplateMatchingApp_H_
#define TEXTRECOGNITION_APP_IMPL_CTemplateMatchingApp_H_

// CTemplateMatchingApp
#include "app/interface/IApplication.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

class CTemplateMatchingApp : public IApplication
{
public:
    CTemplateMatchingApp();
    virtual ~CTemplateMatchingApp() {};

    int run(int, char*[]);

protected:
    bool use_mask;    
    cv::Mat img; 
    cv::Mat templ; 
    cv::Mat mask; 
    cv::Mat result;

    const char* image_window; //  = "Source Image";
    const char* result_window; //  = "Result window";    

    int match_method;
    int max_Trackbar;
private:
    static void MatchingMethod( int, void* );

    void _myMatchingMethod( int);
};

#endif