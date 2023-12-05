#include <iostream>
#include "General.h"
#include "Display.h"
#include "Sound.h"
#include "Car.h"
#include "CommonInfo.h"
#include <fstream>
#include <string>
#include <regex>
#include <iomanip>
#include <sstream>


using namespace std;

Car** carList = new Car* [100];

int carListCount = 0;

vector<CommonInfo> timezoneList;
vector<string> languageList;

void NhapThongTinCaiDat();
void XuatThongTinCaiDat();

void XuatThongTinCaiDat_Sound();
void XuatThongTinCaiDat_General();
void XuatThongTinCaiDat_Display();
void XuatThongTatCaTinCaiDat();


void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
void NhapThongTinCaiDat_Display();

void downloadTimeZone();
void downloadLanguage();
void downloadCarList();
void uploadCarList();

bool isValidEmail(const std::string& email);
bool isValidEightDigitString(const string& input);
bool isDigit(string test);
int checkExistCar(string);
void inputCarSetting(Setting* &);
void sortCarListByName();
bool isBiggerName(string name1, string name2);

int main() {
	downloadLanguage();
	downloadTimeZone();
	downloadCarList();

	int selection = 0;

	while (1)
	{
		system("cls");
		cout << "--- SELECT MENU ---" << endl;
		cout << "1. Input setting information" << endl;
		cout << "2. Print setting information" << endl;
		cout << "0. Exit" << endl;
		cout << "Your selection: ";

		cin >> selection;

		if (selection == 1)
			NhapThongTinCaiDat();
		else if (selection == 2)
			XuatThongTinCaiDat();
		else if (selection == 0)
		{
			system("cls");
			break;
		}
		else {
			cout << endl << "Invalid ! Please try a gain ";
			system("pause");
			system("cls");
		}
	}
	return 0;
}


void NhapThongTinCaiDat() {
	char selection;
	
	while(1)
	{
		system("cls");
		cout << "--- SELECT MENU ---" << endl;
		cout << "1. Display setting" << endl;
		cout << "2. Sound setting" << endl;
		cout << "3. General setting" << endl;
		cout << "0. Exit" << endl;
		cout << "Your selection: ";
		
		cin >> selection;

		if (selection == '1') {
			// Your code
			
			NhapThongTinCaiDat_Display();			
		}
		else if (selection == '2') {
			NhapThongTinCaiDat_Sound();
		}
		else if (selection == '3') {
			NhapThongTinCaiDat_General();
		}
		else if (selection == '0') {
			system("cls");
			break;
		}
		else {
			cout << endl << "Invalid ! Please try a gain ";
			system("pause");
			system("cls");
		}
	}
}



