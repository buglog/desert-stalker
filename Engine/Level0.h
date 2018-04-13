#pragma once
#include "Frog.h"
#include "Wall.h"
#include "Spike.h"
#include "Frame.h"
#include "Colors.h"

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