#include "application.h"

Application::Application(int argc, char* argv[]) :
    QApplication(argc, argv)
{
    // If no args given, default assets path to cwd/assets
    if (argc < 2)
    {
        m_Core = new Core({""});
    } else
    {
        m_Core = new Core({argv[1]});
    }
}

Application::~Application()
{
    // Free core
    delete m_Core;
}
