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
    if (!m_PatientHandler.load("res/test-data/test.csv"))
    {
        exitFailure();
    }

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

    // Test Matrix
    Matrix a(3, 3, doubs);
    Matrix b(3, 3, doubs);
    MIR::Log::writef("\na = \n%s\n", Matrix::toString(a).c_str());
    MIR::Log::writef("b = \n%s\n", Matrix::toString(b).c_str());
    MIR::Log::writeRaw("a dot b = \n");
    Matrix c = a * b;
    MIR::Log::writef("%s\n", Matrix::toString(c).c_str());
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
