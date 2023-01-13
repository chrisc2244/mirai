#include "Node.h"
#include <iostream>
#include "Matrix.h"



Node::Node()
	: m_filter(nullptr), m_bias(0)
{
}

Node::Node(Matrix* weights, int bias)
{
	m_filter = weights;
	m_bias = 0;

}

Node::~Node()
{
	delete m_filter;
}

Matrix* Node::getWeights() const
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
	double valueOfFilterAtCurrentWindow = currentWindow.mutliplyMatricesIndexByIndexThenDivideBySize(*m_filter);
	m_processedResult = valueOfFilterAtCurrentWindow;
	m_processedResults.push_back(valueOfFilterAtCurrentWindow);
}

void Node::setFilter(Matrix* weights)
{
	m_filter = weights;
}

void Node::printProcessedResults()
{
	for (int i = 0; i < m_processedResults.size(); i++)
	{
		std::cout << m_processedResults.at(i) << std::endl;
	}
}

void Node::printProcessedResultsSize()
{
	std::cout << m_processedResults.size() << std::endl;
}

void Node::setProcessedResult(double processedResult)
{
	m_processedResult = processedResult;
}

double Node::getProcessedResult()
{
	return m_processedResult;
}
