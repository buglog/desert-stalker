#include "Wall.h"

void Wall::init(int setx0, int sety0, int setx1, int sety1, Color setc, int setSpacing)
{
	x0 = setx0;
	y0 = sety0;
	x1 = setx1;
	y1 = sety1;
	c = setc;
	spacing = setSpacing;
}

void Wall::block(Vampire& vamp)
{
	//set the block axis.
	if (vamp.y + vamp.height >= y0 && vamp.y <= y1 &&
		(vamp.x + vamp.width <= x0 || vamp.x >= x1))
	{
		rangeY = false;
	}
	if (vamp.x + vamp.width >= x0 && vamp.x <= x1 && 
		//make sure it only tests if vamp is already outside of the box.
		(vamp.y + vamp.height <= y0 || vamp.y >= y1))
	{
		rangeY = true;
	} 
	const int wallHeight = y1 - y0;
	const int wallWidth = x1 - x0;
	if (rangeY)
	{
		//if vamp is in top half of box, push to top.
		//if vamp is in bottom half of box, push down.
		if (vamp.y + vamp.height >= float(y0) &&
			//this one has >=, but the other one doesn't. NO OVERLAP! even by one pixel. 
			//this is important in case you want to make thin walls for some reason.
			vamp.y + (vamp.height/2.0f) <= float (y0 + (wallHeight/2)))
		{
			vamp.y = float(y0) - vamp.height;
			vamp.vy = 0.0f;
		}
		else if (vamp.y <= y1 &&
			vamp.y + (vamp.height / 2.0f) > float(y0 + (wallHeight / 2)))
		{
			vamp.y = float(y1);
			vamp.vy = 0.0f;
		}
	}
	else //test sides
	{
		if (vamp.x + vamp.width >= x0 &&
			vamp.x + (vamp.width / 2.0f) <= float(x0 + (wallWidth / 2)))
		{
			vamp.x = float(x0) - vamp.width - 1.0f;
			vamp.vx = 0.0f;
		}
		else if (vamp.x <= x1 &&
			vamp.x + (vamp.width / 2) > float(x0 + (wallWidth / 2)))
		{
			vamp.x = float(x1 + 1);
			vamp.vx = 0.0f;
		}
	}
}

void Wall::draw(Graphics & gfx)
{
	gfx.Rectangle(x0, y0, x1, y1, spacing, c);
}


