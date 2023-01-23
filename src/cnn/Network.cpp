#include "Network.h"
#include <iostream>
#include "../utils/Log.h"

Network::Network()
	: m_isDone(false), m_Started(false), m_batchSize(0), m_currentLayerIndex(0), m_inputTensor(nullptr)
{
}

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
	if (!m_Started && m_currentLayerIndex == 0)
	{
		MIR::Log::writefInfo("Network::update()", "Layer \'%s\' started processing...", m_Layers[m_currentLayerIndex]->getId());
		m_Started = true;
	}
	if (m_currentLayerIndex < m_Layers.size())
	{
		m_Layers[m_currentLayerIndex]->step();
		if (m_Layers[m_currentLayerIndex]->isDone())
		{
			m_currentLayerIndex++;
			if (m_currentLayerIndex < m_Layers.size())
			{
				MIR::Log::writefInfo("Network::update()", "Layer \'%s\' started processing...", m_Layers[m_currentLayerIndex]->getId());
			}
		}
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

