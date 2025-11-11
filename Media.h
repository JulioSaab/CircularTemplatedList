#ifndef CIRCULARTEMPLATEDLIST_MEDIA_H
#define CIRCULARTEMPLATEDLIST_MEDIA_H

#include <string>

class Media {
protected:
    std::string title;
    int durationSeconds;

    // Protected constructor for derived classes
    Media(const std::string& t, int d) : title(t), durationSeconds(d) {}

public:
    virtual ~Media() = default;

    virtual std::string toString() const = 0;
    virtual void play() const = 0;

    // Accessors
    std::string getTitle() const { return title; }
    void setTitle(const std::string& t) { title = t; }
    int getDuration() const { return durationSeconds; }
    void setDuration(int d) { durationSeconds = d; }
};

#endif // CIRCULARTEMPLATEDLIST_MEDIA_H