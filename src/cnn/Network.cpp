#include "Network.h"
#include <iostream>


Network::Network() = default;

Network::~Network()
{
	m_Layers.clear();
	delete m_inputData;
}


void Network::init(Matrix* inputMatrix)
{
	//layer 1 gets the input data, later layers get the previous layer's output data
	m_inputData = inputMatrix;
}

void Network::update()
{
	for (Layer* l : m_Layers)
	{
		if(!l->isDone())
			l->step();
	}
}

void Network::addLayer(Layer* layer)
{
	m_Layers.push_back(std::move(layer));
}

bool Network::isDone()
{
	m_isDone = true;
	for (Layer* l : m_Layers)
	{
		if (!l->isDone())
			m_isDone = false;
	}
	return m_isDone;
}

//void Network::addLayer(Layer* l)
//{
//	m_Layers.emplace_back(l);
//}

Matrix& Network::getInputData()
{
	return *m_inputData;
}

