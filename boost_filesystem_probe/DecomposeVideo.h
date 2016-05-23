#ifndef DECOMPOSE_VIDEO
#define DECOMPOSE_VIDEO

#include <string>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;

class DecomposeVideo
{
public:
	void ffmpeg(std::string path_to_video );
	void ffmpeg2video (std::string path_to_video);
	void run_processing( /*int FHFparameter*/ /*fs::path full_path*/);
};


#endif