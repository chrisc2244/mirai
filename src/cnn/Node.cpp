#include "Node.h"
#include <iostream>
#include "Matrix.h"



Node::Node()
	: m_filter(nullptr), m_bias(0), m_processedResult(0), m_output(nullptr)
{
}

Node::Node(Matrix* filter, int bias = 0)
	: m_processedResult(0), m_output(nullptr)
{
	m_filter = filter;
	m_bias = bias;
}

Node::Node(Matrix* filter) 
	: m_bias(0), m_processedResult(0), m_output(nullptr)
{
	m_filter = filter;
}

Node::~Node()
{
	delete m_filter;
	delete m_output;
}

Matrix* Node::getWeights() const
{
	return m_filter;
}


void Node::setBias(const uint8_t bias)
{
	m_bias = bias;
}

void Node::applyFilter(Matrix& currentWindow)
{
	/*
	std::cout << "testing currentWindow line 38 Node.cpp: " << std::endl;
	Matrix::print(currentWindow);
	std::cout << std::endl;

	std::cout << "testing m_filter line 42 Node.cpp: " << std::endl;
	Matrix::print(m_filter);
	std::cout << std::endl;
	*/

	double valueOfFilterAtCurrentWindow = currentWindow.mutliplyMatricesIndexByIndexThenDivideBySize(*m_filter);
	m_processedResult = valueOfFilterAtCurrentWindow;

	//std::cout << "testing valueOfFilterAtCurrentWindow: Line 49 Node.cpp: " << valueOfFilterAtCurrentWindow << std::endl;
	m_processedResults.push_back(valueOfFilterAtCurrentWindow);
}

void Node::applyFilter(Matrix& currentWindow, uint16_t column, uint16_t row)
{
	double valueOfFilterAtCurrentWindow = currentWindow.mutliplyMatricesIndexByIndexThenDivideBySize(*m_filter);
	m_processedResult = valueOfFilterAtCurrentWindow;

	(*m_output)(column, row) = m_processedResult;
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

void Node::setProcessedResult(double processedResult)
{
	m_processedResult = processedResult;
}

double Node::getProcessedResult()
{
	return m_processedResult;
}
