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
	void drawInFront(Vampire& vamp, Graphics& gfx);
private:
	void changeStage(Vampire& vamp);
	//drawing functions:
	void drawSand(Graphics& gfx);
	void process_A1(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg);
	void process_A2(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg);
	void process_B1(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg);
	void process_B2(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg);
private:
	int grid_x = 1;
	int grid_y = 1;
	int gridDimX = 2;
	int gridDimY = 2;
	Cactus cact_A1[6];
	Cactus cact_A2[9];
	Cactus cact_B1[5];
	Cactus cact_B2[15];
	Frame frame;
	Color cframe;
	Color csand;
	//cactuses
};