#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "app/impl/CLaplaceApp.h"
#include "app/impl/CCannyEdgeApp.h"
#include "app/impl/C2DFilterApp.h"
#include "app/impl/CHistogramApp.h"
#include "app/impl/CBackProjectApp.h"
#include "app/impl/CTemplateMatchingApp.h"
#include "app/impl/CFindingContoursApp.h"
#include "app/impl/CConvexHullApp.h"
#include "app/impl/CBoundingBoxesApp.h"
#include "app/impl/CImageSegmentationApp.h"

int main( int argc, char* argv[]) 
{
    IApplication* p_App;

    // p_App = new CLaplaceApp();
    // p_App = new CCannyEdgeApp();
    // p_App = new C2DFilterApp();
    // p_App = new CHistogramApp();
    // p_App = new CBackProjectApp();
    // p_App = new CTemplateMatchingApp();
    // p_App = new CFindingContoursApp();
    // p_App = new CConvexHullApp();
    // p_App = new CBoundingBoxesApp();
    p_App = new CImageSegmentationApp();
    p_App->run(argc, argv);

    return 0;
}