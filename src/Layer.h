#pragma once
#include "Node.h"
#include <vector>

class layer

{

public:

	layer();
	layer(const uint8_t number_of_nodes, const std::vector<Node>& nodes);

	static void forward_propagate();
	static void backward_propagate();
	static void apply_activation_function();
	std::vector<std::vector<float>> get_full_layer_output();
	std::vector<std::vector<float>> get_full_layer_input();


private:

	uint8_t m_number_of_nodes_in_layer;
	std::vector<Node> m_nodes;
	std::vector<std::vector<float>> m_full_layer_output;
	std::vector<std::vector<float>> m_full_layer_input;


};