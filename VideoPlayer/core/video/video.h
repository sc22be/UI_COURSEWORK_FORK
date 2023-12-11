#ifndef VIDEO_H
#define VIDEO_H

/**
 * @brief Holds data about a video
 * @author Mustafa Yozgyur
 * @author Muhammad Kashif-Khan
 */

#include <string>
#include <QDateTime>
#include <QUrl>

class Video
{
public:
    Video(std::string path, QDateTime date);

    // Getters
    inline std::string GetPath() const { return m_Path; }
    inline QDateTime GetDate() const { return m_Date; }

    // Get url of video
    QUrl GetURL();

private:

    std::string m_Path;
    QDateTime m_Date;
};

#endif // VIDEO_H
