#include "Patient.h"

Patient::Patient() : m_ID(0), m_age(0), m_gender(0) { }

Patient::Patient(const uint16_t ID, const uint8_t age, const char gender, const Image image, std::vector<std::string> diagnoses)
{
	m_ID = ID;
	m_age = age;
	m_gender = gender;
	m_image = image;
	m_diagnoses = diagnoses;
}

uint16_t Patient::getID() const
{
	return m_ID;
}

uint8_t Patient::getAge() const
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
