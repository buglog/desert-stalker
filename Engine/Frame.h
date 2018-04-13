#pragma once
#include "Frog.h"

class Frame 
{
public:
	void init(int x0, int y0, int x1, int y1);
	void clamp(Frog& frog);
	void draw(int spacing, Color c, Graphics& gfx);
public:
	int x0 = 0;
	int y0 = 0;
	int x1 = 0;
	int y1 = 0;
}; 