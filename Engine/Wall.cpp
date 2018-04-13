#include "Wall.h"

void Wall::init(int setx0,int sety0,int setx1,int sety1, Color& setc, int setSpacing)
{
	x0 = setx0;
	y0 = sety0;
	x1 = setx1;
	y1 = sety1;
	c = setc;
	spacing = setSpacing;
}

void Wall::block(Frog & frog)
{
	//top (floor)
	if (frog.x + frog.width > x0 + 1 &&
		frog.x < x1	- 1			     &&
		frog.y + frog.height > y0    &&
		frog.y < y0 + 5)
	{
		frog.y = y0 - frog.height;
		frog.onGround = true;
	}
	//bottom
	else if (frog.x + frog.width > x0 + 1  &&
			 frog.x < x1	- 1			   &&
			 frog.y + frog.height > y1 - 1 &&
			 frog.y < y1)
	{
		frog.y = y1 + 1;
		frog.vy = 0;
	}
	//left side
	else if (frog.y + frog.height >= y0 &&
			 frog.y <= y1				    &&
			 frog.x + frog.width >= x0		&&
			 frog.x < x0 + 5)
	{
		frog.x = x0 - frog.width;
		frog.vx = 0;
	}
	//right side
	else if (frog.y + frog.height >= y0  &&
			 frog.y <= y1 				 &&
			 frog.x <= x1				 &&
			 frog.x + frog.width > x1 - 5)
	{
		frog.x = x1;
		frog.vx = 0;
	}
}

void Wall::draw(Graphics & gfx)
{
	gfx.Rectangle(x0, y0, x1, y1, spacing, c);
}
