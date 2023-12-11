#include "mainwindow.h"

#include "core/countdown.h"
#include "core/application.h"
#include <QFile>
#include <iostream>
#include <QString>
#include <QTranslator>

/**
 * @author Mustafa Yozgyur
 * @author Muhammad Kashif-Khan
*/

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    a.setStyleSheet(":/VideoPlayer.qss");

    // Set global stylesheet
    QFile file(":/assets/VideoPlayer.qss");
    file.open(QFile::ReadOnly);
    QString style_sheet = QLatin1String(file.readAll());
    file.close();
    a.setStyleSheet(style_sheet);

    // Translator
    QTranslator translator;
    translator.load(":/translations/staysimple_en.qm");
    a.installTranslator(&translator);
    QObject::tr("Testing");

    MainWindow w(nullptr);
    w.show();

    return a.exec();
}
