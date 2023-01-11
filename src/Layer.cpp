#include "Layer.h"

Layer::Layer() = default;

Layer::Layer(const uint8_t numberOfNodes, const std::vector<Node>& nodes)
{
	m_number_of_nodes_in_layer = numberOfNodes;
	m_nodes = nodes;
}


void Layer::forwardPropagate() 
{

}

void Layer::backwardPropagate()
{
	
}

void Layer::applyActivationFunction()
{
	
}

std::vector<std::vector<float>> Layer::getFullLayerOutput()
{
	return m_full_layer_output;
}

std::vector<std::vector<float>> Layer::getFullLayerInput()
{
	return m_full_layer_input;
}

void Layer::slideWindowThroughInputMatrix()
{

}
