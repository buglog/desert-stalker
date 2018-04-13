#include "Spike.h"

void Spike::init(int setx, int sety, int setlength)
{
	x = setx;
	y = sety;
	length = setlength;
}

void Spike::floor(Frog& frog, Graphics& gfx)
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
		frog.stabbed = true;
	}
}

void Spike::top(Frog& frog, Graphics& gfx)
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
		frog.stabbed = true;
	}
}

void Spike::left(Frog& frog, Graphics& gfx)
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
		frog.stabbed = true;
	}
}

void Spike::right(Frog& frog, Graphics& gfx)
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
		frog.stabbed = true;
	}
}
