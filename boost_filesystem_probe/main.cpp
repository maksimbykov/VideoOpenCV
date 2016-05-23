#include <iostream>
#include "DecomposeVideo.h"
#include "ImageProcessing.h"
#include "FITwriter.h"

int main(int argc, char* argv[])
{
	DecomposeVideo dv;
	//int FHFparameter = atoi( argv[2]);
	dv.ffmpeg( argv [1] );
	dv.run_processing(/*FHFparameter*/);
	dv.ffmpeg2video( argv [1] );

  return 0;
}