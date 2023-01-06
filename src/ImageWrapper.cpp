#include "ImageWrapper.h"


std::vector<uint8_t> ImageWrapper::decodeImageToRGBAVector(const char* filename, uint16_t& width, uint16_t& height) 
{

	//the raw pixels, size: 8 bits, range: 0 -> 255
	//decode method doesn't offer an overloaded method with uint16_t width/height, must stay unsigned int
	//doing uint16_t width, height throws back error in lodepng decode method
	unsigned int w, h;

	//decode
	//decode method doesn't offer an overloaded method with uint16_t width/height
	std::vector<uint8_t> imagepixels;
	unsigned error = lodepng::decode(imagepixels, w, h, filename);
	//if there's an error, display it
	if (error) 
		MIR::Log::writeEr("ImageWrapper->decodeImageToRGBAVector()", lodepng_error_text(error));
	else
	{
		width = w;
		height = h;
		//std::cout << w << std::endl;
	}

	return imagepixels;
}

//R, G, B, A, R, G, B, A, R, G, B, A, R, G, B, A <- RGBAVector
//increments by 4 through RGBAVector to fill out pixel struct, then adds to pixelVectorToReturn then returns it.
//maybe some optimization here somehow through pointers/refs, i should definitely not pass
//an entire copy of RGBAVector
std::vector<pixel> ImageWrapper::convertRGBAVectorToPixelVector(const std::vector<unsigned char>& RGBAVector)
{
	std::vector<pixel> pixelVectorToReturn;

	for (int i = 0; i < RGBAVector.size(); i += 4) {
		struct pixel p;
		p.r = RGBAVector.at(i);
		p.g = RGBAVector.at(i + 1);
		p.b = RGBAVector.at(i + 2);
		p.a = RGBAVector.at(i + 3);
		pixelVectorToReturn.push_back(p);
	}

	return pixelVectorToReturn;
}

//0 represents black, 1 represents white
double ImageWrapper::convertPixelToGreyscale(pixel pixel)
{
	return (0.2126 * pixel.r + 0.7152 * pixel.g + 0.0722 * pixel.b) / 255.0;
}


std::vector<double> ImageWrapper::convertPixelVectorToGreyscaleVector(const std::vector<pixel>& pixels)
{
	std::vector<double> doubleVectorToReturn;

	for (int i = 0; i < pixels.size(); i++)
	{
		double convertedPixel = convertPixelToGreyscale(pixels.at(i));
		doubleVectorToReturn.push_back(convertedPixel);
	}
	return doubleVectorToReturn;
}




std::ostream& operator<<(std::ostream& stream, const pixel& pixel)
{
	stream << "[" << "R:" << static_cast<int>(pixel.r) << " " << "G:" << static_cast<int>(pixel.g)
		<< " " << "B:" << static_cast<int>(pixel.b) << " " << "A:" << static_cast<int>(pixel.a) << "]";
	return stream;
}
