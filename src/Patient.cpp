#include "Patient.h"
#include "Image.h"
#include <vector>

Patient::Patient(const int ID, const int age, const char gender, const Image image, const std::vector<std::string> diagnoses)
{
	m_ID = ID;
	m_age = age;
	m_gender = gender;
	m_image = image;
	m_diagnoses = diagnoses;
}


int Patient::getID() const
{
	return m_ID;
}


int Patient::getAge() const
{
	return m_age;
}

char Patient::getGender() const
{
	return m_gender;
}

Image Patient::getImage() const
{
	return m_image;
}

std::vector<std::string> Patient::getDiagnoses() const
{
	return m_diagnoses;
}
