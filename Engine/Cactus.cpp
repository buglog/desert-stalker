#include "Cactus.h"

void Cactus::init(int setx, int sety, int setVersion)
{
	x = setx;
	y = sety;
	version = setVersion;
}

void Cactus::place(Graphics& gfx, Vampire& vamp)
{
	if (version == 0)
	{
		//set width and height
		drawVer0(gfx);
		cWall.init(x, y, x + width, y + height, Colors::Black, 1);
		cWall.block(vamp);
	}
	else if (version == 1)
	{
		//set width and height
		drawVer1(gfx);
	}
	else if (version == 2)
	{
		//set width and height
		drawVer2(gfx);
	}
}

void Cactus::drawVer0(Graphics & gfx)
{
	gfx.Rectangle(x, y, x + width, y + height, 2, Colors::Green);
}

void Cactus::drawVer1(Graphics & gfx)
{
}

void Cactus::drawVer2(Graphics & gfx)
{
}

