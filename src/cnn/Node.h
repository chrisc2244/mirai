#pragma once
#include <vector>
#include "Matrix.h"


class Node
{

public:
	Node();
	Node(Matrix* filter, int bias);
	Node(Matrix* filter);

	// Node takes ownership of it's filter, deletes the memory here
	~Node();


	Matrix* getWeights() const;
	void setBias(uint8_t bias);
	const inline int getBias() const { return m_bias; }
	void applyFilter(Matrix& currentWindow);
	void setFilter(Matrix* weights);
	void printProcessedResults();


	void setProcessedResult(double processedResult);
	double getProcessedResult();

private:

	Matrix* m_filter; // Put this on the heap, give ownership to node
	uint8_t m_bias;
	std::vector<double> m_processedResults;
	double m_processedResult;
};