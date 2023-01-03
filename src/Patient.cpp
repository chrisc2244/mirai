#include "Patient.h"

Patient::Patient(const int ID, int age, char gender, std::string imageFile)
{
	m_ID = ID;
	m_age = age;
	m_gender = gender;
	m_imageFile = imageFile;
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

std::string Patient::getImageFile()
{
	return m_imageFile;
}