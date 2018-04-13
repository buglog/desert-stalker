#pragma once
#include "Graphics.h"

struct Sprite
{
public:
	void Frog_R0(int x, int y, Graphics& gfx) const;
	void Frog_R1(int x, int y, Graphics& gfx) const;
	void Frog_L0(int x, int y, Graphics& gfx) const;
	void Frog_L1(int x, int y, Graphics& gfx) const;
	void spikeFloor(int x, int y,Graphics& gfx);
	void spikeLeft(int x, int y, Graphics& gfx);
	void spikeRight(int x, int y, Graphics& gfx);
	void spikeTop(int x, int y, Graphics& gfx);
};