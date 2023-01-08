#pragma once
#include <vector>
#include "ImageWrapper.h"

class matrix
{

public:

	//constructors
	matrix();

	//unused atm, meant for pixel vectors but kinda unneeded atm
	//matrix(const uint8_t rows, const uint8_t columns, const std::vector<pixel> &pixels);

	//takes in rows, columns, and double vector obtianed from convertPixelVectorToGreyscaleVector() method
	matrix(const uint8_t rows, const uint8_t columns, const std::vector<double> &greyscalevalues);


	//operations
	//returns m_rows
	uint8_t get_row_amount() const;

	//returns m_columns
	uint8_t get_column_amount() const;

	//prints the given matrix in terminal
	static void print(const matrix& matrix_to_print);


	//operators
	matrix operator+(const matrix& other_matrix) const;

	matrix operator-(const matrix& other_matrix);

	//yet to be implemented
	matrix operator*(const matrix& other_matrix);

	//access element in matrix[index]
	double& operator[](int index) const;

	//access element in matrix in (row, col) form
	double& operator() (int row, int col) const;

	int size;
	int p_columns;
	int p_rows;

private:

	uint8_t m_rows;
	uint8_t m_columns;
	std::vector<pixel> m_input_pixel_vector;
	int m_size;
	std::vector<double> m_greyscale_values;
	double* m_ptr_double;
	//pixel* m_ptr_pixel;
};