#pragma once
#include "Graphics.h"
#include "Frame.h"
#include "Vampire.h"
#include "Cactus.h"

class Desert
{
public:
	void process(Vampire& vamp,Graphics& gfx);
	void spawn(int x, int y, Vampire& vamp);
private:
	//drawing functions:
	void drawSand(Graphics& gfx);
	void placeCactuses(Vampire& vamp, Graphics& gfx);
private:
	Frame frame;
	Color csand;
	//cactuses
};