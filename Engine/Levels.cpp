#include "Levels.h"

Levels::Levels() 
{
}

void Levels::L0::processLevel(Frog & frog, Graphics& gfx)
{
	nextStage(frog);
	//testStage(frog, gfx);
	stage0(frog, gfx);
	//draw frame
	frame.init(150, 50, 600, 500);
	frame.offset(frog);
	frame.clamp(frog);
	c.SetR(255);
	c.SetG(0);
	c.SetB(0);
	frame.draw(2, c, gfx);
}

void Levels::L0::testStage(Frog& frog, Graphics& gfx)
{
	c.SetR(200);
	c.SetG(240);
	c.SetB(100);
	testWall[0].init(200, 530, 300, 550, c, 2);
	testWall[1].init(710, 110, 749, 150, c, 2);
	testWall[2].init(670, 150, 750, 529, c, 2);
	testWall[3].init(580, 530, 750, 552, c, 2);
	// block and draw
	for (int i = 0; i < 4; ++i)
	{
		testWall[i].block(frog);
		testWall[i].draw(gfx);
	}
	spike0.init(300, 550, 280);
	spike1.init(640, 530, 30 );
	spike0.floor(frog, gfx);
	spike1.floor(frog, gfx);
}

void Levels::L0::stage0(Frog & frog, Graphics& gfx)
{
	c.SetR(169);
	c.SetG(239);
	c.SetB(034);
	stage0Walls[0].init(0, 450, 600, 500, c, 2);
	stage0Walls[1].init(0, 0, 100, 450, c, 2);
	stage0Walls[2].init(100, 0, 600, 450, c, 2);
	for (int i = 0; i < 3; ++i)
	{
		frame.offset(stage0Walls[i]);
		stage0Walls[i].block(frog);
	}
}

void Levels::L0::stage1(Frog & frog, Graphics & gfx)
{
}

void Levels::L0::nextStage(Frog & frog)
{
	//right
	if (frog.x + frog.width >= frame.width + frog.width && stage < maxStages)
	{
		frog.x = frame.x;
		++stage;
	}
	else if (stage > maxStages)
	{
		stage = maxStages;
	}
	//left
	if (frog.x <= frame.x - frog.width && stage > 0)
	{
		frog.x = frame.width - frog.width - 1;
		--stage;
	}
	else if (stage < 0)
	{
		stage = 0;
	}
}

void Levels::L0::spawn(Frog & frog)
{
	if (stage == 0)
	{
		frog.x = 101;
		frog.y = 450 - frog.width;
	}
	stage = 0;
}

int Levels::L0::getStage()
{
	return stage;
}
