#include "Node.h"
#include <iostream>
#include "Matrix.h"



Node::Node()
{
}

Node::Node(Matrix* weights, int bias)
{
	m_filter = *weights;
	m_bias = 0;
}

Matrix Node::getWeights() const
{
	return m_filter;
}


void Node::setBias(const uint8_t bias)
{
	m_bias = bias;
}

int Node::getBias() const
{
	return m_bias;
}

void Node::applyFilter(Matrix& currentWindow)
{
	double valueOfFilterAtCurrentWindow = currentWindow.mutliplyMatricesIndexByIndexThenDivideBySize(m_filter);
	m_processedResults.push_back(valueOfFilterAtCurrentWindow);
}

void Node::printProcessedResults()
{
	for (int i = 0; i < m_processedResults.size(); i++)
	{
		std::cout << m_processedResults.at(i) << std::endl;
	}
}
