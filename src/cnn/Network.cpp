#include "Network.h"
#include <iostream>


Network::Network() = default;

Network::~Network()
{
	m_Layers.clear();

	for (Matrix* m : m_inputTensor->get()) {
		delete m;
	}

	delete m_inputTensor;
}


void Network::init(TensorPtrs* inputTensor)
{
	m_inputTensor = inputTensor;
	m_currentLayerIndex = 0;
}

void Network::update()
{
	if (m_currentLayerIndex < m_Layers.size())
	{
		m_Layers[m_currentLayerIndex]->step();
		if (m_Layers[m_currentLayerIndex]->isDone())
			m_currentLayerIndex++;
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

