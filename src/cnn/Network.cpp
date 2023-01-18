#include "Network.h"



Network::Network() = default;

Network::~Network()
{
	delete m_inputData;
}


void Network::init(Matrix* inputMatrix)
{
	//layer 1 gets the input data, later layers get the previous layer's output data
	m_inputData = inputMatrix;
}

void Network::update()
{
	for (std::unique_ptr<Layer>& l : m_Layers)
	{
		if(!l->isDone())
			l->step();
	}
}

void Network::addLayer(std::unique_ptr<Layer> layer)
{
	m_Layers.push_back(std::move(layer));
}

//void Network::addLayer(Layer* l)
//{
//	m_Layers.emplace_back(l);
//}

Matrix& Network::getInputData()
{
	return *m_inputData;
}

