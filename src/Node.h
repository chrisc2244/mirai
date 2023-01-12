#pragma once
#include <vector>
#include "Matrix.h"


class Node
{

public:
	Node();
	Node(Matrix& weights, int bias);


	Matrix getWeights() const;
	void setBias(uint8_t bias);
	int getBias() const;
	void applyFilter(Matrix& currentWindow);
	void setFilter(Matrix& weights);
	void printProcessedResults();


	void setProcessedResult(double processedResult);
	double getProcessedResult();

private:

	Matrix m_filter;
	uint8_t m_bias;
	std::vector<double> m_processedResults;
	double m_processedResult;


};