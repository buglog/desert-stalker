#pragma once
#include "Frog.h"
#include "WorldObj.h"

class Frame 
{
public:
	void init(int x0, int y0, int x1, int y1);
	void offset(Frog& frog);
	void offset(World::Wall& wall);
	//call offset functions before clamp func.
	void offset(World::Spike& spike);
	void clamp(Frog& frog);
	void draw(int spacing, Color c, Graphics& gfx);
public:
	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;
}; 