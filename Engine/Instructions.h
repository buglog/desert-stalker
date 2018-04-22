#pragma once
#include "Graphics.h"
//Instructions.h will go in Game.h. It has to include desert because desert will contain the bools that change the instruction on the screen. 
#include "Desert.h"

class Instructions
{	//it's maybe a bad name for this class, but this is for the instructions which will display on the screen when you can interact with something.
public:
	Instructions();
	void draw(Graphics& gfx);
private:
	void drawWASD(Graphics& gfx);
	//draw "E: scare"
	void drawE(Graphics& gfx);
private:
	void drawE_scare(Graphics& gfx);
	void drawE_enter(Graphics& gfx);
	void drawE_pickup(Graphics& gfx);
private:
	Frame fwasd;
	Frame fe;
	Color cframe;
	int wasd_x = 20;
	int wasd_y = 20;
	int wasd_width = 170;
	int wasd_height = 100;
	int e_x = wasd_x;
	int e_y = wasd_y + wasd_height + 10;
	int e_width = wasd_width;
	int e_height = 60;
};