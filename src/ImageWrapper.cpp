#include "lodepng.h"
#include <vector>
#include <iostream>
#include "ImageWrapper.h"
//#include "Log.h" idk why but this isnt working




std::vector<unsigned char> ImageWrapper::decodeImageToRGBAVector(const char* filename) 
{

	std::vector<unsigned char> imagepixels;
	 //the raw pixels, size: 8 bits, range: 0 -> 255
	unsigned int width, height;

	//decode
	unsigned error = lodepng::decode(imagepixels, width, height, filename);

	//if there's an error, display it
	if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

	return imagepixels;
}

//R, G, B, A, R, G, B, A, R, G, B, A, R, G, B, A <- RGBAVector
//increments by 4 through RGBAVector to fill out pixel struct, then adds to pixelVectorToReturn then returns it.
//maybe some optimization here somehow through pointers/refs, i should definitely not pass
//an entire copy of RGBAVector
std::vector<pixel> ImageWrapper::convertRGBAVectorToPixelVector(std::vector<unsigned char>& RGBAVector)
{
	std::vector<pixel> pixelVectorToReturn;

	for (int i = 0; i < RGBAVector.size(); i+=4) {
		struct pixel p;
		p.r = RGBAVector.at(i);
		p.g = RGBAVector.at(i + 1);
		p.b = RGBAVector.at(i + 2);
		p.a = RGBAVector.at(i + 3);
		pixelVectorToReturn.push_back(p);
	}

	return pixelVectorToReturn;
}


std::ostream& operator<<(std::ostream& stream, const pixel& pixel)
{
	stream << "R:" << pixel.r << " " << "G:" << pixel.g << " " << "B:" << pixel.b << " " << "A:" << pixel.a << " " << std::endl;
	return stream;
}



/*
* I was using this main function to test the new methods. I suppose
* this can serve as an example on how to use them. 
* 
* TODO: use the filename and pixel vector to create Image objects
*/


/*
int main()
{

	std::vector<unsigned char> cool = ImageWrapper::decodeImageToRGBAVector("D:\\Downloads\\DatasetMirai\\00000001_001.png");
	std::cout << cool.size() << std::endl;

	std::cout << "Trying out convertRGBA method" << std::endl;
	std::vector<pixel> awesomePixelVectorIcanSleep = ImageWrapper::convertRGBAVectorToPixelVector(cool);
	std::cout << awesomePixelVectorIcanSleep.size() << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << awesomePixelVectorIcanSleep.at(i) << std::endl;
	}
}
*/