#include "FITwriter.h"
#include "fitsio.h"

void FITwriter::writeFIT(std::string path_to_file)
{
	FILE            *inFile;
	char			str0[1024];
	int				h, w, status, jj, ii;
	fitsfile *fptr;       /* pointer to the FITS file, defined in fitsio.h */
	long  fpixel, nelements;
  


	
	inFile = fopen( path_to_file.c_str(), "r" );

	//fscanf(inFile, "%s", str0);	
	fscanf(inFile, "%d", &w);
	fscanf(inFile, "%d", &h);

	unsigned char *img;


	
	std::string filename (path_to_file.c_str());
	filename+=".fts";
    int bitpix   =  BYTE_IMG; /* 8-bit unsigned short pixel values       */
    long naxis    =   2;  /* 2-dimensional image                            */    
    long naxes[2] = { h, w };   /* image is 300 pixels wide by 200 rows */


	/* allocate memory for the whole image */ 
    img = (unsigned char *)malloc( naxes[0] * naxes[1]  * sizeof( unsigned char ) );

	if (fits_create_file(&fptr, filename.c_str(), &status)){};/* create new FITS file */

	if ( fits_create_img(fptr,  bitpix, naxis, naxes, &status) ){};

	fpixel = 1;                               /* first pixel to write      */
    nelements = naxes[0] * naxes[1];          /* number of pixels to write */

	 /* initialize the values in the image */
	for (jj = 0; jj < naxes[1]; jj++)
    {   for (ii = 0; ii < naxes[0]; ii++)
        {
            fscanf(inFile, "%d", (img+ ii + jj * naxes[0]));
        }
    }

	 /* write the array of unsigned char to the FITS file */
	if ( fits_write_img(fptr, TBYTE, fpixel, nelements, img, &status) ){/*return(status);*/};

	//free( img );   //////////////////we`re fall together. we drink together - all for one!

	/* write another optional keyword to the header */
    /* Note that the ADDRESS of the value is passed in the routine */

    /*exposure = 1500;
    if ( fits_update_key(fptr, TLONG, "EXPOSURE", &exposure,
		"Total Exposure Time", &status) ){};*/           

	if ( fits_close_file(fptr, &status) ){/*return(status);*/};                /* close the file */
     
	fclose(inFile);
	//free( img );// it`s strange
	

}