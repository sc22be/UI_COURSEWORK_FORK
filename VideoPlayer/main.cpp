#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <Qstring>

/**
 * @author Mustafa Yozgyur
 * @author Muhammad Kashif-Khan
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(":/VideoPlayer.qss");

    // find relative path to directory
    // will be used to find the user's account information, primarily posts and personal videos/uploads
    QString appPath = QCoreApplication::applicationDirPath();

    // Set global stylesheet
    QFile file(":/assets/VideoPlayer.qss");
    file.open(QFile::ReadOnly);
    QString style_sheet = QLatin1String(file.readAll());
    file.close();
    a.setStyleSheet(style_sheet);

    MainWindow w(nullptr, appPath);
    w.show();

    return a.exec();
}
