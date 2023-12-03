#include "Sound.h"

Sound::Sound(){
	// Your code
	media_level = 0;
	call_level = 0;
	notification_level = 0;
	navi_level = 0;
}

Sound::Sound(int med, int cal, int noti, int navi) {
	// Your code
	media_level = med;
	call_level = cal;
	notification_level = noti;
	navi_level = navi;
}
Sound::~Sound(){}



int Sound::get_media_level(){
	// Your code
	return media_level;
}

int Sound::get_call_level(){
	// Your code
	return call_level;
}

int Sound::get_navi_level(){
	// Your code
	return navi_level;
}

int Sound::get_notification_level(){
	// Your code
	return  notification_level;
}

void Sound::set_media_level(int data){
	// Your code
	media_level = data;
}

void Sound::set_call_level(int data){
	// Your code
	call_level = data;
}

void Sound::set_navi_level(int data){
	// Your code
	navi_level = data;
}

void Sound::set_notification_level(int data){
	// Your code
	notification_level = data;
}

