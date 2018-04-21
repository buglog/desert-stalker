#pragma once
#include "Vampire.h"
#include "Frame.h"
#include "Colors.h"
#include "Wall.h"

class Levels
{
public:
	Levels();
	class L0 
	{
	public:
		L0();
		void processLevel(Vampire& vamp, Graphics& gfx);
		void spawn(Vampire& vamp);
		int getStage();
	private:
		void nextStage(Vampire& vamp);
		void openDesert(Vampire& vamp, Graphics& gfx);
		void stage1(Vampire& vamp, Graphics& gfx);
	private:
		Wall testWall[4];
		Spike spike0;
		Spike spike1;
		Color c;
		int stage = 0;
		int maxStages = 1;
		Frame frame;
	private:
		Wall stage0Walls[3];
		Wall stage1Walls[2];
	};
	//class L1
	//{};
};