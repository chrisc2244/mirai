#pragma once
#include "Layer.h"

class Network
{

public:

	Network();

	void init(Matrix& inputMatrix);

	Matrix& getInputData();

	void update();


private:
	uint8_t m_batchSize;
	Matrix m_inputData;
	Layer m_Layer1;
	
};