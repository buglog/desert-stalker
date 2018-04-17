#pragma once
#include "Frog.h"

class World
{
public:
	class Wall
	{
		//pass frog by ref: wall0.block(frog);
		//and then draw over top. wall.draw(gfx);
		//easy right?
	public:
		void init(int setx0, int sety0, int setx1, int sety1, Color& setc, int setSpacing);
		void block(Frog& frog);
		void draw(Graphics& gfx);
	public:
		int x0 = 0;
		int y0 = 0;
		int x1 = 0;
		int y1 = 0;
		int spacing = 0;
		Color c;
	};
	class Spike
	{
		//spikes are 10 pixels wide each. these spikes extrude to a length of 15 pixels.
	public:
		void init(int setx, int sety, int setlength);
		//choose your direction of spikes. each function draws, blocks, and kills the frog all by itself.
		void floor(Frog& frog, Graphics& gfx);
		void top(Frog& frog, Graphics& gfx);
		void left(Frog& frog, Graphics& gfx);
		void right(Frog& frog, Graphics& gfx);
	public:
		int x;
		int y;
		int length = 10;
	private:
		static constexpr int width = 10;
		static constexpr int height = 15;
		Sprite sprite;
	};
};