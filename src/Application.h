#pragma once
#include "utils/Log.h"
#include "PatientHandler.h"

class Application
{
public:
    Application();

    ~Application();

    // Initialize anything that needs to be initialized in here
    void init();

    // Contains the main logic that is updated every frame
    void update();

    // For rendering if we decide to make the graphical at some point
    void render();

    // Contains main program loop and calls update and render each frame
    void run();

    // Call to terminate the application
    void exitFailure();

    // Returns a pointer to the application 
    static Application* getInstance();
private:
    bool m_Running;
    PatientHandler m_PatientHandler;

    static Application* m_Instance;
};