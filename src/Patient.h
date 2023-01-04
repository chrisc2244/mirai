#pragma once
#include <string>
#include <vector>
#include "Image.h"

class Patient

{
public:

	Patient(const int ID, const int age, const char gender, const std::string imageFile);

	int getID() const;
	int getAge() const;
	char getGender() const;
	std::string getImageFile() const;

private:

	int m_ID;
	int m_age;
	char m_gender;
	std::string m_imageFile;
	std::vector<pixel> m_decodedpixels;
};


