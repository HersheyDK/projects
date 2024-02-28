#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Video {
    public:
        Video(const string& title, const string& content, const Date& date);
        bool lessThan(const Video& video) const;
        void print() const;
        string getTitle() const;
        void play() const;
    private:
        string title;
        string content;
        Date date;
};

#endif