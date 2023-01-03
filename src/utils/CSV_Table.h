#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>


class CSV_Table
{
public:
	// Returns a reference to the raw table
	std::vector<std::vector<std::string>>& getTable();

	/**
	* Dumps the content of the table to the console
	*/
	const void consoleDump() const;

	/**
	* Retrieves specified row of the table
	*
	* @param line_index - The index of the row
	*
	* @throws InvalidArugment If the index is out of bounds
	* 
	* @result Vector containing the line of the table,
	*		  Empty vector if error
	*/
	std::vector<std::string> getLine(const uint32_t line_index);

	/**
	* Retrieves specified element
	*
	* @param row - The row of the element
	* @param column - The column of the element
	*
	* @throws InvalidArugment If the index is out of bounds
	* 
	* @result String containing specified element,
	*		  Empty string if error
	*/
	std::string getElement(const uint32_t row, const uint32_t column);
	
	/**
	* Retrieves specified element as integer
	*
	* @param row - The row of the element
	* @param column - The column of the element
	*
	* @throws InvalidArugment If the index is out of bounds
	* @thrwos stoi conversion error
	*
	* @result Integer representation of specified element
	*/
	int getElementInt(const uint32_t row, const uint32_t column);
	
	/**
	* Retrieves specified element as float
	*
	* @param row - The row of the element
	* @param column - The column of the element
	*
	* @throws InvalidArugment If the index is out of bounds
	* @throws stof conversion error
	*
	* @result Float representation of specified element
	*/
	float getElementFloat(const uint32_t row, const uint32_t column);

	/**
	* Retrieves specified element
	*
	* @param row - The row of the element
	* @param column - The column of the element
	*
	* @throws InvalidArugment If the index is out of bounds
	* @throws stod conversion error
	*
	* @result Double representation of specified element
	*/
	double getElementDouble(const uint32_t row, const uint32_t column);

	const uint32_t getWidth() const;
	const uint32_t getHeight() const;

private:
	std::vector<std::vector<std::string>> m_Table;
	uint32_t m_Width, m_Height;
};

