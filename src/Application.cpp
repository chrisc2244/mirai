#include "Application.h"
#include "cnn/ConvLayer.h"

#define LOAD_PATIENTS 0 // Flag to enable (1) or disable (0) loading patient data for debugging

Application* Application::m_Instance = nullptr;

Application::Application()
    : m_Running(false)
{
    Application::m_Instance = this;
}

Application::~Application()
{
    // Close the Log when the application ends
    MIR::Log::close();
}
void Application::buildNetwork()
{

    // Create a Tensor of the input matrix
    TensorPtrs* inputTensor = new TensorPtrs(m_InputMatrix);

    // Get input Data
    m_Network.init(inputTensor);

    // Create network
    // Layer 1
    ConvLayer* l1 = new ConvLayer("conv_layer_1");
    l1->setNumNodes(3);

    // Node 1
    Matrix* filter = new Matrix(4, 4, 0.6);

    // Node 2
    Matrix* filter2 = new Matrix(4, 4, 0.1);

    // Node 3
    Matrix* filter3 = new Matrix(4, 4, 0.4);

    l1->addNode(filter);
    l1->addNode(filter2);
    l1->addNode(filter3);

    // Layer.init

    
    //inputTensor->addElement(new Matrix(1024, 1024, 0.2));

    l1->init(inputTensor, 4, 4);

    // Add Layer 1 to network
    m_Network.addLayer(std::move(l1));
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

    m_InputMatrix = new Matrix(1024, 1024, doubs);

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

    buildNetwork();
}




	
void Application::update()
{
	// Update program logic here

    m_Network.update();
    if (m_Network.isDone())
    {
        quit();
    }

    // Just set running to false to close the program for now
    //quit();
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
