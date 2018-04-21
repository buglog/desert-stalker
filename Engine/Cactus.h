#pragma once
#include "Vampire.h"
#include "Wall.h"

class Cactus
{
public:
	void init(int setx, int sety, int setVersion);
	void place(Graphics& gfx,Vampire& vampire);
private:
	void drawVer0(Graphics& gfx);
	void drawVer1(Graphics& gfx);
	void drawVer2(Graphics& gfx);
	Wall wallVer0;
private:
	int version = 0;
	int x = 0;
	int y = 0;
	int width  = 24;
	int height = 42;
};