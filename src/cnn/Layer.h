#pragma once
#include "Node.h"
#include <vector>
#include "TensorPtrs.h"


class Layer
{
public:

	Layer(std::string id = "");

	virtual void step() = 0;

	// Returns trus if layer is done processing
	virtual bool isDone() = 0;

protected:

	std::vector<Node> m_Nodes;
	Layer* m_Previous;
	bool m_isDone; // Flag for whether or not the layer has finished processing

	std::string m_Id;
};
