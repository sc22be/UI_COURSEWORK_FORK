#ifndef VIDEODB_H
#define VIDEODB_H

#include <vector>
#include <QDir>

#include "video/video.h"

class VideoDB
{
public:
    VideoDB(std::string path_to_videos);

    /**
     * @brief Gets videos to display on home page
     * @return A vector of videos to display
     */
    std::vector<Video> GetVideos();

    /**
     * @brief Gets videos uploaded by the user
     * for displaying on the profile page
     * @return A vector of videos to display
     */
    std::vector<Video> GetUserVideos();
private:

    std::string m_PathToVideos;

    std::vector<Video> m_Videos;
    std::vector<Video> m_UserVideos;
};

#endif // VIDEODB_H
