#include "Frame.h"

void Frame::init(int setx0, int sety0, int setx1, int sety1)
{
	x0 = setx0;
	y0 = sety0;
	x1 = setx1;
	y1 = sety1;
}

void Frame::clamp(Frog & frog)
{	
	//bottom
	if (frog.y + frog.height >= y1)
	{
		frog.y = y1 - frog.height;
		frog.vy = 0;
		frog.onGround = true;
	}
	//left
	if (frog.x <= x0 - 5)
	{
		frog.x = x0 - 5;
		frog.vx = 0;
	}
	//right
	if (frog.x + frog.width >= x1 + 5)
	{
		frog.x = x1 + 5 - frog.width;
		frog.vx = 0;
	}
	//top
	if (frog.y <= y0)
	{
		frog.y = y0;
		frog.vy = 0;
	}
}

void Frame::draw(int spacing, Color c, Graphics & gfx)
{
	gfx.Rectangle(0, 0, x0, gfx.ScreenHeight - 1, 1, Colors::Black);
	gfx.Rectangle(0, 0, gfx.ScreenWidth - 1, y0, 1, Colors::Black);
	gfx.Rectangle(x1, 0, gfx.ScreenWidth - 1, gfx.ScreenHeight - 1, 1, Colors::Black);
	gfx.Rectangle(0, y1, gfx.ScreenWidth - 1, gfx.ScreenHeight - 1, 1, Colors::Black);
	gfx.HorizontalLine(x0, x1, y0, spacing, c);
	gfx.HorizontalLine(x0, x1, y1, spacing, c);
	gfx.VerticalLine(y0, y1, x0, spacing, c);
	gfx.VerticalLine(y0, y1, x1, spacing, c);
}


