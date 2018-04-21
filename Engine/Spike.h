#pragma once
#include "Vampire.h"

class Spike
{
	//spikes are 10 pixels wide each. these spikes extrude to a length of 15 pixels.
public:
	void init(int setx, int sety, int setlength);
	//choose your direction of spikes. each function draws, blocks, and kills the vamp all by itself.
	void floor(Vampire& vamp, Graphics& gfx);
	void top(Vampire& vamp, Graphics& gfx);
	void left(Vampire& vamp, Graphics& gfx);
	void right(Vampire& vamp, Graphics& gfx);
public:
	int x;
	int y;
	int length = 10;
private:
	static constexpr int width = 10;
	static constexpr int height = 15;
	Sprite sprite;
};