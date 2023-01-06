#pragma once

#include "vendor/lodepng.h"
#include <vector>
#include <iostream>
#include "utils/Log.h" 

struct pixel
{
	uint8_t r; //0 -> 255 red
	uint8_t g; //0 -> 255 green
	uint8_t b; //0 -> 255 blue
	uint8_t a; //alpha channel... decode returns values from 0 -> 255, google says alpha channel has values from 0 -> 1 though???
};

std::ostream& operator<<(std::ostream& stream, const pixel& pixeltoprint);


class ImageWrapper
{

public:

	static std::vector<uint8_t> decodeImageToRGBAVector(const char* filename, uint16_t& width, uint16_t& height);

	//takes an rgba vector [R, G, B, A, R, G, B, A] and returns a pixel vector [Pixel, Pixel]
	static std::vector<pixel> convertRGBAVectorToPixelVector(const std::vector<unsigned char>&);

	//takes pixel vector [pixel, pixel] converts to greyscale vector [0.71221, 0.23211]
	static double convertPixelToGreyscale(pixel pixel);

	static std::vector<double> convertPixelVectorToGreyscaleVector(const std::vector<pixel>& pixels);
};