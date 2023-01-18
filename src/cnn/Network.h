#pragma once
#include "Layer.h"
#include "Matrix.h"
#include <memory>

class Network
{

public:

	Network();
	~Network();

	// Init gives the network it's input matrix, inputMatrix should be heap allocated, then this class takes ownership because
	// It's the Network's input
	void init(Matrix* inputMatrix);

	Matrix& getInputData();

	void update();

	void addLayer(std::unique_ptr<Layer> layer);

private:
	uint8_t m_batchSize;
	Matrix* m_inputData;
	
	std::vector<std::unique_ptr<Layer>> m_Layers;
	bool isDone; // Flag for whether or not the entire layer has finished
};