#include "CCVCore.h"

using namespace cv;
using namespace std;

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

void CCVCore::scanImgPixels_Iterator_(cv::Mat& I)
{
    CV_Assert(I.depth() == CV_8U);

    const int count_Channel = I.channels();
    int nRawPos = 0;
    int nY = 0;
    int nX = 0;

    switch (count_Channel)
    {
        case 1:
        {
            MatIterator_<uchar> it, end;
            for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
            {
                printf("(%3d,%3d) = [%3d]; ", nY, nX, *it);
                
                nRawPos++;
                if (nX == I.cols - 1)
                {
                    nY++;
                    nX = 0;
                    printf("\r\n");
                }
                else
                {
                    nX++;
                }
            }            
            break;
        }
        case 3:
        {
            MatIterator_<Vec3b> it, end;
            for (it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)            
            {
                printf("(%3d,%3d) = [%3d,%3d,%3d]; ", nY, nX, (*it)[0], (*it)[1], (*it)[2]);
                if (nX == I.cols - 1)
                {
                    nY++;
                    nX = 0;
                    printf("\r\n");
                }
                else
                {
                    nX++;
                }
                nRawPos++;
            }
        }
        break;
    }
}

void CCVCore::scanImgPixels_Reference(cv::Mat& I)
{
    CV_Assert(I.depth() == CV_8U);
    const int count_Channel = I.channels();

    switch (count_Channel)
    {
        case 1:
        {
            for (size_t i = 0; i < I.rows; i++)
            {
                for (size_t j = 0; j < I.cols; j++)
                {
                    printf("(%3d,%3d) = [%3d]; ", i, j, I.at<uchar>(i,j));
                }
                printf("\r\n");
            }
            break;
        }
        case 3:
        {
            Mat_<Vec3b> _I = I;
            for (size_t i = 0; i < I.rows; i++)
            {
                for (size_t j = 0; j < I.cols; j++)
                {
                    printf("(%3d,%3d) = [%3d,%3d,%3d]; ", i, j, _I(i,j)[0], _I(i,j)[1], _I(i,j)[2]);
                }
                printf("\r\n");
            }            
            break;
        }
    }
}

void CCVCore::filter2D(cv::InputArray src, 
                            cv::OutputArray dst, 
                            int ddepth,
                            cv::InputArray kernel,
                            cv::Point anchor,
                            double delta = 0,
                            int borderType = cv::BORDER_DEFAULT)
{
    CV_Assert( dst.type() == src.type() && dst.rows() == src.rows() && dst.cols() == src.cols());

    int centerX = anchor.x;
    int centerY = anchor.y;

    if (anchor.x == -1 && anchor.y == -1)
    {
        centerX = anchor.x / 2;
        centerY = anchor.y / 2;
    }
    
    Mat m1 = src.getMat();
    Mat m2 = dst.getMat();
    Mat K = kernel.getMat();

    int c1 = m1.cols;
    int r1 = m1.rows;
    int c2 = m2.cols;
    int r2 = m2.rows;

    int cK = K.cols;
    int rK = K.rows;

    int num_Channel = src.channels();
    switch (num_Channel)
    {
        case 1:
            // o[i,j] = sum(k,l) k[k][l] * i[i+k-cx, j+l-cy]
            for (size_t x = 0; x < c1; x++)
            {
                for (size_t y = 0; y < r1; y++)
                {
                    int val = 0;

                    for (size_t x1 = 0; x1<cK; ++x1) {
                        for (size_t y1 = 0; y1<rK; ++y1) {
                            val = val + m1.at<uchar>(y + y1 - centerY, x + x1 - centerX) * K.at<float>(y1,x1);
                        }
                    }

                    uchar u_val = (uchar) val;
                    m2.at<uchar>(y, x) = u_val;
                }
            }            
            break;
        case 3:
            Mat_<Vec3b> m3b_src = m1;
            Mat_<Vec3b> m3b_dst = m2;

            for (size_t x = 0; x < c1; x++)
            {
                for (size_t y = 0; y < r1; y++)
                {
                    float val_0 = 0;
                    float val_1 = 0;
                    float val_2 = 0;

                    for (size_t x1 = 0; x1<cK; ++x1) {
                        for (size_t y1 = 0; y1<rK; ++y1) {
                            val_0 = val_0 + m3b_src(y + y1 - centerY, x + x1 - centerX)[0] * K.at<float>(y1,x1);
                            val_1 = val_1 + m3b_src(y + y1 - centerY, x + x1 - centerX)[1] * K.at<float>(y1,x1);
                            val_2 = val_2 + m3b_src(y + y1 - centerY, x + x1 - centerX)[2] * K.at<float>(y1,x1);
                        }
                    }

                    m3b_dst(y,x)[0] = (uchar)val_0;
                    m3b_dst(y,x)[0] = (uchar)val_0;
                    m3b_dst(y,x)[0] = (uchar)val_0;
                }
            }
            break;
    }
}