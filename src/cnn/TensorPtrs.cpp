#include "TensorPtrs.h"

TensorPtrs::TensorPtrs(uint8_t size)
	: m_NumElements(size)
{
}

TensorPtrs::TensorPtrs(Matrix* m)
	: m_NumElements(1)
{
	m_Matrices.push_back(m);
}

void TensorPtrs::addElement(Matrix* m)
{
	m_Matrices.push_back(m);
}

void TensorPtrs::setElement(uint8_t index, Matrix* m)
{
	m_Matrices[index] = m;
}
