#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

Mat src, dst;
int morph_elem = 0;
int morph_size = 5;

int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;

const char* window_name = "mywin";

int main( int argc, char* argv[] )
{

    if (argc < 4)
    {
        printf("Usage: %s morph_operation morph_size image1\r\nmorph_operation=ERODE | DILATE | OPEN | CLOSE | GRADIENT | TOPHAT | BALCKHAT | HITMISS\r\nmorph_size: Integer (>=1)\r\n", argv[0]);
        return 0;
    }

    // Opening
    char* strOp = argv[1];
    char* strSize = argv[2];
    char* str_Img = argv[3];
    int morph_operator;
    morph_size = atoi(strSize);

    if ( strcmp(strOp, "ERODE") == 0)
    {
        morph_operator = MORPH_ERODE;
    }
    else if (strcmp(strOp, "DILATE") == 0)
    {
        morph_operator = MORPH_DILATE;
    }
    else if (strcmp(strOp, "OPEN") == 0)
    {
        morph_operator = MORPH_OPEN;
    }
    else if (strcmp(strOp, "CLOSE") == 0)
    {
        morph_operator = MORPH_CLOSE;
    }
    else if (strcmp(strOp, "GRADIENT") == 0)
    {
        morph_operator = MORPH_GRADIENT;
    }
    else if (strcmp(strOp, "TOPHAT") == 0)
    {
        morph_operator = MORPH_TOPHAT;
    }
    else if (strcmp(strOp, "BLACKHAT") == 0)
    {
        morph_operator = MORPH_BLACKHAT;
    }
    else if (strcmp(strOp, "HITMISS") == 0)
    {
        morph_operator = MORPH_HITMISS;
    }
    else {
        printf("Invalid parameter\r\n");
        return 0;
    }    

    src = imread(str_Img);
    if (src.empty())
    {
        printf("Could not open image\r\n");
        return 0;
    }

    namedWindow(window_name, WINDOW_AUTOSIZE);

    // Rect 
    Mat element = getStructuringElement(1, Size(2* morph_size+1, 2*morph_size+1), Point(morph_size, morph_size));
    morphologyEx(src, dst, morph_operator, element);

    imshow(window_name, dst);
    waitKey(0);
    return 0;
}