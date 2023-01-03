#pragma once

class Patient

{
public:

	Patient(const int ID, int age, char gender);

	int getID() const;
	int getAge() const;
	char getGender() const;

private:

	int m_ID;
	int m_age;
	char m_gender;

};


