#ifndef VIDEODB_H
#define VIDEODB_H

#include <vector>

#include "video/video.h"

class VideoDB
{
public:
    VideoDB();

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
};

#endif // VIDEODB_H
