#include "ViewTube.h"

ViewTube::ViewTube(){
    channelList = new ChannelList();
}

ViewTube::~ViewTube(){
    delete channelList;
}

void ViewTube::addChannel(const string& title, const string& owner){
    Channel* newChannel = new Channel(title, owner);
    channelList->addChannel(newChannel);
}


void ViewTube::deleteChannel(int index){
    Channel* goner = channelList->getChannel(index);
    if (goner == nullptr){
        cout << "Channel does not exist" << endl;
        return;
    }

    channelList->removeChannel(index);
    delete goner; 
}

int ViewTube::getNumChannel() const{
    return channelList->size();
}

Channel* ViewTube::getChannel(int index) const{
    return channelList->getChannel(index);
}


bool ViewTube::download(int index, Channel** channel){
    if (index < 0 || index > MAX_CHANNELS){
        return false;
    }
    *channel = channelList->getChannel(index);
    return true;
}

void ViewTube::addVideo(const string& channel, const string& title, const string& content, const Date& date){
    if (channelList->size() < MAX_CHANNELS){
        for (int i = 0; i < channelList->size(); i++){
            if (channelList->getChannel(i)->getTitle() == channel){
                channelList->getChannel(i)->addVideo(title, content, date);
                return;
            }
        }
        cout << "Channel does not exist" << endl;
    }
}

void ViewTube::deleteVideo(int channelIndex, int videoIndex){
    if (channelIndex < 0 || channelIndex >= channelList->size() || videoIndex < 0 || videoIndex >= channelList->getChannel(channelIndex)->getNumVideos()){
        cout << "Channel or Video does not exist" << endl;
        return;
    }
    if (!channelList->getChannel(channelIndex)->removeVideo(videoIndex)){
        cout<< "Unsuccessful Deletion" << endl;
        return;
    }
    return;
}

void ViewTube::printChannel(int index) const{
    if (index < 0 || index > channelList->size()){
        cout<< "Channel out of bounds" << endl;
        return;
    }
    channelList->getChannel(index)->print();
    cout << endl;
    channelList->getChannel(index)->printVideos();
    cout << endl;
}

void ViewTube::printChannels() const{
    for (int i = 0; i < channelList->size(); i++){
        cout << i << ") ";
        channelList->getChannel(i)->print();
        cout << endl;
    }
}

void ViewTube::playVideo(int channelIndex, int videoIndex) const{
    if (channelIndex < 0 || channelIndex >= channelList->size()) {
        cout<<"Invalid channel index"<<endl;
        return;
    }

    Channel* channel = channelList->getChannel(channelIndex);
    if (!channel || videoIndex < 0 || videoIndex >= channel->getNumVideos()) {
        cout<<"Invalid video index"<<endl;
        return;
    }

    Video* video = channel->getVideo(videoIndex);
    if (!video) {
        cout<<"Video not found"<<endl;
        return;
    }

    video->play();
}