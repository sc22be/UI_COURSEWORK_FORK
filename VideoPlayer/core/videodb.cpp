#include "videodb.h"

VideoDB::VideoDB()
{

}

std::vector<Video> VideoDB::GetVideos()
{
    std::vector<Video> videos;
    videos.push_back(Video("test", QDateTime::currentDateTime()));

    return videos;
}

std::vector<Video> VideoDB::GetUserVideos()
{
    // Return an empty vector for now
    return std::vector<Video>();
}
