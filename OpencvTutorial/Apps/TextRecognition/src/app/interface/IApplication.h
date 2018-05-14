#ifndef TEXTRECOGNITION_APP_INTERFACE_IAPPLICATION_H_
#define TEXTRECOGNITION_APP_INTERFACE_IAPPLICATION_H_

class IApplication
{
public:
    virtual ~IApplication() {};

    virtual int run(int, char*[]) = 0;
};

#endif