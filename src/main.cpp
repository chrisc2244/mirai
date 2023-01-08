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
        ImageWrapper::decodeImageToRGBAVector("C:\\Users\\Chris\\Downloads\\DatasetMirai\\00000001_000.png", width, height);
     // ImageWrapper::decodeImageToRGBAVector("D:\\Downloads\\DatasetMirai\\00000001_000.png", width, height);

    static std::vector<pixel> testpixelvec =
        ImageWrapper::convertRGBAVectorToPixelVector(testrgbvec);

    static std::vector<double> testgreyscalevec = ImageWrapper::convertPixelVectorToGreyscaleVector(testpixelvec);

    matrix currMatrix = matrix(3, 3, testgreyscalevec);
    matrix matrix_to_add = matrix(3, 3, testgreyscalevec);
    matrix matrix_to_subtract = matrix(3, 3, testgreyscalevec);

    double element_in_matrix = currMatrix[1];
    std::cout << element_in_matrix << std::endl;
    std::cout << std::endl;

    std::cout << currMatrix.size << std::endl;
    std::cout << std::endl;

    matrix::print(currMatrix);
    std::cout << std::endl;

    matrix added_matrix = matrix_to_add + currMatrix;
    matrix::print(added_matrix);
    std::cout << std::endl;

    std::cout << "First matrix - ";
    matrix::print(currMatrix);
    std::cout << std::endl;

    std::cout << "Second matrix ";
    matrix::print(matrix_to_subtract);
    std::cout << std::endl;

    std::cout << "Subtracted matrix = ";
    matrix subtracted_matrix = currMatrix - matrix_to_subtract;
    matrix::print(subtracted_matrix);



}
