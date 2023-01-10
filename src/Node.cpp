#include "Node.h"

node::node() = default;

node::node(const std::vector<float>& weights, const std::vector<float>& input_float_vec)
{
	m_weights = weights;
	m_input_float_vec = input_float_vec;
	m_bias = 0; //not included in constructor, just setting to 0 for now in case we want it later
}

std::vector<float> node::get_weights() 
{
	return m_weights;
}

std::vector<float> node::get_input_float_vec() 
{
	return m_input_float_vec;
}

void node::set_output_vec(const std::vector<float>& output_float_vec)
{
	m_output_float_vec = output_float_vec;
}

std::vector<float> node::get_output_float_vec()
{
	return m_output_float_vec;
}

void node::set_bias(const uint8_t bias)
{
	m_bias = bias;
}

uint8_t node::get_bias()
{
	return m_bias;
}
