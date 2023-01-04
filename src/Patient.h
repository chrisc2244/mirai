#pragma once
#include <string>
#include <vector>
#include "Image.h"

class Patient

{
public:

	Patient(const uint16_t ID, const uint8_t age, const char gender, const Image image, std::vector<std::string> diagnoses);

	uint16_t getID() const;
	uint8_t getAge() const;
	char getGender() const;
	Image getImage() const;
	std::vector<std::string> getDiagnoses() const;

private:

	uint16_t m_ID;
	uint8_t m_age;
	char m_gender;
	Image m_image;
	std::vector<std::string> m_diagnoses;
};


