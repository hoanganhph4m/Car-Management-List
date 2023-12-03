#include "Display.h"

Display::Display()
{
	// Your code
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
}
Display::Display(int l, int s, int t) {
	light_level = l;
	screen_light_level = s;
	taplo_light_level = t;
}

Display::~Display(){}

int Display::get_light_level(){
	// Your code
	return light_level;
}

int Display::get_screen_light_level(){
	// Your code
	return  screen_light_level;
}

int Display::get_taplo_light_level() {
	// Your code
	return taplo_light_level;
}
void Display::set_light_level(int data){
	// Your code
	light_level = data;
}

void Display::set_screen_light_level(int data){
	// Your code
	screen_light_level = data;
}

void Display::set_taplo_light_level(int data){
	// Your code
	taplo_light_level = data;
}



