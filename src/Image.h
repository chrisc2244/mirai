#pragma once
#include <vector>
#include <string>
#include "ImageWrapper.h"


//the .csv has fields like OriginalImage Width/Height, and OriginalImagePixelSpacing X,Y
//but I didn't include those fields here because I wasn't sure how we'd use it, so I'm keeping it simple, but we could add that later
//if we see some way to use that data. 


class Image 
{

public:

	Image();

	Image(const std::string filename);

	Image(const std::string filename, const std::vector<pixel> pixelvector, uint16_t width, uint16_t height);
	//maybe could include the correct diagnosis at some point

	std::string getFilename() const;
	std::vector<pixel>  getPixelVector() const;
	std::vector<uint8_t> getRGBAVector() const;
	void setRGBAVector(std::vector<uint8_t> RGBAVector);
	uint16_t getWidth() const;
	uint16_t getHeight() const;

private:

	std::string m_filename;
	std::vector<pixel> m_pixels;
	std::vector<uint8_t> m_rgba;
	uint16_t m_height;
	uint16_t m_width;
	bool m_loaded;
};