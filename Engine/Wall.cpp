#include "Wall.h"

void Wall::init(int setx0, int sety0, int setx1, int sety1, Color& setc, int setSpacing)
{
	x0 = setx0;
	y0 = sety0;
	x1 = setx1;
	y1 = sety1;
	c = setc;
	spacing = setSpacing;
}

void Wall::block(Vampire& vamp)
{
	//top (floor)
	if (vamp.x + vamp.width > x0 + 1 &&
		vamp.x < x1 - 1 &&
		vamp.y + vamp.height > y0    &&
		vamp.y < y0 + 5)
	{
		vamp.y = y0 - vamp.height;
		vamp.onGround = true;
	}
	//bottom
	else if (vamp.x + vamp.width > x0 + 1 &&
		vamp.x < x1 - 1 &&
		vamp.y + vamp.height > y1 - 1 &&
		vamp.y < y1)
	{
		vamp.y = y1 + 1;
		vamp.vy = 0;
	}
	//left side
	else if (vamp.y + vamp.height >= y0 &&
		vamp.y <= y1				    &&
		vamp.x + vamp.width >= x0		&&
		vamp.x < x0 + 5)
	{
		vamp.x = x0 - vamp.width;
		vamp.vx = 0;
	}
	//right side
	else if (vamp.y + vamp.height >= y0  &&
		vamp.y <= y1 				 &&
		vamp.x <= x1				 &&
		vamp.x + vamp.width > x1 - 5)
	{
		vamp.x = x1;
		vamp.vx = 0;
	}
}

void Wall::block2(Vampire& vamp)
{
	//set the block axis.
	if (vamp.x + vamp.width >= x0 && vamp.x <= x1 && 
		//make sure it only tests if vamp is already outside of the box.
		(vamp.y + vamp.height <= y0 || vamp.y >= y1))
	{
		rangeY = true;
	}
	if (vamp.y + vamp.height >= y0 && vamp.y <= y1 &&
		(vamp.x + vamp.width <= x0 || vamp.x >= x1))
	{
		rangeY = false;
	}

	const int wallHeight = y1 - y0;
	const int wallWidth = x1 - x0;

	if (rangeY)
	{
		//if vamp is in top half of box, push to top.
		//if vamp is in bottom half of box, push down.
		if (vamp.y + vamp.height >= y0 &&
			//this one has >=, but the other one doesn't. NO OVERLAP! even by one pixel. this is important in case you want to make thin walls for some reason.
			vamp.y + (vamp.height/2) <= y0 + (wallHeight/2))
		{
			vamp.y = y0 - vamp.height;
			vamp.onGround = true;
		}
		else if (vamp.y <= y1 &&
			vamp.y + (vamp.height / 2) > y0 + (wallHeight / 2))
		{
			vamp.y = y1;
			vamp.vy = 0;
		}
	}
	else //test horizontal range
	{
		if (vamp.x + vamp.width >= x0 &&
			vamp.x + (vamp.width / 2) <= x0 + (wallWidth / 2))
		{
			vamp.x = x0 - vamp.width - 1;
			vamp.vx = 0;
		}
		else if (vamp.x <= x1 &&
			vamp.x + (vamp.width / 2) > x0 + (wallWidth / 2))
		{
			vamp.x = x1 + 1;
			vamp.vx = 0;
		}
	}
}

void Wall::draw(Graphics & gfx)
{
	gfx.Rectangle(x0, y0, x1, y1, spacing, c);
}

void Spike::init(int setx, int sety, int setlength)
{
	x = setx;
	y = sety;
	length = setlength;
}

void Spike::floor(Vampire& vamp, Graphics& gfx)
{
	int i = 0;
	while (i < length)
	{
		sprite.spikeFloor(x + i, y - height, gfx);
		i = i + 10;
	}

	if (vamp.x < x + length &&
		vamp.x + vamp.width > x &&
		vamp.y + vamp.height > y - height &&
		vamp.y < y)
	{
		vamp.isStabbed = true;
	}
}

void Spike::top(Vampire& vamp, Graphics& gfx)
{
	int i = 0;
	while (i < length)
	{
		sprite.spikeTop(x + i, y, gfx);
		i = i + 10;
	}

	if (vamp.x < x + width &&
		vamp.x + vamp.width > x &&
		vamp.y + vamp.height > y - width &&
		vamp.y < y)
	{
		vamp.isStabbed = true;
	}
}

void Spike::left(Vampire& vamp, Graphics& gfx)
{
	int i = 0;
	while (i < length)
	{
		sprite.spikeLeft(x, y + i, gfx);
		i = i + 10;
	}

	if (vamp.x < x + width &&
		vamp.x + vamp.width > x &&
		vamp.y + vamp.height > y - width &&
		vamp.y < y)
	{
		vamp.isStabbed = true;
	}
}

void Spike::right(Vampire& vamp, Graphics& gfx)
{
	int i = 0;
	while (i < length)
	{
		sprite.spikeRight(x - width, y + i, gfx);
		i = i + 10;
	}

	if (vamp.x < x + width &&
		vamp.x + vamp.width > x &&
		vamp.y + vamp.height > y - width &&
		vamp.y < y)
	{
		vamp.isStabbed = true;
	}
}
