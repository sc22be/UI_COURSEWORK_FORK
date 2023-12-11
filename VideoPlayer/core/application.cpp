#include "application.h"

Application *Application::instance()
{
    // Our singleton instance
    static Application application;

    return &application;
}
void Application::InitialiseCore(int argc, char *argv[])
{
    // Lock the mutex so that this is thread safe
    _mutex.lock();

    if (m_Core != nullptr) { return; }

    // If no args given, default assets path to cwd/assets
    if (argc < 2)
    {
        m_Core = new Core({"."});
    } else
    {
        m_Core = new Core({argv[1]});
    }

    _mutex.unlock();
}

Application::Application()
{

}

Application::~Application()
{
    // Free core
    delete m_Core;
}
