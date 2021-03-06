#include "ImageProcessing.h"

void ImageProcessing::readframe(std::string path_to_file)
{
	src = imread( path_to_file, 1 );// --after all we may to assign 2-nd parameter as 0 for return Grayscale 
	string filename = path_to_file ;
	filename+=".txt";
	ofstream out(filename);
	out << src.rows << endl << src.cols << endl ;// print dimensions of image 
	//Grayscaling
	cvtColor( src, src_gray, COLOR_RGB2GRAY );

	for(int j = 0; j < src_gray.cols*src_gray.rows; j++) //for Grayscale
	{
		int gray_scale = src_gray.at<uchar>(j);
		out << gray_scale << endl;
	}
	out.close();
}


void ImageProcessing::applyFilter (std::string path_to_file, int FHFparameter) //allows only FIT-file
{
	ofstream out;
	out.open("bin\\FHF5\\input4FHF.txt");
	out << "0\n" << "bin\\initbig4.tmp\n" <<  path_to_file + ".fts\n";
	out	<<  path_to_file + "out" + ".fts\n" << "0\n" << "100\n" << "3\n" << "3\n" <<"0\n"
		<< "bin\\initbig4.tmp\n" <<  path_to_file + ".fts\n" << "-\n" << "0\n" << "bin\\initbig4.tmp\n"
		<< "-\n" << "-\n" << "-\n" << "0\n" << "0\n" << "-\n" << "-\n" << "0\n" <<"0\n" <<"0\n" <<"0\n" <<"0\n" << "-\n" << "-\n"
		<<  "0\n" << "0\n" << "-\n" << "0\n" <<  path_to_file + ".fts\n" <<  path_to_file + "out" + ".fts\n"
		<< "log\\edges\n" << "0\n" << "bin\\initbig4.tmp\n" <<  path_to_file + ".fts\n" <<  path_to_file + "out" + ".fts\n"
		<< "1\n" << "0\n" <<"0\n" <<"0\n" << "1\n" << "1\n" <<  path_to_file + ".fts\n" <<  path_to_file + "out" + ".fts\n"
		<< FHFparameter << "\n";
	out.close();
	int ret = system("bin\\FHF5\\FHF5.2.exe bin\\FHF5\\input4FHF.txt");

}