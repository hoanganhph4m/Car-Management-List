#include "General.h"
#include "CommonInfo.h"

General::General()
{
	// Your code
	language = " ";
	timeZone = " ";
}

General::General(string lan, string time) {
	language = lan;
	timeZone = time;
}
General::~General(){}



string General::get_language(){
	// Your code
	return language;
}

string General::get_timeZone(){
	// Your code
	return timeZone;
}

void General::set_timeZone(string data){
	// Your code
	timeZone = data;
}

void General::set_language(string data){
	// Your code
	language = data;
}
