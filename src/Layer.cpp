#include "Layer.h"
#include <iostream>
#include <vector>
#include "Matrix.h"

Layer::Layer() : m_currentColumnPos(0), m_currentRowPos(0) {}

Layer::Layer(const uint8_t numberOfNodes, const std::vector<Node>& nodes)
{
	m_number_of_nodes_in_layer = numberOfNodes;
	m_nodes = nodes;
	
}


void Layer::forwardPropagate() 
{

}

void Layer::backwardPropagate()
{
	
}

void Layer::applyActivationFunction()
{
	
}

std::vector<std::vector<float>> Layer::getFullLayerOutput()
{
	return m_full_layer_output;
}

std::vector<std::vector<float>> Layer::getFullLayerInput()
{
	return m_full_layer_input;
}

/*
//TODO: fix this? might not actually need.
void Layer::slideWindow(Matrix& inputMatrix, Matrix& windowHolder, uint8_t step, int currentRowPos, int currentColumnPos)
{
	int rows = inputMatrix.getRowAmount();
	int cols = inputMatrix.getColumnAmount();
	for (int i = currentRowPos; i <= rows - windowHolder.getRowAmount() && step > 0; i++)
	{
		for (int j = currentColumnPos; j <= cols - windowHolder.getColumnAmount() && step > 0; j++)
		{
			inputMatrix.putSubMatrix(i, j, windowHolder);
			step--;
		}
	}
}
*/


//TODO: possibly consider just having this loop and put the nodes inside this... idk
void Layer::processInputMatrix(Matrix& inputMatrix) {
	Matrix windowHolder(3, 3);
	int rows = inputMatrix.getRowAmount();
	int cols = inputMatrix.getColumnAmount();

	// i <= rows - windowHolder.getRowAmount() ensures submatrices stay within bounds of bottom edge
	for (int i = 0; i <= rows - windowHolder.getRowAmount(); i++) {
		// i <= rows - windowHolder.getRowAmount() ensures submatrices stay within bounds of right edge
		for (int j = 0; j <= cols - windowHolder.getColumnAmount(); j++) {
			//j, i = column by column
			//i, j = row by row
			inputMatrix.putSubMatrix(j, i, windowHolder);
			//node processing goes here 
		}
	}
}



int Layer::getCurrentColumnPos()
{
	return m_currentColumnPos;
}

int Layer::getCurrentRowPos()
{
	return m_currentRowPos;
}

void Layer::setCurrentRowPos(int currentRow)
{
	m_currentRowPos = currentRow;
}

void Layer::setCurrentColumnPos(int currentColumn)
{
	m_currentColumnPos = currentColumn;
}
