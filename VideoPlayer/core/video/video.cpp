#include "video.h"

#include <QString>
#include <iostream>

Video::Video(std::string path, QDateTime date) :
    m_Path(path),
    m_Date(date)
{

}

QUrl Video::GetURL()
{
    QUrl local_file = QUrl::fromLocalFile(m_Path.c_str());
    std::cout << "sxjhdjs: " << local_file.toDisplayString().toStdString() << std::endl;
    return QUrl(QUrl::fromLocalFile(m_Path.c_str()));
}
