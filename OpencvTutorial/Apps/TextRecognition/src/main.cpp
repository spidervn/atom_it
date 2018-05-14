#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "app/impl/CLaplaceApp.h"
#include "app/impl/CCannyEdgeApp.h"
#include "app/impl/C2DFilterApp.h"

int main( int argc, char* argv[]) 
{
    IApplication* p_App;

    // p_App = new CLaplaceApp();
    // p_App = new CCannyEdgeApp();
    p_App = new C2DFilterApp();
    p_App->run(argc, argv);
    
    return 0;
}