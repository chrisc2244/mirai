#include "Application.h"

#define LOAD_PATIENTS 0 // Flag to enable (1) or disable (0) loading patient data for debugging

Application* Application::m_Instance = nullptr;

Application::Application() : m_Running(false)
{
    Application::m_Instance = this;
}

Application::~Application()
{
    // Close the Log when the application ends
    MIR::Log::close();
} 

void Application::init()
{
    // Create a Log
    MIR::Log::create("V.0.1", "mirai_log.txt");
    MIR::Log::writeInfo("Application->init()", "Log created successfully");


    //image setup, firstInputMatrix is greyscale image data input ready for processing/iteration
    uint16_t width = 0;
    uint16_t height = 0;
    std::vector<unsigned char> vec = ImageWrapper::decodeImageToRGBAVector("res/images/00000001_000.png", width, height);
    std::vector<pixel> pix = ImageWrapper::convertRGBAVectorToPixelVector(vec);
    std::vector<double> doubs = ImageWrapper::convertPixelVectorToGreyscaleVector(pix);
	Matrix firstInputMatrix(1024,1024, doubs);

    m_firstInputMatrix = firstInputMatrix;
    m_network.init(firstInputMatrix);

    // Initialize Patient Handler 
#if LOAD_PATIENTS 
    MIR::Log::writeInfo("Application->init()", "Attempting to load patient data...");
    // Load and Construct Patient Population:
    if (!m_PatientHandler.load("res/test-data/test.csv"))
    {
        MIR::Log::writeEr("Application->init()", "Patient Loading failed, terminating program...");
        exitFailure();
    }
#else
    MIR::Log::writeWarn("Application->init()", "Patient Loading disabled, to renable set LOAD_PATIENTS to 1 in Application.cpp");
#endif

    // Start the main application loop
    m_Running = true;
}




	
void Application::update()
{
	// Update program logic here

    m_network.update();




    // Just set running to false to close the program for now
    quit();
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
        
        //render(); No rendering currently
    }
}

void Application::exitFailure(const char* err)
{
    MIR::Log::writefEr("Application::exitFailure()", "%s", err);
    // Clean up the log if possible
    MIR::Log::close();

    exit(EXIT_FAILURE);
}

Application* Application::getInstance()
{
    return Application::m_Instance;
}

void Application::quit()
{
    Application::getInstance()->m_Running = false;
}
