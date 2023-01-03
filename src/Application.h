#pragma once
#include "utils/Log.h"
#include "PatientHandler.h"

class Application
{
public:
    // No constructor until we find a reason for it

    ~Application();

    // Initialize anything that needs to be initialized in here
    void init();

    // Contains the main logic that is updated every frame
    void update();

    // For rendering if we decide to make the graphical at some point
    void render();

    // Contains main program loop and calls update and render each frame
    void run();
private:
    bool m_Running;
    PatientHandler m_PatientHandler;
};