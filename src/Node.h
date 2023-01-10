#pragma once
#include <vector>

class node
{


public:

	node();
	node(const std::vector<float>& weights, const std::vector<float>& input_float_vec);

	std::vector<float> get_weights();
	std::vector<float> get_input_float_vec();
	void set_output_vec(const std::vector<float>& output_float_vec);
	std::vector<float> get_output_float_vec();
	void set_bias(uint8_t bias);
	uint8_t get_bias();


private:

	std::vector<float> m_weights;
	std::vector<float> m_input_float_vec;
	std::vector<float> m_output_float_vec;
	uint8_t m_bias;


};