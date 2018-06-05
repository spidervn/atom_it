#ifndef TEXTRECOGNITION_APP_INTERFACE_FUNDAMENTAL_OPENCV_IMORPHOLOGY_H_
#define TEXTRECOGNITION_APP_INTERFACE_FUNDAMENTAL_OPENCV_IMORPHOLOGY_H_

class IMorphology
{
public:
    virtual ~IMorphology() {};

    virtual void erode() = 0;
};

#endif
