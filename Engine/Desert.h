#pragma once
#include "Graphics.h"
#include "Frame.h"
#include "Vampire.h"
#include "Cactus.h"
#include "Message.h"

class Desert
{
public:
	Desert();
	void process(Vampire& vamp,Graphics& gfx, Instructions& inst, Message& msg);
	void spawn(int x, int y, Vampire& vamp);
private:
	//drawing functions:
	void drawSand(Graphics& gfx);
	void placeCactuses(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg);
private:
	Cactus c0;
	Cactus c1;
	Cactus c2;
	Cactus c3;
	Cactus c4;
	Cactus c5;
	Frame frame;
	Color cframe;
	Color csand;
	//cactuses
};