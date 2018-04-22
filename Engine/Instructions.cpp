#include "Instructions.h"

Instructions::Instructions()
{
	fwasd.init(wasd_x, wasd_y, wasd_x + wasd_width, wasd_y + wasd_height);
	fe.init(e_x, e_y, e_x + e_width, e_y + e_height);
}

void Instructions::draw(Graphics& gfx)
{
	drawWASD(gfx);
	drawE(gfx);
}

void Instructions::drawWASD(Graphics & gfx)
{
	cframe.SetR(255);
	cframe.SetG(0);
	cframe.SetB(0);
	fwasd.draw(1, cframe, gfx);
}

void Instructions::drawE(Graphics & gfx)
{
	cframe.SetR(255);
	cframe.SetG(0);
	cframe.SetB(0);
	fe.draw(1, cframe, gfx);
}
