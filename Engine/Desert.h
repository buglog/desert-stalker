#pragma once
#include "Graphics.h"
#include "Frame.h"
#include "Vampire.h"
#include "Cactus.h"

class Desert
{
public:
	Desert();
	void process(Vampire& vamp,Graphics& gfx, Instructions& inst);
	void spawn(int x, int y, Vampire& vamp);
private:
	//drawing functions:
	void drawSand(Graphics& gfx);
	void placeCactuses(Vampire& vamp, Graphics& gfx, Instructions& inst);
private:
	Cactus c0;
	Frame frame;
	Color cframe;
	Color csand;
	//cactuses
};