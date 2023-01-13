#pragma once
#include "Node.h"
#include <vector>

class Layer

{

public:

	Layer();
	Layer(const uint8_t numberOfNodes, const std::vector<Node>& nodes, Matrix& inputMatrix);

	void init(Matrix* inputMatrix, uint8_t windowCols, uint8_t windowRows); //? Give init a pointer to the Network's input matrix J.C.

	//none of this block implemented yet
	static void forwardPropagate();
	static void backwardPropagate();
	static void applyActivationFunction();
	std::vector<std::vector<Matrix>> getFullLayerOutput();
	std::vector<std::vector<double>> getFullLayerInput();
	void convolve();
	void getOutputOfNodes();
	void step();



	//void processInputMatrix(Matrix& inputMatrix);

	void setNode1(const Node& node1);
	void setNode2(const Node& node2);
	void setNode3(const Node& node3);

	//stuff I might want later for the slideWindow by increment/steps, for pooling layers later possibly
	//static void slideWindow(Matrix &inputMatrix, Matrix& windowHolder, uint8_t steps, int currentRowPos, int currentColumnPos);
	//int getCurrentColumnPos();
	//int getCurrentRowPos();
	//void setCurrentRowPos(int currentRow);
	//void setCurrentColumnPos(int currentColumn);

private:

	//more stuff I might want later 
	/*
	int m_currentColumnPos;
	int m_currentRowPos;
	*/


	uint16_t m_numberOfNodesInLayer;
	std::vector<std::vector<Matrix>> m_fullLayerOutput;
	std::vector<std::vector<double>> m_fullLayerInput; //? Why is this here
	std::vector<Node> m_vectorOfCurrentNodes;
	
	double* m_windowPtr; //? Why is this here
	uint16_t m_currentWindowCol;
	uint16_t m_currentWindowRow;

	Matrix* m_inputMatrix; //? Input matrix should be a pointer to the matrix that we have in Network J.C.
	Matrix m_window; //? This will be the window for the entire layer to give a pointer to for each node JC.

	Node m_node1; // If we have a vector of nodes why do we need this  J.C
	Node m_node2;
	Node m_node3;

	//using this to test ignoire it
	int m_count;

};