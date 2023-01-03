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

	Image(const std::string filename, const std::vector<pixel> pixelvector);
	//Image(const std::string filename, const std::vector<pixel> decodedpixels, std::string correctDiagnosis);
	//maybe could include the correct diagnosis at some point

	std::string getFilename() const;
	std::vector<pixel>  getPixelVector() const;




private:

	std::string m_filename;
	std::vector<pixel> m_decodedpixels;
	//std::string m_correctDiagnosis; 

	

};