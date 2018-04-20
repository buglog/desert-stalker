#include "WorldObj.h"

void World::Wall::init(int setx0, int sety0, int setx1, int sety1, Color& setc, int setSpacing)
{
	x0 = setx0;
	y0 = sety0;
	x1 = setx1;
	y1 = sety1;
	c = setc;
	spacing = setSpacing;
}

void World::Wall::block(Frog & frog)
{
	//top (floor)
	if (frog.x + frog.width > x0 + 1 &&
		frog.x < x1 - 1 &&
		frog.y + frog.height > y0    &&
		frog.y < y0 + 5)
	{
		frog.y = y0 - frog.height;
		frog.onGround = true;
	}
	//bottom
	else if (frog.x + frog.width > x0 + 1 &&
		frog.x < x1 - 1 &&
		frog.y + frog.height > y1 - 1 &&
		frog.y < y1)
	{
		frog.y = y1 + 1;
		frog.vy = 0;
	}
	//left side
	else if (frog.y + frog.height >= y0 &&
		frog.y <= y1				    &&
		frog.x + frog.width >= x0		&&
		frog.x < x0 + 5)
	{
		frog.x = x0 - frog.width;
		frog.vx = 0;
	}
	//right side
	else if (frog.y + frog.height >= y0  &&
		frog.y <= y1 				 &&
		frog.x <= x1				 &&
		frog.x + frog.width > x1 - 5)
	{
		frog.x = x1;
		frog.vx = 0;
	}
}

void World::Wall::block2(Frog & frog)
{
	//set the block axis.
	if (frog.x + frog.width >= x0 && frog.x <= x1 && 
		//make sure it only tests if frog is already outside of the box.
		(frog.y + frog.height <= y0 || frog.y >= y1))
	{
		rangeY = true;
	}
	if (frog.y + frog.height >= y0 && frog.y <= y1 &&
		(frog.x + frog.width <= x0 || frog.x >= x1))
	{
		rangeY = false;
	}

	const int wallHeight = y1 - y0;
	const int wallWidth = x1 - x0;

	if (rangeY)
	{
		//if frog is in top half of box, push to top.
		//if frog is in bottom half of box, push down.
		if (frog.y + frog.height >= y0 &&
			//this one has >=, but the other one doesn't. NO OVERLAP! even by one pixel. this is important in case you want to make thin walls for some reason.
			frog.y + (frog.height/2) <= y0 + (wallHeight/2))
		{
			frog.y = y0 - frog.height;
			frog.onGround = true;
		}
		else if (frog.y <= y1 &&
			frog.y + (frog.height / 2) > y0 + (wallHeight / 2))
		{
			frog.y = y1;
			frog.vy = 0;
		}
	}
	else //test horizontal range
	{
		if (frog.x + frog.width >= x0 &&
			frog.x + (frog.width / 2) <= x0 + (wallWidth / 2))
		{
			frog.x = x0 - frog.width - 1;
			frog.vx = 0;
		}
		else if (frog.x <= x1 &&
			frog.x + (frog.width / 2) > x0 + (wallWidth / 2))
		{
			frog.x = x1 + 1;
			frog.vx = 0;
		}
	}
}

void World::Wall::draw(Graphics & gfx)
{
	gfx.Rectangle(x0, y0, x1, y1, spacing, c);
}

void World::Spike::init(int setx, int sety, int setlength)
{
	x = setx;
	y = sety;
	length = setlength;
}

void World::Spike::floor(Frog& frog, Graphics& gfx)
{
	int i = 0;
	while (i < length)
	{
		sprite.spikeFloor(x + i, y - height, gfx);
		i = i + 10;
	}

	if (frog.x < x + length &&
		frog.x + frog.width > x &&
		frog.y + frog.height > y - height &&
		frog.y < y)
	{
		frog.isStabbed = true;
	}
}

void World::Spike::top(Frog& frog, Graphics& gfx)
{
	int i = 0;
	while (i < length)
	{
		sprite.spikeTop(x + i, y, gfx);
		i = i + 10;
	}

	if (frog.x < x + width &&
		frog.x + frog.width > x &&
		frog.y + frog.height > y - width &&
		frog.y < y)
	{
		frog.isStabbed = true;
	}
}

void World::Spike::left(Frog& frog, Graphics& gfx)
{
	int i = 0;
	while (i < length)
	{
		sprite.spikeLeft(x, y + i, gfx);
		i = i + 10;
	}

	if (frog.x < x + width &&
		frog.x + frog.width > x &&
		frog.y + frog.height > y - width &&
		frog.y < y)
	{
		frog.isStabbed = true;
	}
}

void World::Spike::right(Frog& frog, Graphics& gfx)
{
	int i = 0;
	while (i < length)
	{
		sprite.spikeRight(x - width, y + i, gfx);
		i = i + 10;
	}

	if (frog.x < x + width &&
		frog.x + frog.width > x &&
		frog.y + frog.height > y - width &&
		frog.y < y)
	{
		frog.isStabbed = true;
	}
}
