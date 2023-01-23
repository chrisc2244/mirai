#include "ConvLayer.h"
#include <iostream>
#include <vector>
#include "Matrix.h"
#include "../utils/Log.h"

ConvLayer::ConvLayer(std::string id)
	: m_numberOfNodesInLayer(0), m_currentWindowCol(0), m_currentWindowRow(0), m_inputMatrix(nullptr), m_isDone(false), Layer(id),
	  m_currentTensor(0), m_inputMatrices(nullptr), m_inputTensor(nullptr), m_outputTensor(nullptr)
{

};

ConvLayer::~ConvLayer()
{
	/*
		delete m_inputTensor; 
		Layers do NOT own their inputs 
		(Network owns initial input, and previous layer owns every subsequent layer's input)
	*/

	delete m_outputTensor; // They do own their outputs though
}

void ConvLayer::init(Matrix* inputMatrix)
{
	m_inputMatrix = inputMatrix;
}

void ConvLayer::init(TensorPtrs* inputTensor, uint8_t windowCols, uint8_t windowRows)
{
	m_inputTensor = inputTensor;
	setWindowSize(windowCols, windowRows);
	// Initialize all de nodes to the proper output matrix size
	uint16_t outCols = inputTensor->getMatrixColumns() - windowCols;
	uint16_t outRows = inputTensor->getMatrixRows() - windowRows;
	for (Node& n : m_Nodes)
	{
		n.initOutputs(inputTensor->size(), outRows, outCols);
	}
	m_outputTensor->setMatrixSize(outRows, outCols);
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

void ConvLayer::setNumNodes(uint8_t size)
{
	m_Nodes.reserve(size);
	m_outputTensor = new TensorPtrs(size);
	// Temporarily fill the Tensor with matrices of the correct size
	
}

void ConvLayer::addNode(Matrix* filter, int bias)
{
	m_Nodes.emplace_back(filter, bias); // This will add a COPY of the node
}

void ConvLayer::finishUp()
{
	m_isDone = true;
	// Get all the nodes outputs,
	// Construct a matrix for each
	// Build a tensor for it
	m_outputTensor->resetSize(0);
	for (Node& node : m_Nodes)
	{
		node.combineOutputs();
		m_outputTensor->addElement(node.getOutput());
	}
	MIR::Log::writefInfo("Layer::convolve()", "Layer \"%s\" finished processing...", m_Id.c_str());
}


void ConvLayer::convolve()
{

	if (!m_isDone)
	{
		//to update this every frame, window starts at 0,0
		(*m_inputTensor)[m_currentTensor]->putSubMatrix(m_currentWindowCol, m_currentWindowRow, m_window); // We are putting a submatrix of the inputMatrix into m_window J.C.

		for (Node& node : m_Nodes)
		{
			node.applyFilter(m_window, m_currentTensor, m_currentWindowCol, m_currentWindowRow);
		}

		if (m_currentWindowCol < (*m_inputTensor)[m_currentTensor]->getColumnAmount() - m_window.getColumnAmount()-1)
		{
			m_currentWindowCol++;
		}
		else if (m_currentWindowRow < (*m_inputTensor)[m_currentTensor]->getRowAmount() - m_window.getRowAmount()-1)
		{
			m_currentWindowCol = 0;
			m_currentWindowRow++;
		}
		else if (m_currentTensor < (*m_inputTensor).size())
		{
			m_currentTensor++;
			m_currentWindowCol = 0;
			m_currentWindowRow = 0;

			if (m_currentTensor == (*m_inputTensor).size())
			{
				finishUp();
			}
		}
	}
}

void ConvLayer::setWindowSize(uint8_t windowCols, uint8_t windowRows)
{
	m_window.reset(windowCols, windowRows);
}

void ConvLayer::step()
{
	convolve();
}
