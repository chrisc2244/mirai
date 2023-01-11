#include "Layer.h"
#include <iostream>
#include <vector>
#include "Matrix.h"

Layer::Layer() : m_numberOfNodesInLayer(0) {}
//m_currentColumnPos(0), m_currentRowPos(0) 

//not using this yet, dunno how I wanna set this up yet, need more research
Layer::Layer(const uint8_t numberOfNodes, const std::vector<Node>& nodes)
{
	//m_currentColumnPos = 0;
	//m_currentRowPos = 0;
	m_numberOfNodesInLayer = numberOfNodes;
	
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

std::vector<std::vector<double>> Layer::getFullLayerOutput()
{
	return m_fullLayerOutput;
}

std::vector<std::vector<double>> Layer::getFullLayerInput()
{
	return m_fullLayerInput;
}

/*
//TODO: fix this later for pooling layers?
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

void Layer::processInputMatrix(Matrix& inputMatrix) {
	//Node m_filter and windowHolder matrix rows/cols must match or invalid argument exception will be thrown
	//from multiplyMatrices inside applyFilter node method
	Matrix windowHolder(3, 3);
	int rows = inputMatrix.getRowAmount();
	int cols = inputMatrix.getColumnAmount();

	// i <= rows - windowHolder.getRowAmount() ensures submatrices stay within bounds of bottom edge
	for (int i = 0; i <= rows - windowHolder.getRowAmount(); i++) {
		// i <= rows - windowHolder.getRowAmount() ensures sub-matrices stay within bounds of right edge
		for (int j = 0; j <= cols - windowHolder.getColumnAmount(); j++) {
			//j, i = column by column
			//i, j = row by row
			//TODO: possibly j + currentWindowCol, i + currentWindowRow to get next sub matrix? idk, needa figure that out
			inputMatrix.putSubMatrix(j, i, windowHolder);
			//Matrix::print(windowHolder);

			//node processing goes here
			m_node1.applyFilter(windowHolder);
			m_node2.applyFilter(windowHolder);
			m_node3.applyFilter(windowHolder);
		}
	}
	//just have this here for now to print to terminal to verify accuracy
	m_node1.printProcessedResults();
	std::cout << std::endl;

	m_node2.printProcessedResults();
	std::cout << std::endl;

	m_node3.printProcessedResults();
	std::cout << std::endl;
}

void Layer::setNode1(const Node& node1)
{
	m_node1 = node1;
}

void Layer::setNode2(const Node& node2)
{
	m_node2 = node2;
}

void Layer::setNode3(const Node& node3)
{
	m_node3 = node3;
}


/*
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
*/