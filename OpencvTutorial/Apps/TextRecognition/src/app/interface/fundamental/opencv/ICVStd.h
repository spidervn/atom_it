#ifndef TEXTRECOGNITION_APP_INTERFACE_FUNDAMENTAL_OPENCV_ICVSTD_H_
#define TEXTRECOGNITION_APP_INTERFACE_FUNDAMENTAL_OPENCV_ICVSTD_H_

#include <stdio.h>
#include <stdlib.h>
// ICVStd.h

// Mat: Core object
typedef int CVMat;
typedef int CVSize;
typedef int CVScalar;

typedef int CVVideoCapture;
typedef int CVVideoWriter;

typedef int CVInputArray;
typedef int CVOutputArray;
typedef int CVInputOutputArray;

typedef int CVMatExpr;

// Border Type
#define CV_BORDER_CONSTANT      1
#define CV_BORDER_REPLICATE     2
#define CV_BORDER_REFLECT       3
#define CV_BORDER_WRAP          4
#define CV_BORDER_REFLECT_101   5
#define CV_BORDER_TRANSPARENT   6
#define CV_BORDER_REFLECT101    7
#define CV_BORDER_DEFAULT       8
#define CV_BORDER_ISOLATED      9

CVInputOutputArray CVNoArray = 0;

class ICVStd
{
public:
    virtual ~ICVStd() {};

    // Core functions
    virtual void absdiff(CVInputArray src1, CVInputArray src2, CVOutputArray dst) = 0;
    virtual CVScalar sum(CVInputArray src) = 0;
    
    // virtual CVMatExpr mul();
    virtual void GaussianBlur(CVInputArray src,
                                CVOutputArray dst,
                                CVSize ksize,
                                double sigmaX,
                                double sigmaY = 0,
                                int borderType = CV_BORDER_DEFAULT) = 0;

    virtual CVScalar mean(CVInputArray src, CVInputArray mask = CVNoArray) = 0;

    virtual CVScalar divide(CVInputArray src1, 
                            CVInputArray src2, 
                            CVOutputArray dst, 
                            double scale = 1, 
                            int dtype = -1) = 0;

    /*
     *  Divides a multi channel array into several single-channel arrays
     *      @src:       input multi-channel array
     *      @mvbegin:   output array.
     */
    virtual void split(const CVMat& src, CVMat* mvbegin) = 0;

     /*
      *  Creates one multi-channel array out of several single-channel ones.
      *     @mv:       	input array of matrices to be merged; all the matrices in mv must have the same size and the same depth.
      *     @count:     number of input matrices when mv is a plain C array; it must be greater than zero.
      *     @dst:       output array of the same size and the same depth as mv[0]; The number of channels will be equal to the parameter count.
      */
    virtual void merge(const CVMat* mv, size_t count, CVOutputArray dst) = 0;


};

#endif
