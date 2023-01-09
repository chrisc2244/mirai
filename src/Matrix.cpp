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

void matrix::print(const matrix& matrix_to_print)
{
	for (int i = 0; i < matrix_to_print.m_size; i++)
	{
		std::cout << "[" << matrix_to_print[i] << "]";
		if ((i + 1) % matrix_to_print.m_columns == 0)
		{
			std::cout << std::endl;
		}
	}
}

matrix matrix::operator+ (const matrix& other_matrix) const
{	
	if (other_matrix.m_size == this->m_size && other_matrix.m_columns == this->m_columns && other_matrix.m_rows == this->m_rows)
	{	
		auto* ptrToReturn = new double[m_size];

		for (int i = 0; i < other_matrix.m_size; i++)
		{
			ptrToReturn[i] = other_matrix[i] + (*this)[i];
		}

		matrix matrix_to_return(other_matrix.m_rows, other_matrix.m_columns, ptrToReturn);
		return matrix_to_return;
	}
		std::cout << "Left Matrix size: " << this->m_size << " Right matrix size: " << other_matrix.m_size << std::endl;
		throw std::invalid_argument("Cannot add matrices of different sizes.");
}

matrix matrix::operator-(const matrix& other_matrix) const
{
	if (other_matrix.m_size == this->m_size && other_matrix.m_columns == this->m_columns && other_matrix.m_rows == this->m_rows)
	{
		auto* ptrToReturn = new double[m_size];

		for (int i = 0; i < other_matrix.m_size; i++)
		{
			ptrToReturn[i] = other_matrix[i] - (*this)[i];
		}

		matrix matrix_to_return(other_matrix.m_rows, other_matrix.m_columns, ptrToReturn);
		return matrix_to_return;
	}
	std::cout << "Left Matrix size: " << this->m_size << " Right matrix size: " << other_matrix.m_size << std::endl;
	throw std::invalid_argument("Cannot subtract matrices of different sizes.");
}

//TODO: Finish operator* 
matrix matrix::operator*(const matrix& other_matrix) const
{	
	if (this->m_columns == other_matrix.m_rows) 
	{
		const uint8_t rows_of_new_matrix = this->m_rows;
		const uint8_t columns_of_new_matrix = m_columns;
		const uint8_t new_matrix_size = rows_of_new_matrix * columns_of_new_matrix;

		for (int i = 0; i < new_matrix_size; i++) 
		{

		}

		//fill this matrix out with right constructor
		matrix matrix_to_return;
		return matrix_to_return;
	}
	std::cout << "Left matrix columns: " << this->m_columns << "Right matrix rows: " << other_matrix.m_rows;
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
		int row_of_element = row;
		int col_of_element = col;
		std::cout << "row: " << row << " col: " << col << std::endl;
		return m_ptr_double[row_of_element * m_columns + col_of_element];
	}
	std::cout << "row: " << row << " col: " << col << std::endl;
	throw std::out_of_range("Invalid matrix index");
}

