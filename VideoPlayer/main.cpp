#include "mainwindow.h"

#include <QApplication>
#include <QFile>

/**
 * @author Mustafa Yozgyur
 * @author ...
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(":/VideoPlayer.qss");

    // Set global stylesheet
    QFile file(":/assets/VideoPlayer.qss");
    file.open(QFile::ReadOnly);
    QString style_sheet = QLatin1String(file.readAll());
    file.close();
    a.setStyleSheet(style_sheet);

    MainWindow w;
    w.show();

    return a.exec();
}
