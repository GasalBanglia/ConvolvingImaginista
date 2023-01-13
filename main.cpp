/*
 *
 * main.cpp
 *
 * Main class for my shrew application.
 *
 * First usage of the utils file, that contains an Image class.
 *
 * v0.1 11/26/2022
 *
 */

#include <iostream>
#include <stdint.h>
#include "Image.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

using namespace std;

int main() {
	int width, height, bpp; //that's Bytes Per Pixel (I figure)

	// Load our image.
	// Request 4 channels (RGBA)
	uint8_t* rgb_image = stbi_load("shrew.bmp", &width, &height, &bpp, 4);

	//print out our newfound parameters.
	cout << "width, height, and bpp: " << width << ", " << height << ", " << bpp << "\n\n";

	// create an instance of our image class.
	cout << "Creating new Image object.\n\n";
	Image image = Image(width, height, rgb_image);

	//return the 2D RGBA pixel array to a 1D bytes array.
	uint8_t* new_image;
	cout << "Calling imageToBytesRGBA\n\n";
	new_image = image.imageToBytesRGBA();
	cout << "imageToBytesRGBA called successfully\n\n";

	image.printString();

	//check indices.
	int index = width*height*4 - 1;
	cout << "rgb_image[" << index << "] = " << rgb_image[index] << "\n\n";
	cout << "new_image[" << index << "] =" << new_image[index] << "\n\n";

	stbi_write_bmp("rewrite_shrew.bmp", width, height, bpp, new_image);

	cout << "Attempting to call getPixels()...\n\n";
	pixel_rgba** p = image.getPixels();
	int red = 189;
	cout << "Pixels[0][0] = " << unsigned(p[0][0].r) << "\n\n";
	cout << "red = " << red << "\n\n";

	return 0;
}

	

