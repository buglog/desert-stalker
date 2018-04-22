#pragma once
#include "Vampire.h"
#include "Wall.h"

class Cactus
{
public:
	void init(int setx, int sety, int setVersion);
	void place(Graphics& gfx,Vampire& vamp);
	Wall cWall;
private:
	void update(Vampire& vamp);
	void turnWhite();
	void drawVer0(Graphics& gfx);
	void drawVer1(Graphics& gfx);
	void drawVer2(Graphics& gfx);
private:
	bool isScared = false;
	Color c;
	int colCounter = 0;
	bool turningWhite = false;
	//white speed is faster the higher the number.
	//green speed is faster the lower the number.
	int turnWhiteSpeed = 10;
	int turnGreenSpeed = 2;
	int r = 180;
	int g = 210;
	int b = 70;
	int version = 0;
	int nVersions = 3;
	int x = 0;
	int y = 0;
	int width  = 30;
	int height = 50;
	int scareRange = 50;
	//int trueHeight = 50;
};