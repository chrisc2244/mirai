#include "Layer.h"

layer::layer() = default;

layer::layer(const uint8_t number_of_nodes, const std::vector<node>& nodes)
{
	m_number_of_nodes_in_layer = number_of_nodes;
	m_nodes = nodes;
}


void layer::forward_propagate() 
{

}

void layer::backward_propagate()
{
	
}

void layer::apply_activation_function()
{
	
}

std::vector<std::vector<float>> layer::get_full_layer_output()
{
	return m_full_layer_output;
}

std::vector<std::vector<float>> layer::get_full_layer_input()
{
	return m_full_layer_input;
}
