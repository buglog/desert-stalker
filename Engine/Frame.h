#pragma once
#include "Vampire.h"
#include "Wall.h"
#include "Spike.h"

class Frame 
{
public:
	void init(int x0, int y0, int x1, int y1);
	//call offset functions before clamp func.
	void offset(Vampire& vamp);
	void offset(Wall& wall);
	void offset(Spike& spike);
	void clamp(Vampire& vamp);
	void draw(int spacing, Color c, Graphics& gfx);
public:
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
}; 