#include "PatientHandler.h"	

int PatientHandler::load(std::string filename)
{
    try
    {
        CSV_Util::read(filename, m_patientTable);
        MIR::Log::writeInfo("PatientHandler::load()", "Successfully loaded patient data!");

        // Create Patient Objects and populate the vector with them
        populatePatients();
    }
    catch (std::exception e)
    {
        MIR::Log::writeEr("PatientHandler::load()", e.what());
        return 0; // Error
    }

    return 1; // Success
}

void PatientHandler::populatePatients()
{
    if (!hasPatients())
    {
        std::string m_Error = "Error: No patients";
        MIR::Log::writeEr("PatientHandler->populatePatients()", "Patient Vector is Empty");
        throw std::runtime_error(m_Error);
    }

    for (int i = 1; i < m_patientTable.getWidth(); i++) {
        std::string image = m_patientTable.getElement(i, 0);
        uint16_t id = m_patientTable.getElementInt(i, 3);
        uint16_t age = m_patientTable.getElementInt(i, 4);
        char gender = m_patientTable.getElement(i, 5)[0];

        m_Patients.push_back(Patient(id, age, gender, image));
    }
}

bool PatientHandler::hasPatients()
{
    return m_patientTable.getTable().size() >= 1;
}
