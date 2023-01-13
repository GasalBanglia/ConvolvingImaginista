/*
 * ImageProcessor.h
 *
 * Header file for the ImageProcessor class.  No need to avoid verbosity; I 
 * already changed it from ImgProcessor to ImageProcessor.
 * 	What's two vowels between variables?
 *
 * Implements a variety of processing algorithms on the Image class,
 * defined within the Image.h class file.  The primary data structure
 * is a 2D pixel array; the pixel_rgba struct is also defined.  A 2D grayscale
 * array of the pixels is also defined for masks and other uses.
 *
 */

#include "Image.h"

class ImageProcessor {
	private:

	public:
		Image* invert(Image* img);
		
};
