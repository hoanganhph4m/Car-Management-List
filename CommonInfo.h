#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class CommonInfo{
public:
	int getHour() {
		return hour;	
	}
		
	string getData() {
		return data;
	}
	void setHour(int hr) {
		hour = hr;	
	}
		
	void setData(string dt){
		data = dt;
	}
	
private:
	int hour;
	
	string data;		
};

#endif // COMMON_H_
