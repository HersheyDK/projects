
#include "ChannelList.h"

ChannelList::ChannelList(){
	numChannels = 0;
	channels = new Channel*[MAX_CHANNELS];
}


ChannelList::~ChannelList(){
	for (int i = 0; i < numChannels; i++){
		delete channels[i];
		channels[i] = nullptr;
	}
	delete[] channels;

}

bool ChannelList::addChannel(Channel* p){
	if (numChannels >= MAX_CHANNELS) return false;
	
	channels[numChannels] = p;
	++numChannels;

	return true;
}

// This is not an ideal implementation.
// If more than one video has the same title it will remove
// the last one only.
Channel* ChannelList::removeChannel(const string& title){
	Channel* goner = nullptr;
	bool found = false;
	for (int i = 0; i < numChannels; ++i){
		if (title == channels[i]->getTitle()){
			goner = channels[i];
			found = true;
		}
		if (found && i < numChannels-1){
			channels[i]=channels[i+1];
		}
	}
	if (found) --numChannels; 
	return goner;
}

Channel* ChannelList::removeChannel(int index){
	if (index < 0 || index >= numChannels) return nullptr;
	Channel* goner = channels[index];
	for (int i = index; i < numChannels-1; ++i){
		channels[i] = channels[i+1];
	}
	--numChannels;
	return goner;
}

Channel* ChannelList::getChannel(const string& title)const {
	for (int i = 0; i < numChannels; ++i){
		if (title == channels[i]->getTitle()){
			return channels[i];
		}
	}
	return nullptr;
}

Channel* ChannelList::getChannel(int index)const {
	if (index < 0 || index >= numChannels) return nullptr;
	return channels[index];
}



int ChannelList::size() const{
	return numChannels;
}

void ChannelList::print() const{
	for (int i = 0; i < numChannels; ++i){
		channels[i]->print();
	}
}

bool ChannelList::isFull() const{
	return numChannels == MAX_CHANNELS;
}
