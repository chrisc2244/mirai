#pragma once
#include <vector>
#include <string>
#include <stdexcept>
class Matrix
{

public:

	//constructors
	Matrix();

	//takes in rows, columns, and double vector obtianed from convertPixelVectorToGreyscaleVector() method
	Matrix(const uint16_t rows, const uint16_t columns, const std::vector<double> &values);

	Matrix(const uint16_t rows, const uint16_t columns, double* arrPtr);

	// Constructs a matrix of columns x rows size, and initializes every value to default_value param
	Matrix(const uint16_t rows, const uint16_t columns, double default_value = 0);

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

	/**
	* Places a submatrix of the CALLING object into the destination matrix, note that destination matrix
	* must have a width and height in columns for this function to work.
	*
	* @param startcol - The column (x index) of the first element to put in the submatrix
	* @param startrow - The row (y index) of the first element to put in the submatrix
	* @param destination - A reference to an intialized matrix in which the put the submatrix
	*
	* @throws out_of_bounds exceptions if startcol, startrow, or that index + destination columns and rows is out of bounds.
	*/
	void putSubMatrix(uint16_t startcol, uint16_t startrow, Matrix& destination);

private:

	uint16_t m_rows;
	uint16_t m_columns;
	uint16_t m_size;
	double* m_ptr_double;
};