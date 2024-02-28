#include "Video.h"

using namespace std;

Video::Video(const string& title, const string& content, const Date& date){
    this->title = title;
    this->content = content;
    this->date = date;
}

// getter
string Video::getTitle() const{
    return title;
}

//less than function
bool Video::lessThan(const Video& video) const{
    return this->date.lessThan(video.date);
}

// print functions
void Video::print() const{
    cout << "Video Title: " << title << endl;
    cout << "Date Released: ";
    date.print();
    cout << endl;
}

void Video::play() const{
    cout << content << endl;
}