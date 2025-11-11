#ifndef CIRCULARTEMPLATEDLIST_SONG_H
#define CIRCULARTEMPLATEDLIST_SONG_H

#include <iostream>
#include "Media.h"

class Song : public Media {
private:
    std::string artist;

public:
    Song(const std::string& t, const std::string& a, int d)
            : Media(t, d), artist(a) {}

    std::string getArtist() const { return artist; }

    std::string toString() const override {
        int minutes = durationSeconds / 60;
        int seconds = durationSeconds % 60;
        return "Song: " + title + " | Artist: " + artist + " | Duration: " +
               std::to_string(minutes) + "m " + std::to_string(seconds) + "s";
    }

    void play() const override {
        std::cout << "🎵 Now playing: " << title << " by " << artist << " 🎵" << std::endl;
    }
};

#endif // CIRCULARTEMPLATEDLIST_SONG_H