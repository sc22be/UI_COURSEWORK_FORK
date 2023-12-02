#include "application.h"

Application::Application(int argc, char* argv[]) :
    QApplication(argc, argv),
    m_Core( {argv[1]} )
{

}
