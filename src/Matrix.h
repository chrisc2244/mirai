#pragma once
#include <vector>

class matrix
{

public:

	//constructors
	matrix();

	//takes in rows, columns, and double vector obtianed from convertPixelVectorToGreyscaleVector() method
	matrix(const uint8_t rows, const uint8_t columns, const std::vector<double> &values);

	matrix(const uint8_t rows, const uint8_t columns, double* arrPtr);


	//operations
	//returns m_rows
	uint8_t getRowAmount() const;

	//returns m_columns
	uint8_t getColumnAmount() const;

	//returns size of matrix
	uint8_t getSize() const;

	//prints values in matrix		[0.4213][0.4213][0.4213]
	//3x3 example, 6 values total	[0.4213][0.4213][0.4213]
	static void print(const matrix& matrix_to_print);


	//operators
	matrix operator+(const matrix& other_matrix) const;

	matrix operator-(const matrix& other_matrix) const;

	//yet to be implemented
	matrix operator*(const matrix& other_matrix) const;

	//access element in matrix[index]
	double& operator[](int index) const;

	//access element in matrix in (row, col) form
	double& operator() (int row, int col) const;

private:

	uint8_t m_rows;
	uint8_t m_columns;
	uint8_t m_size;
	double* m_ptr_double;
};