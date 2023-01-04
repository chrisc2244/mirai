#pragma once
#include <string>
#include <vector>
#include "Image.h"

class Patient

{
public:

	Patient(const int ID, const int age, const char gender, const Image image, const std::vector<std::string> diagnoses);

	int getID() const;
	int getAge() const;
	char getGender() const;
	Image getImage() const;
	std::vector<std::string> getDiagnoses() const;

private:

	int m_ID;
	int m_age;
	char m_gender;
	Image m_image;
	std::vector<std::string> m_diagnoses;
};


