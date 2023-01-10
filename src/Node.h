#pragma once
#include <vector>
#include "Matrix.h"


class Node
{

public:

	Node();
	Node(Matrix& weights, const std::vector<double>& inputGreyscaleValues);


	Matrix getWeights() const;
	void setBias(uint8_t bias);
	uint8_t getBias() const;
	void applyFilterToInputVector();


private:

	Matrix m_weights;
	std::vector<double> m_inputGreyscaleValues;
	uint8_t m_bias;



};