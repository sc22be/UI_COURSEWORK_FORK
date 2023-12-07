#ifndef APPLICATION_H
#define APPLICATION_H

/**
 * @brief Subclass of QApplication with GetCore() method
 */

#include <QApplication>
#include "core.h"

class Application : public QApplication
{
public:
    Application(int argc, char* argv[]);
    virtual ~Application();

    // Get instance
    static Application* instance() { return static_cast<Application*>(QApplication::instance()); }

    // Get Core
    inline Core* GetCore() { return m_Core; }
private:

    Core* m_Core = nullptr;
};

#endif // APPLICATION_H
