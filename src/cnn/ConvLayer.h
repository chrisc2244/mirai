#pragma once
#include "Node.h"
#include "Layer.h"
#include <vector>

class ConvLayer : virtual public Layer
{
public:

	ConvLayer(std::string id);
	ConvLayer(const uint8_t numberOfNodes, const std::vector<Node>& nodes, Matrix& inputMatrix);

	void init(Matrix* inputMatrix);
		;
	void init(Matrix* inputMatrix, uint8_t windowCols, uint8_t windowRows); //? Give init a pointer to the Network's input matrix J.C.

	void convolve();
	void step();
	void getOutputOfNodes();

	void setWindowSize(uint8_t windowCols, uint8_t windowRows);

	//none of this block implemented yet
	void forwardPropagate();
	void backwardPropagate();
	void applyActivationFunction();
	std::vector<std::vector<Matrix>> getFullLayerOutput();

	// Set Initial Vector size
	void setNumNodes(uint16_t size);

	// Add Node
	void addNode(Matrix* filter, int bias = 0);

	// Returns trus if layer is done processing
	inline bool isDone() { return m_isDone; }

private:

	uint16_t m_numberOfNodesInLayer;
	std::vector<std::vector<Matrix>> m_fullLayerOutput;
	std::vector<Node> m_Nodes;

	uint16_t m_currentWindowCol;
	uint16_t m_currentWindowRow;

	Matrix* m_inputMatrix; //? Input matrix should be a pointer to the matrix that we have in Network J.C.

	Matrix m_window; //? This will be the window for the entire layer to give a pointer to for each node JC.

	Layer* previous;

	bool m_isDone; // Flag for whether or not the layer has finished processing
};
