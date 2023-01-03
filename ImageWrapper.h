#pragma once

struct pixel
{
	int r; //0 -> 255 red
	int g; //0 -> 255 green
	int b; //0 -> 255 blue
	int a; //alpha channel... decode returns values from 0 -> 255, google says alpha channel has values from 0 -> 1 though???


};

std::ostream& operator<<(std::ostream& stream, const pixel& pixeltoprint);


/* I'm not really sure if this needed to be a class tbh. Maybe my brain is just defaulting to everything being a class since 
* I'm coming from Java. Anyways, the idea is that we can iterate through the directory containing the dataset photos. We can then call
* ImageWrapper::decodeImagetoRGBAVector() on the PNG's to get our RGBA vector, then call convertRGBAVectorToPixelVector() to get our organized
* vector of pixels, then use that vector to construct our Image objects. 
*/

class ImageWrapper 
{

public:

	//example usage: ImageWrapper::decodeOneStep("D:\\Downloads\\DatasetMirai\\00000001_001.png");
	//the pixels of the image are returned in a vector, 4 bytes per pixel, ordered RGBARGBA
	//should these return a pointer or something? Or take a reference? the vector is like 4 million elements. I still suck at c++
	//but I know copying that is probably bad. :D
	static std::vector<unsigned char> decodeImageToRGBAVector(const char* filename);
	static std::vector<pixel> convertRGBAVectorToPixelVector(std::vector<unsigned char>&);




private:

	std::vector<pixel> pixelvector;
	std::vector<unsigned char> RGBAVector;

};