#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Setting {
public:
	Setting();
	~Setting();
	

	
	void setSetting(string, string ,string, int, int);
	
	string getCarName();
	string getPersonalKey();
	string getMail();
	int getODO();
	int getServiceRemind();

private:
	string car_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;
};
#endif /* SETTING_H_ */

