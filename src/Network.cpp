#include "Network.h"
#include "Layer.h"



Network::Network() = default;

Network::~Network()
{
	delete m_inputData;
}


void Network::init(Matrix* inputMatrix)
{
	//layer 1 gets the input data, later layers get the previous layer's output data
	m_inputData = inputMatrix;
	m_Layer1.init(m_inputData,4, 4);
}

void Network::update()
{
	m_Layer1.step();
}

Matrix& Network::getInputData()
{
	return *m_inputData;
}

