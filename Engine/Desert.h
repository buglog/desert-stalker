#pragma once
#include "Graphics.h"
#include "Frame.h"
#include "Vampire.h"
#include "Cactus.h"
#include "Message.h"

class Desert
{
public:
	Desert(Vampire& vamp);
	void process(Vampire& vamp,Graphics& gfx, Instructions& inst, Message& msg);
	void spawn(int x, int y, Vampire& vamp);
private:
	void changeStage(Vampire& vamp);
	//drawing functions:
	void drawSand(Graphics& gfx);
	void drawA1(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg);
	void drawA2(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg);
	void drawB1(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg);
	void drawB2(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg);
private:
	int grid_x = 0;
	int grid_y = 0;
	int gridDimX = 2;
	int gridDimY = 2;
	Cactus cact_A1[6];
	Frame frame;
	Color cframe;
	Color csand;
	//cactuses
};