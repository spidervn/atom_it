
#ifndef TEXTRECOGNITION_APP_IMPL_CLAPLACEAPP_H_
#define TEXTRECOGNITION_APP_IMPL_CLAPLACEAPP_H_

#include "app/interface/IApplication.h"

class CLaplaceApp : public IApplication
{
public:
    CLaplaceApp() {};
    virtual ~CLaplaceApp() {};

    int run(int, char*[]);
};

#endif // TEXTRECOGNITION_APP_IMPL_CLAPLACEAPP_H_

