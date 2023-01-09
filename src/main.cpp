#include "Application.h"
#include "Matrix.h"
#include "ImageWrapper.h"


int main()
{
    //Application app;
    //app.run();

    uint16_t width = 0;
    uint16_t height = 0;
    static std::vector<uint8_t> testrgbvec =
        //ImageWrapper::decodeImageToRGBAVector("C:\\Users\\Chris\\Downloads\\DatasetMirai\\00000001_000.png", width, height);
        ImageWrapper::decodeImageToRGBAVector("D:\\Downloads\\DatasetMirai\\00000001_000.png", width, height);

    static std::vector<pixel> testpixelvec =
        ImageWrapper::convertRGBAVectorToPixelVector(testrgbvec);

    static std::vector<double> testgreyscalevec = ImageWrapper::convertPixelVectorToGreyscaleVector(testpixelvec);

    matrix currMatrix = matrix(2, 4, testgreyscalevec);
    matrix matrix_to_add = matrix(2, 4, testgreyscalevec);
    matrix matrix_to_subtract = matrix(2, 4, testgreyscalevec);

    /*
    double element_in_matrix = currMatrix[1];
    std::cout << element_in_matrix << std::endl;
    std::cout << std::endl;

    std::cout << +currMatrix.getSize() << std::endl;
    std::cout << std::endl;

    matrix::print(currMatrix);
    std::cout << std::endl;

    matrix added_matrix = matrix_to_add + currMatrix;
    matrix::print(added_matrix);
    std::cout << std::endl;

    std::cout << "First matrix - ";
    std::cout << std::endl;
    matrix::print(currMatrix);
    std::cout << std::endl;

    std::cout << "Second matrix ";
    std::cout << std::endl;
    matrix::print(matrix_to_subtract);
    std::cout << std::endl;

    std::cout << "Subtracted matrix = ";
    std::cout << std::endl;
    matrix subtracted_matrix = currMatrix - matrix_to_subtract;
    matrix::print(subtracted_matrix);
    std::cout << std::endl;

    
    matrix::print(currMatrix);
    std::cout << std::endl;
    std::cout << currMatrix(0, 0);
    std::cout << std::endl;
    std::cout << currMatrix(0, 1);
    std::cout << std::endl;
    std::cout << currMatrix(0, 2);
    std::cout << std::endl;
    std::cout << currMatrix(1, 2);
    std::cout << std::endl;
    std::cout << currMatrix(1, 4);
    std::cout << std::endl;
    std::cout << currMatrix(3, 2);
    std::cout << std::endl;
    std::cout << currMatrix(2, 4);
    std::cout << std::endl;
    */

  
    //matrix::print(currMatrix * currMatrix);
    matrix matrixToMultiply1 = matrix(4, 2, testgreyscalevec);
    std::cout << "Testing multiplying matrices: " << std::endl;
    std::cout << "First matrix to multiply: " << std::endl;
	matrix::print(currMatrix);
    std::cout << std::endl;

    std::cout << "Second matrix to multiply: " << std::endl;
    matrix::print(matrixToMultiply1);
    std::cout << std::endl;

    std::cout << "Multiplied matrices: " << std::endl;
    matrix cool = currMatrix * matrixToMultiply1;
    matrix::print(cool);
    std::cout << std::endl;


    matrix matrixToMultiply2 = matrix(4, 9, testgreyscalevec);
    std::cout << "Testing multiplying matrices: " << std::endl;
    std::cout << "First matrix to multiply: " << std::endl;
    matrix::print(currMatrix);
    std::cout << std::endl;

    std::cout << "Second matrix to multiply: " << std::endl;
    matrix::print(matrixToMultiply2);
    std::cout << std::endl;

    std::cout << "Multiplied matrices: " << std::endl;
    matrix cool2 = currMatrix * matrixToMultiply2;
    matrix::print(cool2);
    std::cout << std::endl;

}
