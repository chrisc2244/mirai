#pragma once
#include <vector>
#include "Matrix.h"


class Node
{

public:
	Node();
	Node(Matrix* weights, int bias);


	Matrix getWeights() const;
	void setBias(uint8_t bias);
	int getBias() const;
	void applyFilter(Matrix& currentWindow);

	void printProcessedResults();

private:

	Matrix m_filter;
	uint8_t m_bias;
	std::vector<double> m_processedResults;


};