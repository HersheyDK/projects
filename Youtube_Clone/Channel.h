#ifndef CHANNEL_H
#define CHANNEL_H

#include <iostream>
#include <string>
#include "Date.h"
#include "VideoList.h"
#include "defs.h"

using namespace std;

class Channel {
    public:
        Channel(const string& title, const string& owner);
        ~Channel();
        Channel(const Channel& channel);

        // getters
        string getTitle() const;
        string getOwner() const;
        int getNumVideos() const;
        Video* getVideo(int index) const;

        //less than
        bool lessThan(const Channel& channel) const;

        //Add/remove video
        bool addVideo(const string& title, const string& content, const Date& date);
        bool addVideo(Video* video);
        bool removeVideo(int index);

        void playVideo (int index) const;

        //print functions
        void print() const;
        void printVideos() const;

    private:
        string title;
        string owner;
        int numVideos;
        VideoList* videoList;
};

#endif