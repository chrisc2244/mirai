#include "Application.h"
#include "Matrix.h"
#include "ImageWrapper.h"
#include "Layer.h"
#include "Node.h"



int main()
{
    Application app;
	app.run();

    /*
    //Application app;
    //app.run();

    //TODO: Try and make all this shit work with application framework
    uint16_t width = 0;
    uint16_t height = 0;

    std::vector<unsigned char> vec = ImageWrapper::decodeImageToRGBAVector("res/images/00000001_000.png", width, height);
    std::vector<pixel> pix = ImageWrapper::convertRGBAVectorToPixelVector(vec);
    std::vector<double> doubs = ImageWrapper::convertPixelVectorToGreyscaleVector(pix);

    Layer firstLayer;

    //printing this so you can compare it in terminal
    Matrix inputMatrix(5, 5, doubs);
    //Matrix::print(inputMatrix);

    Matrix testWeights1(3, 3, 0.25);
    Node node1(&testWeights1, 1);

    Matrix testWeights2(3, 3, 0.5);
    Node node2(&testWeights2, 1);

    Matrix testWeights3(3, 3, 0.75);
    Node node3(&testWeights3, 1);

    firstLayer.setNode1(node1);
    firstLayer.setNode2(node2);
    firstLayer.setNode3(node3);

    firstLayer.processInputMatrix(inputMatrix);
    */




}