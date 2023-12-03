#include "Car.h"

Car::Car(){}

Car::~Car(){
	
}

void Car::setDisplayIF(Display dp) {
	display = dp;
}

void Car::setSoudIF(Sound sd) {
	sound = sd;
}

void Car::setGeneralIF(General gen) {
	general = gen;
}

Display Car::getDisplayIF() {
	return display;
}

Sound Car::getSoudIF() {
	return sound;
}

General Car::getGeneralIF() {
	return general;
}