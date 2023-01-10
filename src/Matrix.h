#pragma once
#include <vector>
#include <string>

class Matrix
{

public:

	//constructors
	Matrix();

	//takes in rows, columns, and double vector obtianed from convertPixelVectorToGreyscaleVector() method
	Matrix(const uint16_t rows, const uint16_t columns, const std::vector<double> &values);

	Matrix(const uint16_t rows, const uint16_t columns, double* arrPtr);

	~Matrix();

	//operations
	//returns m_rows
	uint16_t getRowAmount() const;

	//returns m_columns
	uint16_t getColumnAmount() const;

	//returns size of Matrix
	uint16_t getSize() const;

	//prints values in Matrix		[0.4213][0.4213][0.4213]
	//3x3 example, 6 values total	[0.4213][0.4213][0.4213]
	static void print(const Matrix& MatrixToPrint);
	
	static std::string toString(const Matrix& MatrixToPrint);

	//operators
	Matrix operator+(const Matrix& otherMatrix) const;

	Matrix operator-(const Matrix& otherMatrix) const;

	//dot product
	Matrix operator*(const Matrix& otherMatrix) const;

	void operator=(const Matrix& otherMatrix);

	//access element in Matrix[index]
	double& operator[](uint16_t index) const;

	//access element in Matrix in (row, col) form starting at (0,0) for first element
	double& operator() (uint16_t row, uint16_t col) const;

	

private:

	uint16_t m_rows;
	uint16_t m_columns;
	uint16_t m_size;
	double* m_ptr_double;
};