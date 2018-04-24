#pragma once
#include "Vampire.h"
#include "Wall.h"
#include "Instructions.h"
#include "Message.h"
#include "ProgressBar.h"

class Cactus
{
public:
	void init(int setx, int sety, int setVersion);
	void place(Graphics& gfx,Vampire& vamp,Instructions& inst,Message& msg,ProgressBar& terrorBar);
	Wall cWall;
	void drawInFront(Graphics& gfx, Vampire& vamp);
private:
	void update(Vampire& vamp, Instructions& inst, Message& mgs, ProgressBar& terrorBar);
	void turnWhite();
	void drawVer0(Graphics& gfx);
	void drawVer1(Graphics& gfx);
	void drawVer2(Graphics& gfx);
private:
	bool isScared = false;
	bool canBeScared = true;
	Color c;
	int colCounter = 0;
	bool turningWhite = false;
	//white speed is faster the higher the number.
	int turnWhiteSpeed = 20;
	//green speed is faster the lower the number.
	int turnGreenSpeed = 10;
	int setr = 180;
	int setg = 210;
	int setb = 70;
	int r = 0;
	int g = 0;
	int b = 0;
	int version = 0;
	int nVersions = 3;
	int x = 0;
	int y = 0;
	int yOffset = -30;
	int xOffset = -20;
	//y_draw = y + yOffset, initialized in init
	int y_draw = 0;
	int x_draw = 0;
	int width  = 30;
	int height = 20;
	int scareRange = 40;
	//int trueHeight = 50;
};