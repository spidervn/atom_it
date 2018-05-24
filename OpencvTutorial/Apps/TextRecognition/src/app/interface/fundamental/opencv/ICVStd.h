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

// Image processing module
typedef int CVTermCriteria;

// Features 2D Classes 
typedef int CVFeatureDetector;
typedef int CVCirclesGridFinderParameters;

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

// Camera Calibration
#define CV_CALIB_CB_ADAPTIVE_THRESH     1
#define CV_CALIB_CB_NORMALIZE_IMAGE     2
#define CV_CALIB_CB_FILTER_QUADS        3
#define CV_CALIB_CB_FAST_CHECK          4

#define CV_CALIB_CB_SYMMETRIC_GRID      1
#define CV_CALIB_CB_ASYMMETRIC_GRID     2
#define CV_CALIB_CB_CLUSTERING          3

CVInputOutputArray CVNoArray = 0;

// Struct Template
template <typename T>
struct CVPtr
{    
    T t;
};

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

    /* 
     *   Finds the positions of internal corners of the chessboard.
     *   Parameters
     *      @image:         Source chessboard view. It must be an 8-bit grayscale or color image.
     *      @patternSize:   Number of inner corners per a chessboard row and column.
     *      @corners:       Output array of detected corners.
     *      @flags:         Various operation flags that can be zero or a combination of the following values (:List of values)
     */
    virtual void findChessboardCorners(CVInputArray image, 
                                        CVSize patternSize,
                                        CVOutputArray corners,
                                        int flags = CV_CALIB_CB_ADAPTIVE_THRESH + CV_CALIB_CB_NORMALIZE_IMAGE) = 0;

    /*  
     *  Renders the detected chessboard corners.
     *  Parameters:
     *      @image	        Destination image. It must be an 8-bit color image.
     *      @patternSize	Number of inner corners per a chessboard row and column (patternSize = cv::Size(points_per_row,points_per_column)).
     *      @corners	        Array of detected corners, the output of findChessboardCorners.
     *      @patternWasFound	Parameter indicating whether the complete board was found or not. 
     */
    virtual void drawChessboardCorners(CVInputOutputArray   image, 
                                        CVSize              patternSize,
                                        CVInputArray        corners,
                                        bool                patternWasFound) = 0;

    /* 
     *   Finds centers in the grid of circles.
     *   Parameters
     *      @image:	        grid view of input circles; it must be an 8-bit grayscale or color image.
     *      @patternSize:   number of circles per row and column ( patternSize = Size(points_per_row, points_per_colum) ).
     *      @centers:       output array of detected centers.
     *      @flags:         various operation flags that can be one of the following values ( a list of values)
     *      @blob_Detector: feature detector that finds blobs like dark circles on light background.
     *      @parameters:    struct for finding circles in a grid pattern.
     */
    virtual bool findCirclesGrid(CVInputArray image,
                                    CVSize patternSize, 
                                    CVOutputArray centers,
                                    int flags, 
                                    CVPtr<CVFeatureDetector> & blob_Detector,
                                    CVCirclesGridFinderParameters parameters_) = 0;


    /* 
     *  Refines the corner locations.
     *  Parameters:
     *      @image	    Input image.
     *      @corners	Initial coordinates of the input corners and refined coordinates provided for output.
     *      @winSize	Half of the side length of the search window. For example, if winSize=Size(5,5) , then a 5∗2+1×5∗2+1=11×11 search window is used.
     *      @zeroZone	Half of the size of the dead region in the middle of the search zone over which the summation in the formula below is not done.
     *      @criteria	Criteria for termination of the iterative process of corner refinement.
     */
    virtual void cornerSubPix(CVInputArray image, 
                                CVInputOutputArray  corners,
                                CVSize              winSize,
                                CVSize              zeroZone,
                                CVTermCriteria      criteria) = 0;

};

#endif