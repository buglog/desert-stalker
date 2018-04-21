#include "Desert.h"

void Desert::process(Vampire & vamp, Graphics& gfx)
{
	frame.init(200, 200, 600, 400);
	frame.clamp(vamp);
	frame.draw(1, Colors::Red, gfx);
	drawSand(gfx);
}

void Desert::spawn(int x, int y, Vampire & vamp)
{
	vamp.x = x;
	vamp.y = y;
}

void Desert::drawSand(Graphics & gfx)
{
	// draws sand
	csand.SetR(150);
	csand.SetG(100);
	csand.SetB(70);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 1, csand);
	csand.SetR(255);
	csand.SetG(50);
	csand.SetB(30);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 5, csand);
	csand.SetR(100);
	csand.SetG(200);
	csand.SetB(50);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 12, csand);
	csand.SetR(255);
	csand.SetG(220);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 24, csand);
}
