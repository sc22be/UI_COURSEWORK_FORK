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
    a.setStyleSheet(":/VideoPlayer.qss");

    // Set global stylesheet
    QFile file(":/assets/VideoPlayer.qss");
    file.open(QFile::ReadOnly);
    QString style_sheet = QLatin1String(file.readAll());
    file.close();
    a.setStyleSheet(style_sheet);

    // Translator
    QTranslator translator;
    QString translationFile = ":/assets/translations/staysimple_en_US.qm";
    if (QFile::exists(translationFile))
    {
        translator.load(translationFile);
    }
    a.installTranslator(&translator);

    MainWindow w(nullptr);
    w.show();

    return a.exec();
}
