#include "Levels.h"

Levels::Levels() 
{
}

void Levels::L0::processLevel(Frog & frog, Graphics& gfx)
{
	nextStage(frog);
	testStage(frog, gfx);
	//draw frame
	frame.init(200, 50, 750, 550);
	frame.clamp(frog);
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
	for (int i = 0; i < testWallsN; ++i)
	{
		testWall[i].block(frog);
		testWall[i].draw(gfx);
	}
	spike0.init(300, 550, 280);
	spike1.init(640, 530, 30 );
	spike0.floor(frog, gfx);
	spike1.floor(frog, gfx);
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
	stage = 0;
	frog.x = 30;
	frog.y = 505;
}

void Levels::L0::drawStages(Graphics & gfx)
{	  
	// eventually, you should have a
	// drawStage0, drawStage1, drawStage2, etc
	// these will all go here with a switch / case operator
	// to check for the different values of 'stage'
	// and draw the frame accordingly
	c.SetR(255);
	c.SetG(0);
	c.SetB(0);
	frame.draw(1, Colors::Yellow, gfx);
}

int Levels::L0::getStage()
{
	return stage;
}
