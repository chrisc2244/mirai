#include "Matrix.h"
#include <iostream>


//should probably convert this to a template
Matrix::Matrix() : m_rows(0), m_columns(0),m_size(0), m_ptr_double(nullptr) {}

Matrix::Matrix(const uint16_t rows, const uint16_t columns, const std::vector<double> &values)
{
	m_rows = rows;
	m_columns = columns;
	m_size = rows * columns;
	
	auto* this_Matrix = new double[m_size];
	m_ptr_double = this_Matrix;

	for (uint16_t r = 0; r < rows; r++)
	{
		for (uint16_t c = 0; c < columns; c++)
		{
			this_Matrix[c + r * columns] = values.at(c + r * columns);
		}
	}
}

Matrix::Matrix(const uint16_t rows, const uint16_t columns, double* arrPtr)
{
	m_rows = rows;
	m_columns = columns;
	m_size = rows * columns;
	m_ptr_double = arrPtr;
}

Matrix::Matrix(const uint16_t rows, const uint16_t columns, double default_value)
{
	m_rows = rows;
	m_columns = columns;
	m_size = rows * columns;

	auto* this_Matrix = new double[m_size];
	m_ptr_double = this_Matrix;

	for (uint16_t r = 0; r < rows; r++)
	{
		for (uint16_t c = 0; c < columns; c++)
		{
			this_Matrix[c + r * columns] = default_value;
		}
	}
}


Matrix::~Matrix()
{
	delete[] m_ptr_double;
}

uint16_t Matrix::getRowAmount() const
{
	return m_rows;
}

uint16_t Matrix::getColumnAmount() const
{
	return m_columns;
}

uint16_t Matrix::getSize() const
{
	return m_size;
}

void Matrix::print(const Matrix& MatrixToPrint)
{
	for (int i = 0; i < MatrixToPrint.m_size; i++)
	{
		std::cout << "[" << MatrixToPrint[i] << "]";
		if ((i + 1) % MatrixToPrint.m_columns == 0)
		{
			std::cout << std::endl;
		}
	}
}

std::string Matrix::toString(const Matrix& MatrixToPrint)
{
	std::string str = "";

	for (int i = 0; i < MatrixToPrint.m_size; i++)
	{
		str.append("[");
		str.append(std::to_string(MatrixToPrint[i]));
		str.append("]");
		if ((i + 1) % MatrixToPrint.m_columns == 0)
		{
			str.append("\n");
		}
	}
	return str;
}

Matrix Matrix::operator+ (const Matrix& otherMatrix) const
{	
	if (otherMatrix.m_size == this->m_size && otherMatrix.m_columns == this->m_columns && otherMatrix.m_rows == this->m_rows)
	{	
		auto* ptrToReturn = new double[m_size];

		for (int i = 0; i < otherMatrix.m_size; i++)
		{
			ptrToReturn[i] = otherMatrix[i] + (*this)[i];
		}

		Matrix matrix_to_return(otherMatrix.m_rows, otherMatrix.m_columns, ptrToReturn);
		return matrix_to_return;
	}
		throw std::invalid_argument("Cannot add matrices of different sizes.");
}

Matrix Matrix::operator-(const Matrix& otherMatrix) const
{
	if (otherMatrix.m_size == this->m_size && otherMatrix.m_columns == this->m_columns && otherMatrix.m_rows == this->m_rows)
	{
		auto* ptrToReturn = new double[m_size];

		for (int i = 0; i < otherMatrix.m_size; i++)
		{
			ptrToReturn[i] = otherMatrix[i] - (*this)[i];
		}

		Matrix matrix_to_return(otherMatrix.m_rows, otherMatrix.m_columns, ptrToReturn);
		return matrix_to_return;
	}
	throw std::invalid_argument("Cannot subtract matrices of different sizes.");
}

Matrix Matrix::operator*(const Matrix& otherMatrix) const
{
	if (this->m_columns == otherMatrix.m_rows)
	{
		const uint16_t rowsOfNewMatrix = this->m_rows;
		const uint16_t columnsOfNewMatrix = otherMatrix.m_columns;
		const uint16_t newMatrixSize = rowsOfNewMatrix * columnsOfNewMatrix;
		auto* ptrToReturn = new double[newMatrixSize];
		Matrix MatrixToReturn(rowsOfNewMatrix, columnsOfNewMatrix, ptrToReturn);

		for (int i = 0; i < this->m_rows; i++)
		{
			for (int j = 0; j < otherMatrix.m_columns; j++)
			{
				double x = 0;
				for (int k = 0; k < this->m_columns; k++)
				{
					x += this->operator()(i, k) * otherMatrix(k, j);
				}
				MatrixToReturn(i, j) = x;
			}
		}
		return MatrixToReturn;
	}
	throw std::invalid_argument("Columns of left Matrix must = rows of right Matrix.");
}

void Matrix::operator=(const Matrix& otherMatrix)
{
	this->m_columns = otherMatrix.m_columns;
	this->m_rows = otherMatrix.m_rows;
	this->m_size = otherMatrix.m_size;
	delete[] this->m_ptr_double;
	this->m_ptr_double = new double[this->m_size];
	for (int i = 0; i < this->m_rows; i++)
	{
		for (int j = 0; j < otherMatrix.m_columns; j++)
		{
			m_ptr_double[i * this->m_columns + j] = otherMatrix(i,j);
		}
	}	
}

double& Matrix::operator[](const uint16_t index) const
{
	
	if (index >= m_size || index < 0)
	{
		throw std::invalid_argument("Matrix index out of bounds");
	}
	return m_ptr_double[index];
}

double& Matrix::operator() (const uint16_t row, const uint16_t col) const
{
	if (row >= 0 && col >= 0 && col <= m_columns && row <= m_rows)
	{
		uint16_t rowOfElement = row;
		uint16_t colOfElement = col;
		return m_ptr_double[rowOfElement * m_columns + colOfElement];
	}
	throw std::out_of_range("Invalid Matrix index");
}

void Matrix::putSubMatrix(uint16_t startcol, uint16_t startrow, Matrix& destination)
{

	// Do error checking here to make sure that indexes are in range with width and height
	if (startcol + destination.getColumnAmount() > m_columns ||
		startrow + destination.getRowAmount() > m_rows)
	{
		throw std::out_of_range("Invalid Matrix index or size");
	}
	for (uint16_t r = startrow; r < startrow + destination.getRowAmount(); r++) {
		for (uint16_t c = startcol; c < startcol + destination.getColumnAmount(); c++) {
			destination(r-startrow, c-startcol) = (*this)(r, c);
		}
	}
}

