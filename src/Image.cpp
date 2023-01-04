#include "Image.h"
#include "ImageWrapper.h"

/*
Image::Image(std::string filename, std::vector<pixel> pixels, std::string correctDiagnosis)
{
	m_filename = filename;
	m_decodedpixels = pixels;
	m_correctDiagnosis = correctDiagnosis;
}
*/



Image::Image(std::string filename, std::vector<pixel> pixels)
{
	std::string m_filename = filename;
	std::vector<pixel> m_decodedpixels = pixels;
}

std::string Image::getFilename() const
{
	return m_filename;
}

std::vector<pixel> Image::getPixelVector() const
{
	return m_decodedpixels;
}

