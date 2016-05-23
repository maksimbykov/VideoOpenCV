#include "DecomposeVideo.h"
#include "ImageProcessing.h"
#include "FITwriter.h"
#include "FITreader2PNG.h"


void DecomposeVideo::ffmpeg( std::string path_to_video)
{	
	//system("mkdir C:\\Alias\\frames");
	//std::string fmpeg = "C:\\Alias\\ffmpeg.exe -i " + path_to_video + " C:\\Alias\\frames\\%d.png";   // path_to_video including filename of video
	std::string fmpeg = "bin\\ffmpeg.exe -i " + path_to_video + " frames\\%d.png";
	system(fmpeg.c_str());
}



void DecomposeVideo::ffmpeg2video (std::string path_to_video)
{
	path_to_video += "_out.avi";
	//std::string fmpeg = "bin\\ffmpeg.exe -f image2 -i frames\\%d.png.txtout.fts.png -q 0 " + path_to_video;
	std::string fmpeg = "bin\\ffmpeg.exe -f image2 -i frames\\%d.png_out.png -q 0 " + path_to_video;
	system( fmpeg.c_str() );
}



void DecomposeVideo::run_processing( /*int FHFparameter*/  /*fs::path full_path*/)
{
	/*fs::path apppath( fs::initial_path<fs::path>() );
	apppath = fs::system_complete( fs::path( full_path ) );*/

	path p ( /*apppath+ */ "frames\\");   // p reads clearer than argv[1] in the following code

	try
	{
		if (exists(p))    // does p actually exist?
		{
			if (is_regular_file(p))        // is p a regular file?   
				cout << p << " size is " << file_size(p) << '\n';

			else if (is_directory(p))      // is p a directory?
			{
				cout << endl << endl << p << "\n Processing in folder:\n";

				typedef vector<path> vec;             // store paths,
				vec v;                                // so we can sort them later

				copy(directory_iterator(p), directory_iterator(), back_inserter(v));

				sort(v.begin(), v.end());             // sort, since directory iteration
				// is not ordered on some file systems

				for (vec::const_iterator it (v.begin()); it != v.end(); ++it)
				{
					 std::string path = "bin\\openCV.exe " + (*it).string();
					 system(path.c_str());

					/*std::cout << endl << (*it).string() << endl;
					ImageProcessing ip;
					ip.readframe((*it).string());
					FITwriter fr;

					std::string str = (*it).string() + ".txt";

					fr.writeFIT(str);
					ip.applyFilter(str,FHFparameter);

					FITreader2PNG fr2png;
					fr2png.writePNG(str);*/

				}
			}

			else
				std::cout << p << " exists, but is neither a regular file nor a directory\n";
		}
		else
			cout << p << " does not exist\n";
	}

	catch (const filesystem_error& ex)
	{
		cout << ex.what() << '\n';
	}
}