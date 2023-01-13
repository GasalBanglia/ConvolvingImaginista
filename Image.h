/*
 *
 * utils.h
 *
 * Header file for my utilities for the shrew program.
 *
 */
using namespace std;

/*
 * pixel_rgba structure.
 *
 * Defines a structure that holds data on pixels 
 * within an image, using the RGBA color model.
 *
 */
struct pixel_rgba {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

/*
 * pixel_hsva structure.
 *
 * Defines a structure that holds data on pixels 
 * wiithin an image, using the HSV color model.
 *
 */
struct pixel_hsva {
	uint8_t h;
	uint8_t s;
	uint8_t v;
	uint8_t a;
};

/*
 * Image class.  
 * 
 * Defines a rectangular image array of pixels, each with
 * an encoding scheme (RGB, HSI, Grayscale)
 *
 * v0.1 We only provide support for RGBA schemes. The RGBA and the 
 * grayscale pixel matrixes will be encoded simultaneously.
 * 
 */
class Image {
	private:
	int width, height, size;
	uint8_t* rgba_bytes;
	pixel_rgba** pixels;
	uint8_t** pixels_gray;
	



	public:
	Image (int w, int h, uint8_t* bytes) {
		width = w;
		height = h;
		size = height * width * 4;
		//copy contents of bytes into rgba_bytes
		rgba_bytes = new uint8_t[size];
		for (int i = 0; i < (size); i++) {
			rgba_bytes[i] = bytes[i];
		}
		cout <<"Width/Height/Size: " << width << "/" << height << "/" << size << "\n\n";
		//Initialize the pixel arrays
		//We can't init a 2D array at once during runtime.
		//So we init rows first, then column positions.
		pixels = new pixel_rgba*[height];
		pixels_gray = new uint8_t*[height];
		int index = 0; //iterator position across bytes
		for (int i = 0; i < (height); i++) {
			pixels[i] = new pixel_rgba[width];
			pixels_gray[i] = new uint8_t[width];
			for (int j = 0; j < (width); j++) {
				//extract the next sequence of bytes
				//from the image array, into our current 
				//rgba pixel.
				pixels[i][j].r = bytes[index++]; 
				pixels[i][j].g = bytes[index++]; 
				pixels[i][j].b = bytes[index++]; 
				pixels[i][j].a = bytes[index++]; 

				//also calculate the gray value of each pixel
				//and insert it into our pixels_gray array.
				//We will use the average of the RGB values.
				//This is not the best, but it might work 
				//for our processing algorithms.
				int sum = pixels[i][j].r + pixels[i][j].g + pixels[i][j].b;
				sum = sum / 3;
				pixels_gray[i][j] = (uint8_t) sum;
			}
		}
	}

	/*
	 * returns a pointer to the pixels member.
	 */
	pixel_rgba** getPixelsRGBA() {
		return pixels;
	}

	/*
	 * returns a pointer to the pixels member.
	 */
	uint8_t** getPixelsGray() {
		return pixels_gray;
	}

	/*
	 * Convert 2D rgba pixels into a 1D byte array.
	 * TODO Pull data from the 2D array, not the rgba_bytes array.
	 */
	uint8_t* imageToBytesRGBA() {
		uint8_t* new_bytes = new uint8_t[size];
		for (int i = 0; i < size; i++) {
			new_bytes[i] = rgba_bytes[i];
		}
		return new_bytes;

	}

	/*
	 * Returns a pointer to a 1D description of the RGBA pixels of 
	 * the image, in grayscale.
	 */
	uint8_t* imageToBytesGray() {
		uint8_t* new_image = new uint8_t[size];
		int num_pixels = height * width;
		for (int i = 0; i < num_pixels; i++) {
			for (int j = 0; j < 4; j++) {
				if (j==3) {
					new_image[i+j] = 255;
				}
				else {
					new_image[i + j] = rgba_bytes[i];
				}
			}
		}
		return new_image;

	}


	/*
	 * printString
	 *
	 * prints a string describing the object to standard console output.
	 *
	 */
	void printString() {
		cout << "Image object\n" 		\
			"Height: " << height << 	\
			"\nWidth: " << width << 	\
			"\nSize: " << size << 		\
			"\n\n";
	}


};
