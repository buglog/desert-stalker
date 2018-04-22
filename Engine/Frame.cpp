#include "Frame.h"

void Frame::init(int setx, int sety, int setWidth, int setHeight)
{
	x = setx;
	y = sety;
	width = setWidth;
	height = setHeight;
}

void Frame::offset(Vampire& vamp)
{
	vamp.x = vamp.x + float(x);
	vamp.y = vamp.y + float(y);
}

void Frame::offset(Wall & wall)
{
	wall.x0 = wall.x0 + x;
	wall.x1 = wall.x1 + x;
	wall.y0 = wall.y0 + y;
	wall.y1 = wall.y1 + y;
}

void Frame::offset(Spike & spike)
{
	spike.x += x;
	spike.y += y;
}

void Frame::clamp(Vampire& vamp)
{	
	//bottom
	if (vamp.y + vamp.height >= float(height))
	{
		vamp.y = float(height) - vamp.height;
		vamp.vy = 0.0f;
	}
	//left
	if (vamp.x <= x)
	{
		vamp.x  = float(x);
		vamp.vx = 0.0f;
	}
	//right
	if (vamp.x + vamp.width >= float(width))
	{
		vamp.x = float(width) - vamp.width;
		vamp.vx = 0.0f;
	}
	//top
	if (vamp.y + vamp.hitOffset <= float(y))
	{
		vamp.y  = float(y) - vamp.hitOffset;
		vamp.vy = 0.0f;
	}
}

void Frame::draw(int spacing, Color c, Graphics & gfx)
{
	gfx.HorizontalLine(x, width, y, spacing, c);
	gfx.HorizontalLine(x, width, height, spacing, c);
	gfx.VerticalLine(y, height, x, spacing, c);
	gfx.VerticalLine(y, height, width, spacing, c);
}


