#include "Spike.h"

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