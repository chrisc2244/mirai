#include "Node.h"

node::node() : m_weights(0), m_ptrToInputDoubleArray(nullptr), m_ptrToOutputDoubleArray(nullptr), m_bias(0) {}

node::node(const std::vector<double>& weights, double* inputDoubleArray)
{
	m_weights = weights;
	m_ptrToInputDoubleArray = inputDoubleArray;
	m_ptrToOutputDoubleArray = nullptr;
	m_bias = 0;
}

std::vector<double> node::getWeights() const
{
	return m_weights;
}

double* node::getPtrToInputDoubleArray() const
{
	return m_ptrToInputDoubleArray;
}

void node::setPtrToOutputDoubleArray(double* ptrToOutputDoubleArray)
{
	m_ptrToOutputDoubleArray = ptrToOutputDoubleArray;
}

double* node::getPtrToOutputDoubleArray() const
{
	return m_ptrToOutputDoubleArray;
}

void node::setBias(const uint8_t bias)
{
	m_bias = bias;
}

uint8_t node::getBias() const
{
	return m_bias;
}
