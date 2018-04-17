#include "Level0.h"

Level0::Level0() 
{
}

void Level0::init(Frog & frog)
{
	stage = 0;
	frog.x = 30;
	frog.y = 505;
}

void Level0::level(Frog & frog, Graphics& gfx)
{
	nextStage(frog);
	if (stage == 0)
	{
		stage0(frog, gfx);
	}
	else if(stage == 1)
	{
		stage4(frog, gfx);
	}
	//draw frame
	c.SetR(255);
	c.SetG(0);
	c.SetB(0);
	frame.init(200, 50, 750, 550);
	frame.clamp(frog);
}

void Level0::stage0(Frog & frog, Graphics & gfx)
{
	c.SetR(255);
	c.SetG(200);
	c.SetB(0);
	gfx.Rectangle(frame.x0, 530, frame.x1, frame.y1, 2, c);
	gfx.Rectangle(frame.x0, frame.y0, frame.x1, 504, 2, c);
	gfx.Rectangle(frame.x0, frame.y0, 300, frame.y1, 2, c);

	frog.jump = false;
	
	if (frog.x <= 300)
	{
		frog.x = 300;
	}
	if (frog.y + frog.height >= 530)
	{
		frog.y = 530 - frog.height;
		frog.onGround = true;
	}
	if (frog.y <= 530 - frog.height - 2)
	{
		frog.y = 530 - frog.height;
		frog.vy = 0;
	}
}

void Level0::stage1(Frog & frog, Graphics & gfx)
{
	c.SetR(255);
	c.SetG(100);
	c.SetB(100);
	gfx.Rectangle(frame.x0, 530, frame.x1, frame.y1, 2, c);
	gfx.Rectangle(frame.x0, frame.y0, frame.x1, 504, 2, c);

	frog.jump = false;

	if (frog.y + frog.height >= 530)
	{
		frog.y = 530 - frog.height;
		frog.onGround = true;
	}
	if (frog.y <= 530 - frog.height - 2)
	{
		frog.y = 530 - frog.height;
		frog.vy = 0;
	}
}

void Level0::stage4(Frog& frog, Graphics& gfx)
{
	c.SetR(200);
	c.SetG(240);
	c.SetB(100);
	stage4wall[0].init(200, 530, 300, 550, c, 2);
	stage4wall[1].init(710, 110, 749, 150, c, 2);
	stage4wall[2].init(670, 150, 750, 529, c, 2);
	stage4wall[3].init(580, 530, 750, 552, c, 2);
	// block and draw
	for (int i = 0; i < stage4walls; ++i)
	{
		stage4wall[i].block(frog);
		stage4wall[i].draw(gfx);
	}
	spike0.init(300, 550, 280);
	spike1.init(640, 530, 30 );
	spike0.floor(frog, gfx);
	spike1.floor(frog, gfx);
}

void Level0::nextStage(Frog & frog)
{
	//right
	if (frog.x + frog.width >= frame.x1 + 3 && stage < maxStages)
	{
		frog.x = frame.x0 + 2;
		++stage;
	}
	else if (stage > maxStages)
	{
		stage = maxStages;
	}
	//left
	if (frog.x <= frame.x0 - 3 && stage > 0)
	{
		frog.x = frame.x1 - frog.width - 2;
		--stage;
	}
	else if (stage < 0)
	{
		stage = 0;
	}
}

