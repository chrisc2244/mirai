#include "TensorPtrs.h"
#include "../utils/Log.h"

TensorPtrs::TensorPtrs()
	: m_NumElements(0), m_MatrixRows(0), m_MatrixCols(0)
{
}

TensorPtrs::TensorPtrs(uint8_t size)
	: m_NumElements(size), m_MatrixRows(0), m_MatrixCols(0)
{
}

TensorPtrs::TensorPtrs(uint8_t size, uint16_t matrixRows, uint16_t matrixCols)
	: m_NumElements(size), m_MatrixRows(matrixRows), m_MatrixCols(matrixCols)
{
}

TensorPtrs::TensorPtrs(Matrix* m)
	: m_NumElements(1), m_MatrixRows(0), m_MatrixCols(0)
{
	// Update the fields
	m_MatrixCols = m->getColumnAmount();
	m_MatrixRows = m->getRowAmount();
	m_Matrices.push_back(m);
}

void TensorPtrs::addElement(Matrix* m)
{
	if (m->getColumnAmount() != m_MatrixCols || m->getRowAmount() != m_MatrixRows)
	{
		// Update the fields
		m_MatrixCols = m->getColumnAmount();
		m_MatrixRows = m->getRowAmount();
		MIR::Log::writeWarn("TensorPtrs->addElement()", "Adding a new matrix of different dimensions. May produce unexpected results.");
	}
	m_Matrices.push_back(m);
	m_NumElements++;
}

void TensorPtrs::setElement(uint8_t index, Matrix* m)
{
	m_Matrices[index] = m;
}

void TensorPtrs::setMatrixSize(uint16_t matrixRows, uint16_t matrixCols)
{
	m_MatrixCols = matrixCols;
	m_MatrixRows = matrixRows;
}

void TensorPtrs::resetSize(uint8_t size)
{
	m_NumElements = size;
}

Matrix* TensorPtrs::operator[](uint8_t index) const
{
	return m_Matrices[index];
}
