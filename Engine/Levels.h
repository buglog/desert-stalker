#pragma once
#include "Frog.h"
#include "Frame.h"
#include "Colors.h"
#include "World.h"

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
	private:
		static constexpr int testWallsN = 4;
		World::Wall testWall[testWallsN];
		World::Spike spike0;
		World::Spike spike1;
		Color c;
		int stage = 0;
		int maxStages = 1;
		Frame frame;
	};
};