#include "Desert.h"

Desert::Desert()
{
	frame.init(200, 20, 780, 580);
	c0.init(300, 250, 0);
}

void Desert::process(Vampire & vamp, Graphics& gfx)
{
	drawSand(gfx);
	placeCactuses(vamp, gfx);
	frame.clamp(vamp);
	cframe.SetR(255);
	cframe.SetG(0);
	cframe.SetB(0);
	frame.draw(1, cframe, gfx);
}

void Desert::spawn(int x, int y, Vampire & vamp)
{
	vamp.x = float(x);
	vamp.y = float(y);
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
	//draw vignette
	//csand.SetR(0);
	//csand.SetG(0);
	//csand.SetB(255);
	//gfx.Rectangle(frame.x, frame.y, frame.width,frame.y + 100,4,csand);
}

void Desert::placeCactuses(Vampire & vamp, Graphics& gfx)
{
	c0.place(gfx, vamp);
}

