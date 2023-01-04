#pragma once
struct pixel
{
	uint8_t r; //0 -> 255 red
	uint8_t g; //0 -> 255 green
	uint8_t b; //0 -> 255 blue
	uint8_t a; //alpha channel... decode returns values from 0 -> 255, google says alpha channel has values from 0 -> 1 though???


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

	//example usage: 
	// std::string filename = "D:\\Downloads\\DatasetMirai\\00000001_001.png"
	//std::vector<uint8_t> rgbavalues = ImageWrapper::decodeImageToRGBAVector(filename);
	//std::vector<pixel> pixelvector = ImageWrapper::convertRGBAVectorToPixelVector(rgbvalues);
	//Image finalImageObject = createImage(filename, pixelvector, width, height);
	static std::vector<uint8_t> decodeImageToRGBAVector(const char* filename, uint16_t& width, uint16_t& height);

	//takes an rgba vector [R, G, B, A, R, G, B, A] and returns a pixel vector [Pixel, Pixel]
	static std::vector<pixel> convertRGBAVectorToPixelVector(const std::vector<unsigned char>&);
};