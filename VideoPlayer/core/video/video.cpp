#include "video.h"

#include <QString>

Video::Video(std::string path, QDateTime date) :
    m_Path(path),
    m_Date(date)
{

}

QUrl Video::GetURL()
{
    return QUrl(QString {m_Path.c_str()});
}
