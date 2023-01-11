#pragma once
#include "Node.h"
#include <vector>

class Layer

{

public:

	Layer();
	Layer(const uint8_t numberOfNodes, const std::vector<Node>& nodes);

	static void forwardPropagate();
	static void backwardPropagate();
	static void applyActivationFunction();
	std::vector<std::vector<float>> getFullLayerOutput();
	std::vector<std::vector<float>> getFullLayerInput();
	static void slideWindow(Matrix &inputMatrix, Matrix& windowHolder, uint8_t steps, int currentRowPos, int currentColumnPos);
	int getCurrentColumnPos();
	int getCurrentRowPos();
	void setCurrentRowPos(int currentRow);
	void setCurrentColumnPos(int currentColumn);
	void processInputMatrix(Matrix& inputMatrix);
private:

	uint8_t m_number_of_nodes_in_layer;
	std::vector<Node> m_nodes;
	std::vector<std::vector<float>> m_full_layer_output;
	std::vector<std::vector<float>> m_full_layer_input;
	int m_currentColumnPos;
	int m_currentRowPos;

};