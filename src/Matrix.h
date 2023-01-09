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
	static void print(const matrix& matrixToPrint);


	//operators
	matrix operator+(const matrix& otherMatrix) const;

	matrix operator-(const matrix& otherMatrix) const;

	//yet to be implemented
	matrix operator*(const matrix& otherMatrix) const;

	//access element in matrix[index]
	double& operator[](int index) const;

	//access element in matrix in (row, col) form starting at (0,0) for first element
	double& operator() (int row, int col) const;

private:

	uint8_t m_rows;
	uint8_t m_columns;
	uint8_t m_size;
	double* m_ptr_double;
};