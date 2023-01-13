#pragma once
#include "Layer.h"

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


private:
	uint8_t m_batchSize;
	Matrix* m_inputData;
	Layer m_Layer1;
	
};