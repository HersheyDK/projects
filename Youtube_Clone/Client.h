
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "defs.h"
#include "ViewTube.h"

using namespace std;

class Client {
		
	public:
		//constructor
		Client(const string& name);
		
		//destructor
		~Client();
		
		//other
		bool download(ViewTube& viewTube, int index);

		void print() const;
        void printChannel() const;
		void play(int index) const;
	
	private:
        string name;
		Channel* channel;

};
#endif
