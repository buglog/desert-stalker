#pragma once
#include "Graphics.h"
#include "Frame.h"
#include "Vampire.h"
#include "Cactus.h"
#include "Message.h"
#include "CowboyHat.h"

class Desert
{
public:
	Desert(Vampire& vamp);
	void process(Vampire& vamp,Graphics& gfx, Instructions& inst, Message& msg,ProgressBar& terrorBar);
	void spawn(int x, int y, Vampire& vamp);
	void drawInFront(Vampire& vamp, Graphics& gfx);
public:
	bool canDrawHat = false;
private:
	void changeStage(Vampire& vamp);
	//drawing functions:
	void drawSand(Graphics& gfx);
	void process_A1(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg, ProgressBar& terrorBar);
	void process_A2(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg, ProgressBar& terrorBar);
	void process_B1(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg, ProgressBar& terrorBar);
	void process_B2(Vampire& vamp, Graphics& gfx, Instructions& inst, Message& msg, ProgressBar& terrorBar);
private:
	int grid_x = 0;
	int grid_y = 0;
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