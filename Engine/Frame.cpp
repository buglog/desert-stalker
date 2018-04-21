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
	vamp.x = vamp.x + x;
	vamp.y = vamp.y + y;
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
	if (vamp.y + vamp.height >= height)
	{
		vamp.y = height - vamp.height;
		vamp.vy = 0;
		vamp.onGround = true;
	}
	//left
	if (vamp.x <= x)
	{
		vamp.x = x;
		vamp.vx = 0;
	}
	//right
	if (vamp.x + vamp.width >= width)
	{
		vamp.x = width - vamp.width;
		vamp.vx = 0;
	}
	//top
	if (vamp.y <= y)
	{
		vamp.y = y;
		vamp.vy = 0;
	}
}

void Frame::draw(int spacing, Color c, Graphics & gfx)
{
	gfx.Rectangle(0, 0, x, gfx.ScreenHeight - 1, 1, Colors::Black);
	gfx.Rectangle(0, 0, gfx.ScreenWidth - 1, y, 1, Colors::Black);
	gfx.Rectangle(width, 0, gfx.ScreenWidth - 1, gfx.ScreenHeight - 1, 1, Colors::Black);
	gfx.Rectangle(0, height, gfx.ScreenWidth - 1, gfx.ScreenHeight - 1, 1, Colors::Black);
	gfx.HorizontalLine(x, width, y, spacing, c);
	gfx.HorizontalLine(x, width, height, spacing, c);
	gfx.VerticalLine(y, height, x, spacing, c);
	gfx.VerticalLine(y, height, width, spacing, c);
}


