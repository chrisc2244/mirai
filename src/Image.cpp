#include "Image.h"
#include "ImageWrapper.h"



Image::Image(const std::string filename, const std::vector<pixel> pixelvector, uint16_t width, uint16_t height)
{
	m_filename = filename;
	m_pixels = pixelvector;
	m_width = width;
	m_height = height;

}

std::string Image::getFilename() const
{
	return m_filename;
}

std::vector<pixel> Image::getPixelVector() const
{
	return m_pixels;
}

std::vector<uint8_t> Image::getRGBAVector() const
{
	return m_rgba;
}

void Image::setRGBAVector(std::vector<uint8_t> RGBAVector)
{
	m_rgba = RGBAVector;
}

uint16_t Image::getWidth() const
{
	return m_width;
}

uint16_t Image::getHeight() const
{
	return m_height;
}