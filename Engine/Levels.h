#pragma once
#include "Frog.h"
#include "Frame.h"
#include "Colors.h"
#include "WorldObj.h"

class Levels
{
public:
	Levels();
	class L0 
	{
	public:
		void processLevel(Frog& frog, Graphics& gfx);
		void spawn(Frog& frog);
		int getStage();
	private:
		void nextStage(Frog& frog);
		void testStage(Frog& frog, Graphics& gfx);
		void stage0(Frog& frog, Graphics& gfx);
		void stage1(Frog& frog, Graphics& gfx);
	private:
		World::Wall testWall[4];
		World::Spike spike0;
		World::Spike spike1;
		Color c;
		int stage = 0;
		int maxStages = 1;
		Frame frame;
	private:
		World::Wall stage0Walls[3];
		World::Wall stage1Walls[2];
	};
	//class L1
	//{};
};