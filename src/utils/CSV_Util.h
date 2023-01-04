#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "CSV_Table.h"

class CSV_Util
{
public:
	/**
	* Reads the content of a .csv file into a CSV_Table object
	* 
	* @param filename - The file to read
	* @param content - The CSV_Table object to contain the content
	* 
	* @throws InvalidArugment If the file is not found
	* 
	* @result 0 if the file was read, -1 if error
	*/
	static int read(const std::string filename, CSV_Table& content);

	// Returns the error string for failed operations
	static const std::string getError();

	static int strToInt(const std::string element);

	static float strToFloat(const std::string element);

	static double strToDouble(const std::string element);
	
private:
	// Contains the error string describing failed operation
	static std::string m_Error;
};