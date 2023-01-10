#pragma once
#include <vector>

class node
{

public:

	node();
	node(const std::vector<double>& weights, double* ptrToInputDoubleArray);

	std::vector<double> getWeights() const;
	double* getPtrToInputDoubleArray() const;
	void setPtrToOutputDoubleArray(double* ptrToOutputDoubleArray);
	double* getPtrToOutputDoubleArray() const;
	void setBias(uint8_t bias);
	uint8_t getBias() const;


private:

	std::vector<double> m_weights;
	double* m_ptrToInputDoubleArray;
	double* m_ptrToOutputDoubleArray;
	uint8_t m_bias;


};