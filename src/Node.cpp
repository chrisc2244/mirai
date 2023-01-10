#include "Node.h"

Node::Node() : m_weights(), m_inputGreyscaleValues(), m_bias(0) {}

Node::Node(Matrix& weights, const std::vector<double>& inputGreyscaleValues)
{
	Matrix m_weights = weights;
	m_weights = weights;
	m_inputGreyscaleValues = inputGreyscaleValues;
	m_bias = 0;
}

Matrix Node::getWeights() const
{
	return m_weights;
}


void Node::setBias(const uint8_t bias)
{
	m_bias = bias;
}

uint8_t Node::getBias() const
{
	return m_bias;
}

void Node::applyFilterToInputVector()
{

}
