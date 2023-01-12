#pragma once
#include "utils/Log.h"
#include "PatientHandler.h"
#include "Matrix.h"
#include "ImageWrapper.h"
#include "Image.h"

class Application
{
public:
    Application();

    ~Application();

    // Initialize anything that needs to be initialized in here ( Called once! )
    void init();

    // Contains the main logic that is updated every frame
    void update();

    // For rendering if we decide to make this graphical at some point
    void render();

    // Contains main program loop and calls update and render each frame
    void run();

    // Call to terminate the application immediately
    void exitFailure(const char* err = "");

    // Returns a pointer to the current Application instance
    static Application* getInstance();

    // Ends the main application loop upon after completing the current iteration
    static void quit();
private:
    bool m_Running;
    PatientHandler m_PatientHandler;

    static Application* m_Instance;
};