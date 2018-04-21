#include "Levels.h"

Levels::Levels() 
{
}

Levels::L0::L0()
{
	frame.init(0, 0, 600, 500);
}

void Levels::L0::processLevel(Vampire& vamp, Graphics& gfx)
{
	if (!vamp.isSpawned)
	{
		spawn(vamp);
		vamp.isSpawned = true;
	}
	openDesert(vamp, gfx);
	//frame.offset(vamp);
	frame.clamp(vamp);
	c.SetR(255);
	c.SetG(0);
	c.SetB(0);
	frame.draw(2, c, gfx);
}

void Levels::L0::openDesert(Vampire& vamp, Graphics& gfx)
{
}

void Levels::L0::stage1(Vampire& vamp, Graphics & gfx)
{
}

void Levels::L0::nextStage(Vampire& vamp)
{
	//right
	if (vamp.x + vamp.width >= frame.width - 1 && stage < maxStages)
	{
		vamp.x = frame.x + vamp.width;
		++stage;
	}
	else if (stage > maxStages)
	{
		stage = maxStages;
	}
	//left
	if (vamp.x <= frame.x + 1 && stage > 0)
	{
		vamp.x = frame.width - vamp.width * 2;
		--stage;
	}
	else if (stage < 0)
	{
		stage = 0;
	}
}

void Levels::L0::spawn(Vampire& vamp)
{
	vamp.x = 80;
	vamp.y = 460 - vamp.height;
}

int Levels::L0::getStage()
{
	return stage;
}
