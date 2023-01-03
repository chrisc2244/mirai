#include "Application.h"

void Application::init()
{
    m_Running = true;
}

void Application::update()
{
    // Update program logic here
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