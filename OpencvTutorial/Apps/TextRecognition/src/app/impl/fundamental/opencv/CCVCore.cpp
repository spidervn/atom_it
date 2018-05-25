#include "CCVCore.h"

using namespace cv;

CCVCore::CCVCore()
{
}

void CCVCore::scanImgPixels(cv::Mat& I)
{
    CV_Assert(I.depth() == CV_8U);
    int count_Channel = I.channels();    
    int nRows = I.rows;
    int nCols = I.cols * count_Channel;
    uchar pixel_Info_[5];

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    uchar* p;
    int y;
    int x;
    int rawPos = 0;

    for (size_t i = 0; i < nRows; i++)
    {        
        p = I.ptr<uchar>(i);
        for (size_t j = 0; j < nCols;)
        {         
            // This is p[j]            
            // This is p[j]
            int k = 0;
            while (k<count_Channel)
            {                
                pixel_Info_[k] = p[j];
                k++;
                j++;
            }

            y = rawPos / I.rows;
            x = rawPos - (y*I.rows);

            // Print here
            printf("(%3d,%3d) = [%3d", y, x, pixel_Info_[0]);

            for (int i1=1;i1<count_Channel;i1++)
            {
                printf(",%3d", pixel_Info_[i1]);
            }

            printf("]; ");
            if (x == I.cols - 1)
            {
                printf("\r\n");
            }

            rawPos++;
        }
    }
    
    printf("\r\nRawPos = %d\r\n", rawPos);
    return ;
}