#include "Matrix.h"
#include <iostream>


//should probably convert this to a template
matrix::matrix() : m_rows(0), m_columns(0),m_size(0), m_ptr_double(nullptr) {}

matrix::matrix(const uint8_t rows, const uint8_t columns, const std::vector<double> &values)
{
	m_rows = rows;
	m_columns = columns;
	m_size = rows * columns;
	
	auto* this_matrix = new double[m_size];
	m_ptr_double = this_matrix;

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			this_matrix[c + r * columns] = values.at(c + r * columns);
		}
	}
}

matrix::matrix(const uint8_t rows, const uint8_t columns, double* arrPtr)
{
	m_rows = rows;
	m_columns = columns;
	m_size = rows * columns;
	m_ptr_double = arrPtr;
}

uint8_t matrix::getRowAmount() const
{
	return m_rows;
}

uint8_t matrix::getColumnAmount() const
{
	return m_columns;
}

uint8_t matrix::getSize() const
{
	return m_size;
}

void matrix::print(const matrix& matrixToPrint)
{
	for (int i = 0; i < matrixToPrint.m_size; i++)
	{
		std::cout << "[" << matrixToPrint[i] << "]";
		if ((i + 1) % matrixToPrint.m_columns == 0)
		{
			std::cout << std::endl;
		}
	}
}

matrix matrix::operator+ (const matrix& otherMatrix) const
{	
	if (otherMatrix.m_size == this->m_size && otherMatrix.m_columns == this->m_columns && otherMatrix.m_rows == this->m_rows)
	{	
		auto* ptrToReturn = new double[m_size];

		for (int i = 0; i < otherMatrix.m_size; i++)
		{
			ptrToReturn[i] = otherMatrix[i] + (*this)[i];
		}

		matrix matrix_to_return(otherMatrix.m_rows, otherMatrix.m_columns, ptrToReturn);
		return matrix_to_return;
	}
		std::cout << "Left Matrix size: " << this->m_size << " Right matrix size: " << otherMatrix.m_size << std::endl;
		throw std::invalid_argument("Cannot add matrices of different sizes.");
}

matrix matrix::operator-(const matrix& otherMatrix) const
{
	if (otherMatrix.m_size == this->m_size && otherMatrix.m_columns == this->m_columns && otherMatrix.m_rows == this->m_rows)
	{
		auto* ptrToReturn = new double[m_size];

		for (int i = 0; i < otherMatrix.m_size; i++)
		{
			ptrToReturn[i] = otherMatrix[i] - (*this)[i];
		}

		matrix matrix_to_return(otherMatrix.m_rows, otherMatrix.m_columns, ptrToReturn);
		return matrix_to_return;
	}
	std::cout << "Left Matrix size: " << this->m_size << " Right matrix size: " << otherMatrix.m_size << std::endl;
	throw std::invalid_argument("Cannot subtract matrices of different sizes.");
}

matrix matrix::operator*(const matrix& otherMatrix) const
{
	if (this->m_columns == otherMatrix.m_rows)
	{
		const uint8_t rowsOfNewMatrix = this->m_rows;
		const uint8_t columnsOfNewMatrix = otherMatrix.m_columns;
		const uint8_t newMatrixSize = rowsOfNewMatrix * columnsOfNewMatrix;
		auto* ptrToReturn = new double[newMatrixSize];
		matrix matrixToReturn(rowsOfNewMatrix, columnsOfNewMatrix, ptrToReturn);

		for (int i = 0; i < this->m_rows; i++)
		{
			for (int j = 0; j < otherMatrix.m_columns; j++)
			{
				double x = 0;
				for (int k = 0; k < this->m_columns; k++)
				{
					x += this->operator()(i, k) * otherMatrix(k, j);
				}
				matrixToReturn(i, j) = x;
			}
		}
		return matrix(rowsOfNewMatrix, columnsOfNewMatrix, ptrToReturn);
	}
	std::cout << "Left matrix columns: " << +this->m_columns << "Right matrix rows: " << +otherMatrix.m_rows;
	throw std::invalid_argument("Columns of left matrix must = rows of right matrix.");
}

double& matrix::operator[](const int index) const
{
	
	if (index >= m_size || index < 0)
	{
		std::cout << "Matrix index: [" << index << "] is out of bounds. Size of matrix: " << m_size << std::endl;
		throw std::invalid_argument("");
	}
	return m_ptr_double[index];
}

double& matrix::operator() (const int row, const int col) const
{
	if (row >= 0 && col >= 0 && col <= m_columns && row <= m_rows)
	{
		int rowOfElement = row;
		int colOfElement = col;
		return m_ptr_double[rowOfElement * m_columns + colOfElement];
	}
	std::cout << "row: " << row << " col: " << col << std::endl;
	throw std::out_of_range("Invalid matrix index");
}

