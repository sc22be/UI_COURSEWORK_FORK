#ifndef APPLICATION_H
#define APPLICATION_H

/**
 * @brief Singleton with GetCore() method
 * used to be subclass of QApplication.
 * keeping it this way to not break old code.
 */

#include <QApplication>
#include <mutex>
#include "core.h"

class Application
{
public:
    // Get instance
    static Application* instance();

    // Initialise core
    void InitialiseCore(int argc, char* argv[]);

    // Get Core
    inline Core* GetCore() { return m_Core; }
private:

    Application();
    virtual ~Application();

    Core* m_Core = nullptr;

    // Thread safety stuff for initialising core
    std::mutex _mutex;
};

#endif // APPLICATION_H
