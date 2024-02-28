#include "Client.h"

Client::Client(const string& name){
    this->name = name;
    channel = nullptr;
}

Client::~Client(){
    delete channel;
}

bool Client::download(ViewTube& viewTube, int index){
    if (index < 0 || index >= viewTube.getNumChannel()){
        return false;
    }
    Channel* originalChannel = viewTube.getChannel(index);
    Channel* newChannel = new Channel(*originalChannel);
    if (channel != nullptr) {
        delete channel;
    }
    channel = newChannel;
    return true;
}

void Client::print() const{
    if (channel != nullptr) {
        cout << "Client name " << name << endl;
        channel->print();
        cout << endl;
    }
}

void Client::printChannel() const{
    if (channel != nullptr) {
        channel->print();
        channel->printVideos();
    }
}

void Client::play(int index) const{
    if (channel != nullptr) {
        channel->playVideo(index);
    }
}