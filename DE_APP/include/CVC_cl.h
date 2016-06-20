/*---------------------------------------------------------------------------
   CVC_cl.h - OpenCL Cost Volume Construction Header
  ---------------------------------------------------------------------------
   Author: Charles Leech
   Email: cl19g10 [at] ecs.soton.ac.uk
   Copyright (c) 2016 Charlie Leech, University of Southampton.
   All rights reserved.
  ---------------------------------------------------------------------------*/
#include "ComFunc.h"
#include "common.h"

// CVPR 11
#define BORDER_THRES 0.011764
#define BORDER_CONSTANT 1.0

//#define TAU_1 0.7
//#define TAU_2 0.2
#define TAU_1 0.028
#define TAU_2 0.008
#define ALPHA 0.9

//
// TAD + GRD for Cost Computation
//
class CVC_cl
{
public:

    Mat lImg_ref;
    //Data Variables
    Mat lGray, rGray;
	Mat lGrdX, rGrdX;
	int maxDis;

	//OpenCL Variables
    cl_context* context;
	cl_command_queue* commandQueue;
    cl_program program;
    cl_kernel kernel;
    cl_int errorNumber;
    cl_event event;

    cl_int width, height, channels, dispRange;
    size_t bufferSize_color, bufferSize_grad, bufferSize_costVol;
    size_t globalWorksize[3];

	enum buff_id {CVC_LIMG = 0, CVC_RIMG, CVC_LGRDX, CVC_RGRDX, CV_LCV, CV_RCV, DS_LDM, DS_RDM};

    CVC_cl(cl_context* context, cl_command_queue* commandQueue, cl_device_id device, Mat l, const int d);
    ~CVC_cl(void);

	int buildCV(const Mat& lImg, const Mat& rImg, cl_mem* memoryObjects);
};
