#pragma once
#include "Frog.h"
#include "Wall.h"
#include "Spike.h"
#include "Frame.h"
#include "Colors.h"

// I must try to think of a better way to store my levels. I feel like either class inheritance
// or file access must be the key to this. I hate the idea of having  files floating around wherever

class Level0
{
public:
	Level0();
	void init(Frog& frog);
	void level(Frog& frog, Graphics& gfx);
private:
	void stage0(Frog& frog, Graphics& gfx);
	void stage1(Frog& frog, Graphics& gfx);
	void stage4(Frog& frog, Graphics& gfx);
	void nextStage(Frog& frog);
private:
	//important
	int stage = 0;
	int maxStages = 1;
	Frame frame;
	//stage0
	static constexpr int stage0walls = 3;
	Wall stage0wall[stage0walls];
	//stage4
	static constexpr int stage4walls = 4;
	Wall stage4wall[stage4walls];
	Spike spike0;
	Spike spike1;
	Color c;
};