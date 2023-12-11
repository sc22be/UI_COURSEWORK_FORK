#include "video.h"

#include <QString>

Video::Video(std::string path, QDateTime date) :
    m_Path(path),
    m_Date(date)
{

}

QUrl Video::GetURL()
{
    QUrl local_file = QUrl::fromLocalFile(m_Path.c_str());
    return QUrl(QUrl::fromLocalFile(m_Path.c_str()));
}
