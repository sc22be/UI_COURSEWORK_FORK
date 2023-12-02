#include "mainwindow.h"

#include "core/application.h"
#include <QFile>
#include <iostream>

/**
 * @author Mustafa Yozgyur
 * @author ...
*/

int main(int argc, char *argv[])
{
    // Check arg count
    if (argc < 2)
    {
        std::cerr << "No path for videos folder given!" << std::endl;
        return -1;
    }

    Application a(argc, argv);
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
