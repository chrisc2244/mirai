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
        ImageWrapper::decodeImageToRGBAVector("D:\\Downloads\\DatasetMirai\\00000001_000.png", width, height);

    static std::vector<pixel> testpixelvec =
        ImageWrapper::convertRGBAVectorToPixelVector(testrgbvec);

    static std::vector<double> testgreyscalevec = ImageWrapper::convertPixelVectorToGreyscaleVector(testpixelvec);

    matrix currMatrix = matrix(3, 3, testgreyscalevec);



    return 0;
}
