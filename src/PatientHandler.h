#pragma once
#include "utils/Log.h"
#include "utils/CSV_Util.h"
#include "Patient.h"
class PatientHandler
{
public:
	// Loads the Dataset and populates the vector of patient objects
	int load(std::string filename);

	// Parses the correct values from the csv table and constructs patient objects
	void populatePatients();

	// Returns true if the patient vector has elements
	bool hasPatients();

private:
	CSV_Table m_patientTable;
	std::vector<Patient> m_Patients;
};