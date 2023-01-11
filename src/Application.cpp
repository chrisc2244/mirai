#include "Application.h"

Application* Application::m_Instance = nullptr;

Application::Application() : m_Running(false)
{
    Application::m_Instance = this;
}

Application::~Application() {
    // Close the Log when the application ends
    MIR::Log::close();
}

void Application::init()
{
    // Create a Log
    MIR::Log::create("V.0.1", "mirai_log.txt");
    MIR::Log::writeInfo("Application->init()", "Log created successfully");

    // Patient Population:
    /*if (!m_PatientHandler.load("res/test-data/test.csv"))
    {
        exitFailure();
    }*/

    m_Running = true;
}

void Application::update()
{
    // Update program logic here
    // Just set running to false to close the program for now
    m_Running = false;

    // Test Image Wrapper
    uint16_t width = 0;
    uint16_t height = 0;

    std::vector<unsigned char> vec = ImageWrapper::decodeImageToRGBAVector("res/images/00000001_000.png", width, height);
    std::vector<pixel> pix = ImageWrapper::convertRGBAVectorToPixelVector(vec);
    std::vector<double> doubs = ImageWrapper::convertPixelVectorToGreyscaleVector(pix);

    std::cout << std::endl;

    // Test Matrix that contains the image data
    Matrix a(5, 5, doubs);
    
    // Matrix we want to contain a submatrix of the image data
    Matrix b(3, 3);

    // Logging and printing stuff
    MIR::Log::writef("\na = \n%s\n", Matrix::toString(a).c_str());
    MIR::Log::writef("Before Putting Sub Matrix b = \n%s\n", Matrix::toString(b).c_str());
    MIR::Log::writeRaw("Getting sub matrix at (2, 2)\n");

    // Trying to get a matrix that is in bounds
    try
    {
        a.putSubMatrix(2, 2, b); // It puts the submatrix of a into b
        MIR::Log::writef("\nNew Sub Matrix b = \n%s\n", Matrix::toString(b).c_str());
    }
    catch (std::out_of_range e)
    {
        MIR::Log::writefEr("Application::update()->putSubMatrix()", "putSubmatrix failure : %s", e.what());
    }
    
    MIR::Log::writeRaw("Getting sub matrix at (4, 4)\n");
    // Trying to put submatrix that doesn't exits at (4,4)
    try
    {
        a.putSubMatrix(4, 4, b); // It puts the submatrix of a into b
        MIR::Log::writef("\nNew Sub Matrix b = \n%s\n", Matrix::toString(b).c_str());
    }
    catch (std::out_of_range e)
    {
        MIR::Log::writefWarn("Application::update()->putSubMatrix()", "TESTING: putSubmatrix failure : %s", e.what());
    }
}

void Application::render()
{
    // We will draw stuff here maybe
}

void Application::run()
{
    // Initialize our application
    init();

    // Loop until we set m_Running to false
    while(m_Running)
    {
        update();
        render();
    }
}

void Application::exitFailure()
{
    // Clean up the log if possible
    MIR::Log::close();

    exit(EXIT_FAILURE);
}

Application* Application::getInstance()
{
    return Application::m_Instance;
}
