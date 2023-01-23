#include "ConvLayer.h"
#include <iostream>
#include <vector>
#include "Matrix.h"
#include "../utils/Log.h"

ConvLayer::ConvLayer(std::string id)
	: m_numberOfNodesInLayer(0), m_currentWindowCol(0), m_currentWindowRow(0), m_inputMatrix(nullptr), m_isDone(false), Layer(id)
{
};

//not using this yet, dunno how I wanna set this up yet, need more research
ConvLayer::ConvLayer(const uint8_t numberOfNodes, const std::vector<Node>& nodes, Matrix& inputMatrix)
{
	m_Nodes = nodes;
	m_numberOfNodesInLayer = numberOfNodes;
	m_inputMatrix = &inputMatrix; // Changed this to address of input matrix J.C.
	m_currentWindowCol = 0;
	m_currentWindowRow = 0;

}

ConvLayer::~ConvLayer()
{
	std::cout << "Delete Conv Layer";
	delete m_inputTensor;
}

//void ConvLayer::init(Matrix* inputMatrix, uint8_t windowCols, uint8_t windowRows) // Added window columns and rows (SIZE OF THE WINDOW MATRIX) J.C
//{
//	m_inputMatrix = inputMatrix; // Copy the pointer J.C.
//	m_window.reset(windowCols, windowRows);
//}

void ConvLayer::init(Matrix* inputMatrix)
{
	m_inputMatrix = inputMatrix; // Copy the pointer J.C.
}

void ConvLayer::init(TensorPtrs* inputTensor, uint16_t windowCols, uint16_t windowRows)
{
	m_inputTensor = inputTensor; // Copy the pointer J.C.
	setWindowSize(windowCols, windowRows);
	// Initialize all de nodes to the proper output matrix size
	uint16_t outCols = inputTensor->getElement(0)->getColumnAmount() - windowCols + 1;
	uint16_t outRows = inputTensor->getElement(0)->getRowAmount() - windowRows + 1;
	for (Node& n : m_Nodes)
	{
		n.initOutputs(inputTensor->size(), outRows, outCols);
	}
}


void ConvLayer::forwardPropagate()
{

}

void ConvLayer::backwardPropagate()
{

}

void ConvLayer::applyActivationFunction()
{

}

void ConvLayer::setNumNodes(uint16_t size)
{
	m_Nodes.reserve(size);
}

void ConvLayer::addNode(Matrix* filter, int bias)
{
	m_Nodes.emplace_back(filter, bias); // This will add a COPY of the node
}


void ConvLayer::convolve()
{

	if (!m_isDone)
	{
		//to update this every frame, window starts at 0,0
		(*m_inputTensor)[m_currentTensor]->putSubMatrix(m_currentWindowCol, m_currentWindowRow, m_window); // We are putting a submatrix of the inputMatrix into m_window J.C.
		//Matrix::print(m_window);

		for (Node& node : m_Nodes)
		{
			node.applyFilter(m_window, m_currentTensor, m_currentWindowCol, m_currentWindowRow);
		}

		//TODO: scuffed af bounds checking but it works... maybe fix it later :D

		if (m_currentWindowCol < (*m_inputTensor)[m_currentTensor]->getColumnAmount() - m_window.getColumnAmount())
		{
			m_currentWindowCol++;

		}
		else if (m_currentWindowRow < (*m_inputTensor)[m_currentTensor]->getRowAmount() - m_window.getRowAmount())
		{
			m_currentWindowCol = 0;
			m_currentWindowRow++;
		}
		else if (m_currentTensor < (*m_inputTensor).size()-1)
		{
			m_currentTensor++;
			m_currentWindowCol = 0;
			m_currentWindowRow = 0;
		}
		else
		{
			m_isDone = true;
			// Get all the nodes outputs,
			// Construct a matrix for each
			// Build a tensor for it
			TensorPtrs output(m_Nodes.size());
			for (Node& node : m_Nodes)
			{
				node.combineOutputs();
				output.addElement(node.getOutput());
			}
			MIR::Log::writefInfo("Layer::convolve()", "Layer \"%s\" finished processing...", m_Id.c_str());
		}
	}
}

void ConvLayer::getOutputOfNodes()
{
	// Get all of the outputs for the nodes and throw them in a vector of matrices
	for (Node& n : m_Nodes) {

	}
}

void ConvLayer::setWindowSize(uint8_t windowCols, uint8_t windowRows)
{
	m_window.reset(windowCols, windowRows);
}

void ConvLayer::step()
{
	convolve();
	getOutputOfNodes();
}
