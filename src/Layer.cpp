#include "Layer.h"
#include <iostream>
#include <vector>
#include "Matrix.h"

Layer::Layer() = default;

//not using this yet, dunno how I wanna set this up yet, need more research
Layer::Layer(const uint8_t numberOfNodes, const std::vector<Node>& nodes, Matrix& inputMatrix)
{
	m_vectorOfCurrentNodes = nodes;
	m_numberOfNodesInLayer = numberOfNodes;
	m_inputMatrix = &inputMatrix; // Changed this to address of input matrix J.C.
	m_currentWindowCol = 0;
	m_currentWindowRow = 0;
	m_windowPtr = nullptr;
	
}

void Layer::init(Matrix* inputMatrix, uint8_t windowCols, uint8_t windowRows) // Added window columns and rows (SIZE OF THE WINDOW MATRIX) J.C
{
	m_inputMatrix = inputMatrix; // Copy the pointer J.C.
	m_window.reset(windowCols, windowRows);


	////creates empty 4x4 matrix to be used as window
	//Matrix window(4, 4);
	//m_window = window;

	////populate m_window with first 4x4 window of input at (0,0)
	//m_inputMatrix.putSubMatrix(m_currentWindowCol, m_currentWindowRow, m_window); We already have a window m_window

	/*
	 * Initialize Nodes with their weights, eventually we'll need to initialize these weight matrices
	 * with the previous batch's data from a txt file
	 */

	Matrix* weights1 = new Matrix(4, 4, 0.25);
	m_node1.setFilter(weights1);

	Matrix* weights2 = new Matrix(4, 4, 0.5);
	m_node2.setFilter(weights2);

	Matrix* weights3 = new Matrix(4, 4, 0.75);
	m_node3.setFilter(weights3);
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

std::vector<std::vector<Matrix>> Layer::getFullLayerOutput()
{
	return m_fullLayerOutput;
}

std::vector<std::vector<double>> Layer::getFullLayerInput()
{
	return m_fullLayerInput;
}

void Layer::convolve()
{

	//to update this every frame, window starts at 0,0
	m_inputMatrix->putSubMatrix(m_currentWindowCol, m_currentWindowRow, m_window); // We are putting a submatrix of the inputMatrix into m_window J.C.

	/*
	if(m_count % 10000 == 0 && m_count >= 50000) // Check and see what the window looks like. FOR some reason it's full of 0s after around 60k iterations
	{
		std::cout << m_count << ": " << std::endl;
		Matrix::print(m_window);
	}
	*/

	std::cout << "Current m_count: " << m_count << ". ";

	m_node1.applyFilter(m_window);
	m_node2.applyFilter(m_window);
	m_node3.applyFilter(m_window);

	std::cout << "Last processed result from node1: " << m_node1.getProcessedResult() << std::endl;
	std::cout << "Total processed result vector size: ";
	m_node1.printProcessedResultsSize();


	//TODO: scuffed af bounds checking but it works... maybe fix it later :D
	if (m_count != 1042440)
	{
		if (m_currentWindowCol < m_inputMatrix->getColumnAmount() - m_window.getColumnAmount())
		{
			m_currentWindowCol++;

		}
		else if (m_currentWindowRow < m_inputMatrix->getRowAmount() - m_window.getRowAmount())
		{
			m_currentWindowCol = 0;
			m_currentWindowRow++;
		}
		else
		{
			throw std::out_of_range("m_currentWindowCol or m_currentWindowRow attempting to go out of bounds of m_inputMatrix");
		}
		m_count++;
	}
}

void Layer::getOutputOfNodes()
{
	//TODO: this stuff below
	//fill storage matrix here for each node each tick
	// need to figure out? how big output matrix for each node needs to be...
	//then initialize that and fill it index by index here 

	double node1Result = m_node1.getProcessedResult();
	double node2Result = m_node2.getProcessedResult();
	double node3Result = m_node3.getProcessedResult();
}

void Layer::step()
{
	convolve();
	getOutputOfNodes();
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

// Don't need this -J.C.
// 
// //processes the entire input matrix... need to do it one by one.
//void Layer::processInputMatrix(Matrix& inputMatrix) {
//	//Node m_filter and windowHolder matrix rows/cols must match or invalid argument exception will be thrown
//	//from multiplyMatrices inside applyFilter node method
//	Matrix windowHolder(3, 3);
//	int rows = inputMatrix.getRowAmount();
//	int cols = inputMatrix.getColumnAmount();
//
//	// i <= rows - windowHolder.getRowAmount() ensures submatrices stay within bounds of bottom edge
//	for (int i = 0; i <= rows - windowHolder.getRowAmount(); i++) {
//		// i <= rows - windowHolder.getRowAmount() ensures sub-matrices stay within bounds of right edge
//		for (int j = 0; j <= cols - windowHolder.getColumnAmount(); j++) {
//			//j, i = column by column
//			//i, j = row by row
//			//TODO: possibly j + currentWindowCol, i + currentWindowRow to get next sub matrix? idk, needa figure that out
//			inputMatrix.putSubMatrix(j, i, windowHolder);
//			//Matrix::print(windowHolder);
//
//			//node processing goes here
//			m_node1.applyFilter(windowHolder);
//			m_node2.applyFilter(windowHolder);
//			m_node3.applyFilter(windowHolder);
//		}
//	}
//	//just have this here for now to print to terminal to verify accuracy
//	m_node1.printProcessedResults();
//	std::cout << std::endl;
//
//	m_node2.printProcessedResults();
//	std::cout << std::endl;
//
//	m_node3.printProcessedResults();
//	std::cout << std::endl;
//}

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