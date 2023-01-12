#pragma once
#include <vector>
#include <string>
#include <stdexcept>
class Matrix
{

public:

	//constructors
	Matrix();

	/**
	* Creates a matrix of columns x rows size, and populates it with values from a vector
	*
	* @param rows - The row amount (height) of the matrix
	* @param columns - The column amount (width) of the matrix
	* @param values -  Reference to a vector containing the values to populate the matrix with
	*/
	Matrix(const uint16_t rows, const uint16_t columns, const std::vector<double> &values);

	/**
	* Creates a matrix of columns x rows size, and populates it with values from a vector
	*
	* @param rows - The row amount (height) of the matrix
	* @param columns - The column amount (width) of the matrix
	* @param arrPtr -  Pointer to a heap allocated array of doubles for the matrix to use
	*/
	Matrix(const uint16_t rows, const uint16_t columns, double* arrPtr);

	/**
	* Creates a matrix of columns x rows size, and populates it with default_value
	*
	* @param rows - The row amount (height) of the matrix
	* @param columns - The column amount (width) of the matrix
	* @param default_value - Value to place in every element of the matrix
	*/
	Matrix(const uint16_t rows, const uint16_t columns, double default_value = 0);

	~Matrix();

	/**
	* Places a submatrix of the CALLING object into the destination matrix, note that destination matrix
	* must have a width and height in columns and rows for this function to work.
	*
	* @param startcol - The column (x index) of the first element to put in the submatrix
	* @param startrow - The row (y index) of the first element to put in the submatrix
	* @param destination - A reference to an intialized matrix in which the put the submatrix
	*
	* @throws out_of_bounds exceptions if startcol, startrow, or that index + destination columns and rows is out of bounds.
	*/
	void putSubMatrix(uint16_t startcol, uint16_t startrow, Matrix& destination);

	// Returns number of rows (height)
	inline uint16_t getRowAmount() const { return m_rows; }

	// Returns number of columns (width)
	inline uint16_t getColumnAmount() const { return m_columns;  }

	// Returns the size of the matrix in elements (columns * rows)
	inline uint16_t getSize() const { return m_size; }

	//prints values in Matrix		[0.4213][0.4213][0.4213]
	//3x3 example, 6 values total	[0.4213][0.4213][0.4213]
	static void print(const Matrix& MatrixToPrint);
	
	/**
	* Generates a string that represents the matrix and its elements
	*
	* @param matrix - A reference to the matrix you want a string representation of
	*/
	static std::string toString(const Matrix& matrix);

	//operators
	Matrix operator+(const Matrix& otherMatrix) const;
	Matrix operator-(const Matrix& otherMatrix) const;
	Matrix operator*(const Matrix& otherMatrix) const;				// Dot Product
	void operator=(const Matrix& otherMatrix);						
	double& operator[](uint16_t index) const;						// Access element in Matrix[index]
	double& operator() (uint16_t row, uint16_t col) const;			// Access element in Matrix in (row, col) form (y, x) starting at (0,0) for first element

private:

	uint16_t m_rows;
	uint16_t m_columns;
	uint16_t m_size;
	double* m_ptr_double;
};