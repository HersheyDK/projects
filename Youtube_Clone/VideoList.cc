
#include "VideoList.h"

VideoList::VideoList(){
	numPods = 0;
	videos = new Video*[MAX_VIDS];
}

VideoList::VideoList(const VideoList& other) {
    numPods = other.numPods;
    videos = new Video*[MAX_VIDS];
    for(int i = 0; i < numPods; i++) {
        videos[i] = new Video(*other.videos[i]);  // Deep copy
    }
}


VideoList::~VideoList(){
    for(int i = 0; i < numPods; i++) {
        delete videos[i];
		videos[i] = nullptr;
    }
    delete[] videos;
}

bool VideoList::addVideo(Video* p){
    if (numPods >= MAX_VIDS) return false;
    int i = numPods++;
    while (i > 0 && p->lessThan(*videos[i-1])){
        videos[i] = videos[i-1];
        --i;
    }
    videos[i] = p;
	// for (int x = 0; x < numPods; x++) {
	// 	videos[x]->print();
	// }
    return true;
}

Video* VideoList::removeVideo(const string& title){
	Video* goner = nullptr;
	bool found = false;
	for (int i = 0; i < numPods; ++i){
		if (title == videos[i]->getTitle()){
			goner = videos[i];
			found = true;
		}
		if (found && i < numPods-1){
			videos[i]=videos[i+1];
		}
	}
	if (found) --numPods; 
	return goner;
}

Video* VideoList::removeVideo(int index){
	if (index < 0 || index >= numPods) return nullptr;
	Video* goner = videos[index];
	for (int i = index; i < numPods-1; ++i){
		videos[i] = videos[i+1];
	}
	--numPods;
	return goner;
}

Video* VideoList::getVideo(const string& title)const {
	for (int i = 0; i < numPods; ++i){
		if (title == videos[i]->getTitle()){
			return videos[i];
		}
	}
	return nullptr;
}

Video* VideoList::getVideo(int index)const {
	if (index < 0 || index >= numPods) return nullptr;
	return videos[index];
}



int VideoList::size()const{
	return numPods;
}

void VideoList::print()const{
	for (int i = 0; i < numPods; ++i){
		videos[i]->print();
	}
}
