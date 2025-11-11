#ifndef CIRCULARTEMPLATEDLIST_PODCAST_H
#define CIRCULARTEMPLATEDLIST_PODCAST_H

#include <iostream>
#include <sstream>
#include "Media.h"

class Podcast : public Media {
private:
    std::string host;
    int episodeNumber;

public:
    Podcast(const std::string& t, const std::string& h, int epNum)
            : Media(t, 0), host(h), episodeNumber(epNum) {}

    std::string toString() const override {
        std::stringstream ss;
        ss << "Podcast: " << title << " | Host: " << host << " | Ep #: " << episodeNumber;
        return ss.str();
    }

    void play() const override {
        std::cout << "🎙️ Playing episode " << episodeNumber << ": " << title
                  << " hosted by " << host << " 🎙️" << std::endl;
    }
};

#endif // CIRCULARTEMPLATEDLIST_PODCAST_H