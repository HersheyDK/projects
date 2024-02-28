
#ifndef CHANNELLIST_H
#define CHANNELLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "defs.h"
#include "Channel.h"

using namespace std;

class ChannelList {
		
	public:
		//constructor
		ChannelList();
		
		//destructor
		~ChannelList();
		
		//other
		bool addChannel(Channel*);
		Channel* getChannel(const string& title) const;
		Channel* getChannel(int) const;
		Channel* removeChannel(const string& title);
		Channel* removeChannel(int);
		int size() const;
		void print() const;
		bool isFull() const;
	
	private:
		int numChannels;
		Channel** channels;
};
#endif
