#ifndef GENERAL_H_
#define GENERAL_H_

#include "Setting.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class General {
public:
	General();
	General(string, string);
	~General();
	
	string get_language();
	string get_timeZone();
	void set_timeZone(string data);
	void set_language(string data);
private:
	string timeZone;
	string language;
};
#endif
