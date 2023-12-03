#pragma once
#include "Setting.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"

using namespace  std;
class Car : public Setting
{
private:
	Display display;
	Sound sound;
	General general;

public:
	Car();
	~Car();

	void setDisplayIF(Display);
	void setSoudIF(Sound);
	void setGeneralIF(General);
	Display getDisplayIF();
	Sound getSoudIF();
	General getGeneralIF();
};

