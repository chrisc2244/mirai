#pragma once
#include <string>

class Patient

{
public:

	Patient(const int ID, int age, char gender, std::string imageFile);

	int getID() const;
	int getAge() const;
	char getGender() const;
	std::string getImageFile();

private:

	int m_ID;
	int m_age;
	char m_gender;
	std::string m_imageFile;
};


