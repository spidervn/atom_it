#ifndef TEXTRECOGNITION_APP_INTERFACE_FUNDAMENTAL_OPENCV_ITEMPLATEMATCHING_H_
#define TEXTRECOGNITION_APP_INTERFACE_FUNDAMENTAL_OPENCV_ITEMPLATEMATCHING_H_

class ITemplateMatching
{
public:
    virtual ~ITemplateMatching() {};

    virtual int templateMatching_Sqdiff() = 0;    
};

#endif