void NhapThongTinCaiDat_Sound()
{
	while (1)
	{
		system("cls");
		cout << " --- Input Sound Setting --- " << endl;
		Setting* newCar;							//tao obj Setting de luu thong tin setting xe
		inputCarSetting(newCar);					//goi ham input de chuyen nhap thong tin setting xe 
		int index;
		if (carListCount == 0) {
			index = -1;
		}
		else
			index = checkExistCar(newCar->getPersonalKey());//kiem tra xem thong tin xe moi nhap vao da ton tai hay chua

		if (index != -1) { // truong hop neu trung thi sao chep setting luu vao o trung roi xoa bo nho dong da cap phat cho newCar

			carList[index]->setSetting(newCar->getCarName(), newCar->getPersonalKey(), newCar->getMail(), newCar->getODO(), newCar->getServiceRemind());// trong truong hop da trung key thi nap lai thong tin setting vao vi tri da co

			delete newCar;
			cout << "	->This care already existed, data will be overwritten" << endl;
			int med, cal, nav, noti;
			
			string test;
			while (1) {
				cout << "Media sound level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					med = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			while (1) {
				cout << "Call sound level:";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					cal = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			while (1) {
				cout << "Navigation sound level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					nav = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			while (1) {
				cout << "Notification sound level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					noti = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
						
			Sound newSound(med, cal, nav, noti);
			carList[index]->setSoudIF(newSound);
			cout << "Will you input for next car? ('y' to continue with new display setting, press any to go back) ";

			char continues;
			cin >> continues;
			if (continues == 'y') {}
			else {
				break;
			}
		}
		else {
			carList[carListCount] = new Car; // trong truong hop chua co thi tao 1 thong tin xe moi va nap du lieu vao listcar
			carList[carListCount]->setSetting(newCar->getCarName(), newCar->getPersonalKey(), newCar->getMail(), newCar->getODO(), newCar->getServiceRemind());
			delete newCar;
			cout << "	->This is new car, data will be appended to your list" << endl;
			int med, cal, nav, noti;
			string test;
			while (1) {
				cout << "Media sound level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					med = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			while (1) {
				cout << "Call sound level:";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					cal = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			while (1) {
				cout << "Navigation sound level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					nav = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			while (1) {
				cout << "Notification sound level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					noti = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			Sound newSound(med, cal, nav, noti);
			carList[carListCount]->setSoudIF(newSound);
			carListCount++;
			cout << "Will you input for next car? ('y' to continue with new display setting, press any to go back) ";

			char continues;
			cin >> continues;
			if (continues == 'y') {}
			else {
				break;
			}
		}
	}
	sortCarListByName();
	uploadCarList();
}

void NhapThongTinCaiDat_General()
{
	while (1)
	{
		system("cls");
		cout << " --- Input General Setting --- " << endl;
		Setting* newCar;							//tao obj Setting de luu thong tin setting xe
		inputCarSetting(newCar);					//goi ham input de chuyen nhap thong tin setting xe 
		int index;
		if (carListCount == 0) {
			index = -1;
		}
		else
			index = checkExistCar(newCar->getPersonalKey());//kiem tra xem thong tin xe moi nhap vao da ton tai hay chua

		if (index != -1) { // truong hop neu trung thi sao chep setting luu vao o trung roi xoa bo nho dong da cap phat cho newCar

			carList[index]->setSetting(newCar->getCarName(), newCar->getPersonalKey(), newCar->getMail(), newCar->getODO(), newCar->getServiceRemind());// trong truong hop da trung key thi nap lai thong tin setting vao vi tri da co

			delete newCar;
			
			cout << "	->This car already existed, data will be overwritten" << endl;

			string lan, time;
			
			cout << "--- Select language data --" << endl;
			for (int i = 0;i < languageList.size();i++) {
				cout << i + 1 << ": " << languageList[i] << endl;
			}
			while(1){
				cout << "Your selection: ";
				getline(cin, lan);
				if (isDigit(lan) == 1)
				{
					if (stoi(lan) > 0 && stoi(lan) < languageList.size() + 1)
						break;
					else
					{
						cout << "Invalid, please re-enter ! " << endl;
					}
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			
			cout << "--- Select timezone data ---" << endl;
			for (int i = 0;i < timezoneList.size();i++) {
				cout << i + 1 << ": " << timezoneList[i].getData() << endl;
			}

			while (1) {
				cout << "Your selection: ";
				getline(cin, time);
				if (isDigit(time) == 1)
				{
					if (stoi(time) > 0 && stoi(time) < timezoneList.size() + 1)
						break;
					else
					{
						cout << "Invalid, please re-enter ! " << endl;
					}
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}

			General newGeneral(languageList[stoi(lan)-1], timezoneList[stoi(time)-1].getData());
			carList[index]->setGeneralIF(newGeneral);
			cout << "Will you input for next car? ('y' to continue with new display setting, press any to go back) ";

			char continues;
			cin >> continues;
			if (continues == 'y') {}
			else {
				break;
			}
		}
		else {
			carList[carListCount] = new Car; // trong truong hop chua co thi tao 1 thong tin xe moi va nap du lieu vao listcar
			carList[carListCount]->setSetting(newCar->getCarName(), newCar->getPersonalKey(), newCar->getMail(), newCar->getODO(), newCar->getServiceRemind());
			delete newCar;
			cout << "	->This is new car, data will be appended to your list" << endl;
			string lan, time;

			cout << "--- Select language data --" << endl;
			for (int i = 0;i < languageList.size();i++) {
				cout << i + 1 << ": " << languageList[i] << endl;
			}
			while (1) {
				cout << "Your selection: ";
				getline(cin, lan);
				if (isDigit(lan) == 1)
				{
					if (stoi(lan) > 0 && stoi(lan) < languageList.size() + 1)
						break;
					else
					{
						cout << "Invalid, please re-enter ! " << endl;
					}
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}

			cout << "--- Select timezone data ---" << endl;
			for (int i = 0;i < timezoneList.size();i++) {
				cout << i + 1 << ": " << timezoneList[i].getData() << endl;
			}

			while (1) {
				cout << "Your selection: ";
				getline(cin, time);
				if (isDigit(time) == 1)
				{
					if (stoi(time) > 0 && stoi(time) < timezoneList.size() + 1)
						break;
					else
					{
						cout << "Invalid, please re-enter ! " << endl;
					}
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			General newGeneral(languageList[stoi(lan) - 1], timezoneList[stoi(time) - 1].getData());
			carList[carListCount]->setGeneralIF(newGeneral);
			carListCount++;
			cout << "Will you input for next car? ('y' to continue with new display setting, press any to go back) ";

			char continues;
			cin >> continues;
			if (continues == 'y') {}
			else {
				break;
			}
		}
	}
	sortCarListByName();
	uploadCarList();
}


void NhapThongTinCaiDat_Display()
{
	while(1)
	{
		system("cls");
		cout << " --- Input Display Setting --- " << endl;
		Setting* newCar;							//tao obj Setting de luu thong tin setting xe
		inputCarSetting(newCar);					//goi ham input de chuyen nhap thong tin setting xe 
		int index;
		if (carListCount == 0) {
			index = -1;
		}
		else
		 index = checkExistCar(newCar->getPersonalKey());//kiem tra xem thong tin xe moi nhap vao da ton tai hay chua

		if (index != -1) { // truong hop neu trung thi sao chep setting luu vao o trung roi xoa bo nho dong da cap phat cho newCar

			carList[index]->setSetting(newCar->getCarName(), newCar->getPersonalKey(), newCar->getMail(), newCar->getODO(), newCar->getServiceRemind());// trong truong hop da trung key thi nap lai thong tin setting vao vi tri da co
			
			delete newCar;
			
			cout << "	->This care already existed, data will be overwritten" << endl;
			int light, screen, taplo;
			string test;
			while (1) {
				cout << "Light level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					light = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			while (1) {
				cout << "Screen light level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					screen = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			while (1) {
				cout << "Taplo light level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					taplo = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
						
			Display newDisplay(light, screen, taplo);
			carList[index]->setDisplayIF(newDisplay);
			cout << "Will you input for next car? ('y' to continue with new display setting, press any to go back) "	;
			
			char continues;
			cin >> continues;
			if (continues == 'y') {}
			else {
				break;
			}
		}
		else {
			carList[carListCount] = new Car; // trong truong hop chua co thi tao 1 thong tin xe moi va nap du lieu vao listcar
			carList[carListCount]->setSetting(newCar->getCarName(), newCar->getPersonalKey(), newCar->getMail(), newCar->getODO(), newCar->getServiceRemind());
			delete newCar;
			cout << "	->This is new car, data will be appended to your list" << endl;
			int light, screen, taplo;
			string test;
			while (1) {
				cout << "Light level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					light = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			while (1) {
				cout << "Screen light level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					screen = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			while (1) {
				cout << "Taplo light level: ";
				getline(cin, test);
				if (isDigit(test) == 1)
				{
					taplo = stoi(test);
					break;
				}
				else
					cout << "Invalid, please re-enter ! " << endl;
			}
			Display newDisplay(light, screen, taplo);
			carList[carListCount]->setDisplayIF(newDisplay);
			carListCount++;
			cout << "Will you input for next car? ('y' to continue with new display setting, press any to go back) ";

			char continues;
			cin >> continues;
			if (continues == 'y') {}
			else {
				break;
			}
		}
	}
	sortCarListByName();
	uploadCarList();
}



void downloadTimeZone() {
	ifstream f;
	f.open("timezones.txt");
	// Your code
	string a;
	
	while (f.eof()== false) {
		getline(f, a);
		CommonInfo info;
		info.setData(a);
		string hour = a.substr(4, 6) + a.substr(8, 9);
		hour.erase(3, 1);
		info.setHour(stoi(hour)); // lay phan gio trong mui gio de sort lại list
		timezoneList.push_back(info);
	}
	f.close();

	//sort lai timezone theo mui gio
		int i, j, last;
		for (i = 1; i < timezoneList.size(); i++) {
			last = timezoneList[i].getHour();
			j = i;
			while ((j > 0) && (timezoneList[j - 1].getHour() > last)) {
				timezoneList[j].setHour(timezoneList[j - 1].getHour());
				j = j - 1;
			}
			timezoneList[j].setHour(last);
		} // end for
	
}

void downloadLanguage() {
	ifstream f;
	f.open("languages.txt");
	string a;
	while (f.eof() == false) {
		getline(f, a);		
		languageList.push_back(a);		
	}
	f.close();
	vector<string>::iterator p1 = languageList.begin();
	vector<string>::iterator p2 = languageList.end();
	sort(p1, p2);	// sort lai language theo alphabet
}

void downloadCarList() {
	
	ifstream myFile;	// cap nhat danh sach moi vao file binary
	
	myFile.open("data.txt");
	string buf1, buf2,buf3, buf4, buf5; // luu du lieu tam thoi kieu string
	
	if(myFile.is_open())
	{
		while (!myFile.eof()) {

			getline(myFile, buf1);
			getline(myFile, buf2);
			getline(myFile, buf3);
			getline(myFile, buf4);
			getline(myFile, buf5);
			
			carList[carListCount] = new Car;
			carList[carListCount]->setSetting(buf1, buf3, buf2, stoi(buf4), stoi(buf5));

			getline(myFile, buf1);
			getline(myFile, buf2);
			getline(myFile, buf3);
			
			Display dp(stoi(buf1), stoi(buf2), stoi(buf3));
			carList[carListCount]->setDisplayIF(dp);

			getline(myFile, buf1);
			getline(myFile, buf2);
			getline(myFile, buf3);
			getline(myFile, buf4);
			
			Sound sd(stoi(buf1), stoi(buf2), stoi(buf3), stoi(buf4));
			carList[carListCount]->setSoudIF(sd);

			getline(myFile, buf1);
			getline(myFile, buf2);
			
			General gen(buf1, buf2);
			carList[carListCount]->setGeneralIF(gen);
			carListCount++;
		}
		myFile.close();
	}

	
}

void XuatThongTinCaiDat() {
	while(1)
	{
		system("cls");
		cout << "--- SELECT MENU ---" << endl;
		cout << "1. Print Display setting information" << endl;
		cout << "2. Print Sound setting information" << endl;
		cout << "3. Print General setting information" << endl;
		cout << "4. Print all setting information" << endl;
		cout << "0. Exit" << endl;
		cout << "Your selection: ";

		char selection;
		cin >> selection;

		if (selection == '1') {
			XuatThongTinCaiDat_Display();
		}
		else if (selection == '2') {
			XuatThongTinCaiDat_Sound();
		}
		else if (selection == '3') {
			XuatThongTinCaiDat_General();
		}
		else if (selection == '4') {
			XuatThongTatCaTinCaiDat();
		}
		else if (selection == '0') {
			break;
		}
		else {
			cout << endl << "Invalid ! Please try a gain ";
			system("pause");
			system("cls");
		}
	}
}

void XuatThongTinCaiDat_Sound() {
	cout << setw(20) << "TEN CHU XE" << setw(25) << left << "Email" << setw(15) << left << "MSC" << setw(10) << left << "ODO" << setw(10) << left << "SEVICES" << setw(10) << left << "Media" << setw(10) << left << "Call" << setw(10) << left << "Navi" << setw(10) << left << "Notify" << endl;
	
	for (int i = 0; i < carListCount; i++)
	{
		cout << setw(20) << left << carList[i]->getCarName() << setw(25) << left << carList[i]->getMail() << setw(15) << left << carList[i]->getPersonalKey() << setw(10) << left << carList[i]->getODO() << setw(10) << left << carList[i]->getServiceRemind() << setw(10) << left << carList[i]->getSoudIF().get_media_level() << setw(10) << left << carList[i]->getSoudIF().get_call_level() << setw(10) << left << carList[i]->getSoudIF().get_navi_level() << setw(10) << left << carList[i]->getSoudIF().get_notification_level() << endl;
	}
	system("pause");
}

void XuatThongTinCaiDat_General() {
	cout << setw(20) << left << "TEN CHU XE" << setw(25) << left << "Email" << setw(15) << left << "MSC" << setw(10) << left << "ODO" << setw(15) << left << "SEVICES" << setw(15) << left << "TimeZone" << setw(15) << left << "Language" << endl;
	
	for(int i = 0; i < carListCount; i++)
	{
		cout << setw(20) << left << carList[i]->getCarName() << setw(25) << left << carList[i]->getMail() << setw(15) << left << carList[i]->getPersonalKey() << setw(10) << left << carList[i]->getODO() << setw(15) << left << carList[i]->getServiceRemind() << setw(15) << left << carList[i]->getGeneralIF().get_timeZone().substr(1,9) << setw(15) << left << carList[i]->getGeneralIF().get_language() << endl;
	}
	system("pause");
}

void XuatThongTinCaiDat_Display() {
	cout << setw(20) << left << "TEN CHU XE" << setw(25) << left << "Email" << setw(15) << left << "MSC" << setw(10) << left << "ODO" << setw(10) << left << "SEVICES" << setw(10) << left << "Light" << setw(10) << left << "Taplo" << setw(10) << left << "Screen" << endl;
	// Your code
	for (int i = 0; i < carListCount; i++)
	{
		cout << setw(20) << left << carList[i]->getCarName() << setw(25) << left << carList[i]->getMail() << setw(15) << left << carList[i]->getPersonalKey() << setw(10) << left << carList[i]->getODO() << setw(10) << left << carList[i]->getServiceRemind() << setw(10) << left << carList[i]->getDisplayIF().get_light_level() << setw(10) << left << carList[i]->getDisplayIF().get_taplo_light_level() << setw(10) << left << carList[i]->getDisplayIF().get_screen_light_level() << endl;
	}
	system("pause");
}

void XuatThongTatCaTinCaiDat() {
	// Your code
}

bool isValidEmail(const std::string& email) {  // Biểu thức chính quy để kiểm tra địa chỉ email
	
	std::regex emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");

	// Kiểm tra tính hợp lệ của địa chỉ email
	return std::regex_match(email, emailRegex);
}

bool isValidEightDigitString(const std::string& input) {  // Biểu thức chính quy để kiểm tra chuỗi chứa chính xác 8 số
	
	std::regex eightDigitRegex("^[0-9]{8}$");

	// Kiểm tra tính hợp lệ của chuỗi
	return std::regex_match(input, eightDigitRegex);
}

bool isDigit(string test) {
	std::regex numericRegex("^[0-9]+$");

	// Sử dụng hàm std::regex_match để kiểm tra
	return std::regex_match(test, numericRegex);
}

int checkExistCar(string key) {
	for (int i = 0; i < carListCount; i++) {
		if (key == carList[i]->getPersonalKey()) {
			return i;
		}
	}
	return -1;
}

void inputCarSetting(Setting* & newCar) {
	system("cls");
	
	string name;
	string mail;
	string key;
	int odo;
	int reS;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cout << "Owner name: ";
	getline(cin,name);
	while (1) { // tao vong while de check email
		cout  << "Email: ";
		getline(cin,mail);
		if (isValidEmail(mail))
			break;
		else
			cout << "Invalid email address, please re-enter ! " << endl;
	}

	while (1) { // tao vong while de check ma so ca nhan
		cout  << "Key number: ";
		getline(cin,key);
		if (isValidEightDigitString(key))
			break;
		else
			cout << "Invalid key number (8 digits), please re-enter ! " << endl;
	}
	string test;
	while (1){
		cout << "ODO number: ";
		getline(cin, test);
		if (isDigit(test) == 1)
		{
			odo = stoi(test);
			break;
		}
		else
			cout << "Invalid, please re-enter ! " << endl;
	}
	while (1) {
		cout << "Remind service (km): ";
		getline(cin, test);
		if (isDigit(test) == 1)
		{
			reS = stoi(test);
			break;
		}
		else
			cout << "Invalid, please re-enter ! " << endl;
	}
	
	newCar = new Car;
	newCar->setSetting(name, key, mail, odo, reS);
}

void uploadCarList() {
	ofstream myFile;	// cap nhat danh sach moi vao file binary
	
	myFile.open("data.txt");

	for (int i = 0; i < carListCount; i++) {
		myFile << carList[i]->getCarName() << endl;
		myFile << carList[i]->getMail() << endl;
		myFile << carList[i]->getPersonalKey() << endl;
		myFile << carList[i]->getODO() << endl;
		myFile << carList[i]->getServiceRemind() << endl;
		myFile << carList[i]->getDisplayIF().get_light_level() << endl;
		myFile << carList[i]->getDisplayIF().get_screen_light_level() << endl;
		myFile << carList[i]->getDisplayIF().get_taplo_light_level() << endl;
		myFile << carList[i]->getSoudIF().get_call_level() << endl;
		myFile << carList[i]->getSoudIF().get_media_level() << endl;
		myFile << carList[i]->getSoudIF().get_navi_level() << endl;
		myFile << carList[i]->getSoudIF().get_notification_level() << endl;
		myFile << carList[i]->getGeneralIF().get_language() << endl;
		if(i == carListCount-1)
			myFile << carList[i]->getGeneralIF().get_timeZone();
		else
			myFile << carList[i]->getGeneralIF().get_timeZone() << endl;
	}
	myFile.close();
}

void sortCarListByName() {
	int i, j;
	
	Car* temp;
	for (i = 1; i < carListCount; i++) {
		
		temp = carList[i];
		j = i;
		while ((j > 0) && isBiggerName(carList[j - 1]->getCarName() , temp->getCarName())) {
			carList[j]= carList[j - 1];
			j = j - 1;
		}
		carList[j] = temp;
	} // end for
}
bool isBiggerName(string name1, string name2) {
    stringstream n1(name1);
    stringstream n2(name2);
    
    vector<string> arr1; // tao vector string de luu name sau khi da dao nguoc lai
    vector<string> arr2;

    while (n1 >> name1) {

        arr1.push_back(name1);
    }
    while (n2 >> name2) {

        arr2.push_back(name2);
    }
    int len1 = arr1.size();
    int len2 = arr2.size();

    int minSize = (len1 > len2) ? len2 : len1;
    
    for (int i = 0; i < minSize; i++) {
        if (arr1[len1 - 1 - i] == arr2[len2 - 1 - i])
            continue;
        return (arr1[len1 - 1 - i] > arr2[len2 - 1 - i]);
    }

    if (arr1.size() > arr2.size())
        return true;
    return false;

}