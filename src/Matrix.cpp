#include "Matrix.h"
#include "ImageWrapper.h"


//constructors
matrix::matrix() : m_rows(0), m_columns(0), m_input_pixel_vector(0) {}

matrix::matrix(const uint8_t rows, const uint8_t columns, const std::vector<pixel>& pixels)
{
	m_rows = rows;
	m_columns = columns;
	m_input_pixel_vector = pixels;

	pixel* this_matrix = new pixel[rows * columns];


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
	delete[](this_matrix);
}


//operations
uint8_t matrix::get_row_amount() const
{
	return m_rows;
}

uint8_t matrix::get_column_amount() const
{
	return m_columns;
}

std::vector<pixel> matrix::get_column_at(uint8_t row, uint8_t column)
{
	//TODO: add logic here for returning column at specific index of matrix
	return std::vector<pixel>();
}

std::vector<pixel> matrix::get_row_at(uint8_t row, uint8_t column)
{
	//TODO: add logic here for returning row at specific index of matrix
	return std::vector<pixel>();
}



//operators
matrix matrix::operator+ (const matrix& other_matrix)
{
	//TODO: the actual thing
	return matrix();
}

matrix matrix::operator-(const matrix& other_matrix)
{
	//TODO: the actual thing
	return matrix();
}

matrix matrix::operator*(const matrix& other_matrix)
{
	//TODO: the actual thing
	return matrix();
}