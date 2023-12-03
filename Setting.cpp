#include "Setting.h"

Setting::Setting()
{
	// Your code
}

Setting::~Setting(){}

void Setting::setSetting(string name, string key, string mail, int od, int svrm){
	// Your code
	car_name = name;
	personal_key = key;
	email = mail;
	odo = od;
	service_remind = svrm;
}



string Setting::getCarName() {
	// Your code
	return car_name;
}

string Setting::getPersonalKey() {
	// Your code
	return personal_key;
}

string Setting::getMail() {
	return email;
}

int Setting::getODO() {
	// Your code
	return odo;
}

int Setting::getServiceRemind() {
	// Your code
	return service_remind;
}

