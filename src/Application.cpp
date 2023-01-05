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
