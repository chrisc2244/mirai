#pragma once
#include "Node.h"
#include "Layer.h"
#include <vector>
#include "TensorPtrs.h"

class ConvLayer : virtual public Layer
{
public:

	ConvLayer(std::string id);

	~ConvLayer();

	void init(Matrix* inputMatrix); // First layer only get one input matrix
	void init(TensorPtrs* inputTensor); // Subsequent layers get input matrices for each node in the previous layer


	void init(TensorPtrs* inputTensor, uint8_t windowCols, uint8_t windowRows); //? Give init a pointer to the Network's input matrix J.C.

	void convolve();
	void step();
	
	inline TensorPtrs* getOutput() const { return m_outputTensor; }

	//none of this block implemented yet
	void forwardPropagate();
	void backwardPropagate();
	void applyActivationFunction();


	// Set Initial Vector size
	void setNumNodes(uint8_t size);

	// Add Node
	void addNode(Matrix* filter, int bias = 0);

	void finishUp();

	// Returns trus if layer is done processing
	inline bool isDone() { return m_isDone; }

private:

	uint16_t m_numberOfNodesInLayer;
	std::vector<Node> m_Nodes;

	std::vector<Matrix*>* m_inputMatrices; // Pointer to a vector of pointers to matrices

	uint16_t m_currentWindowCol;
	uint16_t m_currentWindowRow;

	uint8_t m_currentTensor;

	Matrix* m_inputMatrix; //? Input matrix should be a pointer to the matrix that we have in Network J.C.
	TensorPtrs* m_inputTensor;

	TensorPtrs* m_outputTensor;

	//Tensor m_outputTensor;

	Matrix m_window; //? This will be the window for the entire layer to give a pointer to for each node JC.

	bool m_isDone; // Flag for whether or not the layer has finished processing

	void setWindowSize(uint8_t windowCols, uint8_t windowRows);
};
