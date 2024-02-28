#include "Channel.h"

using namespace std;

Channel::Channel(const string& title, const string& owner){
    this->title = title;
    this->owner = owner;
    numVideos = 0;
    videoList = new VideoList();
}

Channel::Channel(const Channel& channel){
    this->title = channel.title;
    this->owner = channel.owner;
    this->numVideos = channel.numVideos; 
    this->videoList = new VideoList(*channel.videoList);
}

Channel::~Channel(){
    delete videoList;
}


// getter
string Channel::getTitle()const{
    return title;
}

string Channel::getOwner()const{
    return owner;
}

int Channel::getNumVideos()const{
    return numVideos;
}

Video* Channel::getVideo(int index)const{
    return videoList->getVideo(index);
}

//less than function
bool Channel::lessThan(const Channel& channel) const{
    if (this->title < channel.title){
        return true;
    }
    else {
        return false;
    }
}

bool Channel::addVideo(const string& title, const string& content, const Date& date){
    if (numVideos >= MAX_VIDS){
        return false;
    }
    Video* newVideo = new Video(title, content, date);
    videoList->addVideo(newVideo);
    numVideos++;
    return true;
}

bool Channel::addVideo(Video* video){
    if (numVideos >= MAX_VIDS){
        return false;
    }
    videoList->addVideo(video);
    return true;
}


bool Channel::removeVideo(int index){
    if (index < 0 || index > getNumVideos()) return false;
    cout << "Removing: ";
    Video* videoToRemove = videoList->removeVideo(index);
    videoToRemove->print();
    delete videoToRemove;  // Delete the Video object
    cout << endl;
    numVideos--;
    return true;
}

// print functions
void Channel::print()const{
    cout << "Channel Title: " << title << endl;
    cout << "Channel Owner: " << owner << endl;
}

void Channel::printVideos()const{
    print();
    for (int i = 0; i < getNumVideos(); i++){
        cout << i << ")";
        videoList->getVideo(i)->print();
        cout << endl;
    }
}

void Channel::playVideo(int index)const{
    if (index < 0 || index > getNumVideos()) {
        cout << "Index out of range" << endl;
        return;
    }
    videoList->getVideo(index)->play();
}