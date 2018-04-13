#pragma once
#include "Colors.h"
#include "Graphics.h"
#include "Sprite.h"
#include "Frog.h"

class Spike
{
//spikes are 10 pixels wide each. these spikes extrude to a length of 15 pixels.
public:
	void init(int setx, int sety, int setlength);
	void floor(Frog& frog, Graphics& gfx);
	void top  (Frog& frog, Graphics& gfx);
	void left (Frog& frog, Graphics& gfx);
	void right(Frog& frog, Graphics& gfx);
public:
	int x;
	int y;
	int length = 10;
private:
	static constexpr int width  = 10;
	static constexpr int height = 15;
	Sprite sprite;
};