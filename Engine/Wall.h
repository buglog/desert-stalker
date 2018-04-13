#pragma once
#include "Frog.h"
#include "Graphics.h"


class Wall
{// pass frog through like so: wall0.block(frog);
 // and then draw lines over top.
public:
	void init(int setx0, int sety0, int setx1, int sety1, Color& setc, int setSpacing);
	void block(Frog& frog);
	void draw(Graphics& gfx);
public:
	int x0 = 0;
	int y0 = 0;
	int x1 = 0;
	int y1 = 0;
	int spacing = 0;
	Color c;
};