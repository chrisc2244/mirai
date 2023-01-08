#include "Matrix.h"
#include "ImageWrapper.h"


//should probably convert this to a template

matrix::matrix() : size(0), p_columns(0), p_rows(0), m_rows(0), m_columns(0), m_input_pixel_vector(0),
m_size(0), m_ptr_double(nullptr) {}

matrix::matrix(const uint8_t rows, const uint8_t columns, const std::vector<double> &greyscalevalues)
{
	m_rows = rows;
	m_columns = columns;
	m_size = rows * columns;
	size = m_size;
	p_columns = m_columns;
	p_rows = m_rows;
	m_greyscale_values = greyscalevalues;
	
	double* this_matrix = new double[m_size];
	m_ptr_double = this_matrix;

	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			this_matrix[c + r * columns] = greyscalevalues.at(c + r * columns);
		}
	}
}

/*
//pixel vector version 
matrix::matrix(const uint8_t rows, const uint8_t columns, const std::vector<pixel>& pixels)
{
	m_rows = rows;
	m_columns = columns;
	m_input_pixel_vector = pixels;
	m_size = rows * columns;

	pixel* this_matrix = new pixel[m_size];
	m_ptr_pixel = this_matrix;

	//fills matrix with [rows * columns] pixels, not a 2d array, still a regular 1d array.
	//every r (row) increment jumps column (the width) elements forward, equivalent to moving down a row.
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < columns; c++)
		{
			this_matrix[c + r * columns] = pixels.at(c + r * columns);
		}
	}

	//prints pixels in matrix,		[R, G, B, A] [R, G, B, A] [R, G, B, A] [R, G, B, A]
	//2x4 example, 8 pixels total	[R, G, B, A] [R, G, B, A] [R, G, B, A] [R, G, B, A]
	for (int i = 0; i < rows * columns; i++)
	{
		std::cout << this_matrix[i];
		if ((i + 1) % columns == 0)
		{
			std::cout << std::endl;
		}
	}
}
*/


uint8_t matrix::get_row_amount() const
{
	return m_rows;
}

uint8_t matrix::get_column_amount() const
{
	return m_columns;
}

void matrix::print(const matrix& matrix_to_print)
{
	for (int i = 0; i < matrix_to_print.size; i++)
	{
		std::cout << "[" << matrix_to_print[i] << "]";
		if ((i + 1) % matrix_to_print.p_columns == 0)
		{
			std::cout << std::endl;
		}
	}
}


//prints pixels in matrix,		[0.4213] [0.4213] [0.4213]			[0.4213] [0.4213] [0.4213] 
//2x4 example, 8 pixels total	[0.4213] [0.4213] [0.4213]			[0.4213] [0.4213] [0.4213]
matrix matrix::operator+ (const matrix& other_matrix) const
{	
	if (other_matrix.size == this->size && other_matrix.m_columns == this->m_columns && other_matrix.m_rows == this->m_rows)
	{	
		std::vector<double> new_values;

		for (int i = 0; i < other_matrix.size; i++)
		{
			double added_value = other_matrix[i] + (*this)[i];
			new_values.push_back(added_value);
		}

		matrix matrix_to_return(other_matrix.m_rows, other_matrix.m_columns, new_values);
		return matrix_to_return;

	}
		throw std::invalid_argument("Cannot add matrices of different sizes.");
}


matrix matrix::operator-(const matrix& other_matrix)
{
	if (other_matrix.size == this->size && other_matrix.m_columns == this->m_columns && other_matrix.m_rows == this->m_rows)
	{
		std::vector<double> new_values;

		for (int i = 0; i < other_matrix.size; i++)
		{
			double subtracted_value = (*this)[i] - other_matrix[i];
			new_values.push_back(subtracted_value);
		}

		matrix matrix_to_return(other_matrix.m_rows, other_matrix.m_columns, new_values);
		return matrix_to_return;

	}
	throw std::invalid_argument("Cannot subtract matrices of different sizes.");
}

matrix matrix::operator*(const matrix& other_matrix)
{
	//TODO: the actual thing



	return matrix();
}

//all this reference means is that the type at this address is *presumed* to be the type we give it.
//the pointer is still just an address to a specific byte.
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
	return m_ptr_double[col + row * col];
}

