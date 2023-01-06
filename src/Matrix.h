#pragma once
#include <vector>
#include <iostream>
#include "ImageWrapper.h"

class matrix
{

public:

	//constructors
	matrix();
	matrix(const uint8_t rows, const uint8_t columns, const std::vector<pixel>& pixels);
	matrix(const uint8_t rows, const uint8_t columns, std::vector<double> greyscalevalues);


	//operations
	uint8_t get_row_amount() const;
	uint8_t get_column_amount() const;
	std::vector<pixel> get_column_at(uint8_t column);
	std::vector<pixel> get_row_at( uint8_t column);

	//operators
	matrix operator+(const matrix& other_matrix);
	matrix operator-(const matrix& other_matrix);
	matrix operator*(const matrix& other_matrix);


private:

	uint8_t m_rows;
	uint8_t m_columns;
	std::vector<pixel> m_input_pixel_vector;
	int m_size;
	std::vector<double> m_greyscale_values;

};