#pragma once
#include "Graphics.h"
#include "Frame.h"

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
	void drawE_terrorize(Graphics& gfx);
	void drawE_enter(Graphics& gfx);
	void drawE_pickup(Graphics& gfx);
public:
	int e_message = 1;
	static constexpr int terrorize = 0;
	static constexpr int enter = 1;
	static constexpr int pickup = 2;
private:
	Frame fwasd;
	Frame fe;
	Color cframe;
	const int wasd_x = 20;
	const int wasd_y = 20;
	const int wasd_width = 170;
	const int wasd_height = 100;
	const int e_x = wasd_x;
	const int e_y = wasd_y + wasd_height + 10;
	const int e_width = wasd_width;
	const int e_height = 40;
};