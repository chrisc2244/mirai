#pragma once
#include <vector>	
#include "Matrix.h"

class Tensor
{
public:
	Tensor(uint8_t size);
	void addElement(const Matrix& m);
	void setElement(uint8_t index, const Matrix& m);
	inline Matrix* getElement(uint8_t index) { return &m_Matrices[index]; }
private:
	std::vector<Matrix> m_Matrices;
	uint8_t m_NumElements;
};