#pragma once
#include <vector>	
#include "Matrix.h"

class TensorPtrs
{
public:
	TensorPtrs();
	TensorPtrs(uint8_t size);
	// Constructs a 1 element tensor containing the matrix
	TensorPtrs(Matrix* m);
	void addElement(Matrix* m);
	void setElement(uint8_t index, Matrix* m);
	inline Matrix* getElement(uint8_t index) { return m_Matrices[index]; }
	const inline uint8_t size() const { return m_NumElements; }

	inline std::vector<Matrix*> get() { return m_Matrices; }

	Matrix* operator[](uint8_t index) const;
private:
	std::vector<Matrix*> m_Matrices;
	uint8_t m_NumElements;
};