
#ifndef VIEWTUBE_H
#define VIEWTUBE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "defs.h"
#include "ChannelList.h"

using namespace std;

class ViewTube {
		
	public:
		//constructor
		ViewTube();
		
		//destructor
		~ViewTube();
		
		//other
		void addChannel(const string& title, const string& owner);
		void deleteChannel(int index);
		int getNumChannel() const;
		bool download(int index, Channel** channel);
        Channel* getChannel(int index) const;

        void addVideo(const string& channel, const string& title, const string& content, const Date& date);
        void deleteVideo(int channelIndex, int videoIndex);

		void printChannels() const;
        void printChannel(int index) const;
		void playVideo(int channelIndex, int videoIndex) const;
	
	private:
		ChannelList* channelList;
};
#endif
