#pragma once
#include "Graphics.h"

class CowboyHat
{
public:
	void init(int setx, int sety);
	void draw(Graphics& gfx);
public:
	int x = 0;
	int y = 0;
	int yOffset = -12;
	static constexpr int pickUpRange = 40;
	static constexpr int width = 50;
	static constexpr int height = 22;
};