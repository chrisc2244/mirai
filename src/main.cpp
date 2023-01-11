#include "Application.h"
#include "Matrix.h"
#include "ImageWrapper.h"
#include "Layer.h"




int main()
{
    //Application app;
	//app.run();
    uint16_t width = 0;
    uint16_t height = 0;

    std::vector<unsigned char> vec = ImageWrapper::decodeImageToRGBAVector("res/images/00000001_000.png", width, height);
    std::vector<pixel> pix = ImageWrapper::convertRGBAVectorToPixelVector(vec);
    std::vector<double> doubs = ImageWrapper::convertPixelVectorToGreyscaleVector(pix);

    Matrix inputMatrix(10, 10, doubs);
    Matrix windowHolder(3, 3);
    Matrix::print(inputMatrix);
    std::cout << std::endl;
    
    Layer layer;

    /*
    inputMatrix.putSubMatrix(layer.getCurrentColumnPos(), layer.getCurrentRowPos(), windowHolder);

   
    Matrix::print(windowHolder);
    
   
    std::cout << "testing window moving" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "slide: " << i + 1 << std::endl;

        Layer::slideWindow(inputMatrix, windowHolder, 1,
            layer.getCurrentRowPos(), layer.getCurrentColumnPos());

        layer.setCurrentColumnPos(layer.getCurrentColumnPos());

        Matrix::print(windowHolder);
        std::cout << std::endl;
    }
    */

    layer.processInputMatrix(inputMatrix);



}