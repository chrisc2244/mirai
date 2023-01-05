#include "CSV_Util.h"

std::string CSV_Util::m_Error = "none";

int CSV_Util::read(const std::string filename, CSV_Table& content)
{
	// Temporary row container
	std::vector<std::string> row;
	std::string line, word;
	std::fstream file(filename, std::ios::in);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			// Reset the row
			row.clear();

			std:: stringstream str(line);

			while (std::getline(str, word, ','))
				row.push_back(word);
			content.getTable().push_back(row);
		}
	}
	else // If the file failed to open, save error, throw exception, retrieve with CSV_Util::getError()
	{
		m_Error = "Error @ CSV_Util.read(): Could not open file: \"" + filename +"\"";
		throw std::invalid_argument(m_Error);
		return -1;
	}

	return 0;
}

const std::string CSV_Util::getError()
{
	return m_Error + '\n';
}

int CSV_Util::strToInt(const std::string element)
{
	int num = 0;
	try
	{
		num = std::stoi(element);
	}
	catch (std::exception& err)
	{
		m_Error = "Error @ CSV_Util::strToInt(): ";
		m_Error.append(err.what());
		std::exception_ptr eptr = std::current_exception();
		std::rethrow_exception(eptr);
	}
	return num;
}

float CSV_Util::strToFloat(const std::string element)
{
	float num = 0.0f;
	try
	{
		num = std::stof(element);
	}
	catch (std::exception& err)
	{
		m_Error = "Error @ CSV_Util::strToFloat(): ";
		m_Error.append(err.what());
		std::exception_ptr eptr = std::current_exception();
		std::rethrow_exception(eptr);
	}
	return num;
}

double CSV_Util::strToDouble(const std::string element)
{
	double num = 0.0;
	try
	{
		num = std::stod(element);
	}
	catch (std::exception& err)
	{
		m_Error = "Error @ CSV_Util::strToDouble(): ";
		m_Error.append(err.what());
		std::exception_ptr eptr = std::current_exception();
		std::rethrow_exception(eptr);
	}
	return num;
}
