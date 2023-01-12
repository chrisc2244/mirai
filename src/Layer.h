#pragma once
#include "Node.h"
#include <vector>

class Layer

{

public:

	Layer();
	Layer(const uint8_t numberOfNodes, const std::vector<Node>& nodes, Matrix& inputMatrix);

	void init(Matrix& inputMatrix);

	//none of this block implemented yet
	static void forwardPropagate();
	static void backwardPropagate();
	static void applyActivationFunction();
	std::vector<std::vector<Matrix>> getFullLayerOutput();
	std::vector<std::vector<double>> getFullLayerInput();
	void convolve();
	void getOutputOfNodes();
	void step();



	void processInputMatrix(Matrix& inputMatrix);
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
	std::vector<std::vector<double>> m_fullLayerInput;
	std::vector<Node> m_vectorOfCurrentNodes;
	Matrix m_window;
	double* m_windowPtr;
	uint16_t m_currentWindowCol;
	uint16_t m_currentWindowRow;
	Matrix m_inputMatrix;
	Node m_node1;
	Node m_node2;
	Node m_node3;

};