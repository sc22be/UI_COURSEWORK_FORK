#include "mainwindow.h"

#include "core/application.h"
#include <QFile>
#include <QLocale>
#include <QString>
#include <QTranslator>
#include <QDir>

/**
 * @author Mustafa Yozgyur
 * @author Muhammad Kashif-Khan
 * @author Brent Edington
*/

int main(int argc, char *argv[])
{
    // Initialise core
    Application::instance()->InitialiseCore(argc, argv);

    QApplication a(argc, argv);
    Application::setAppInstance(&a);
    a.setStyleSheet(":/VideoPlayer.qss");

    // Set global stylesheet
    QFile file(":/assets/VideoPlayer.qss");
    file.open(QFile::ReadOnly);
    QString style_sheet = QLatin1String(file.readAll());
    file.close();
    a.setStyleSheet(style_sheet);

    MainWindow w(nullptr);
    w.show();

    return a.exec();
}
