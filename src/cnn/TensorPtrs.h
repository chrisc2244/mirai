#pragma once
#include <vector>	
#include "Matrix.h"

class TensorPtrs
{
public:
	TensorPtrs();
	TensorPtrs(uint8_t size);
	TensorPtrs(uint8_t size, uint16_t matrixRows, uint16_t matrixCols);
	// Constructs a 1 element tensor containing the matrix
	TensorPtrs(Matrix* m);
	void addElement(Matrix* m);
	void setElement(uint8_t index, Matrix* m);
	void setMatrixSize(uint16_t matrixRows, uint16_t matrixCols);
	void resetSize(uint8_t size);


	inline Matrix* getElement(uint8_t index) { return m_Matrices[index]; }
	inline const uint8_t size() const { return m_NumElements; }
	inline std::vector<Matrix*> get() { return m_Matrices; }
	inline const uint16_t getMatrixRows() const { return m_MatrixRows; }
	inline const uint16_t getMatrixColumns() const { return m_MatrixCols; }

	Matrix* operator[](uint8_t index) const;
private:
	std::vector<Matrix*> m_Matrices;
	uint8_t m_NumElements;

	uint16_t m_MatrixRows;
	uint16_t m_MatrixCols;
};