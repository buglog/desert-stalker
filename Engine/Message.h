#pragma once
#include "Graphics.h"
#include "Frame.h"

class Message
{
public:
	Message();
	void draw(Graphics& gfx);
	void reset();
public:
	int message = 1;
	int cactus_scared = 1;
	int cact_unimpressed = 2;
	int got_hat = 3;
	int truly_terrifying = 4;
	int true_cowboy = 5;
	int beautiful = 6;
private:
	Frame fmsg;
	Color cframe;
	int counter = 100;
	static constexpr int msgTime = 100;
private:
	int x = 260;
	int y = 520;
	void draw_frame(Graphics& gfx);
	void draw_cactScared(Graphics& gfx);
	void draw_cactUnimpressed(Graphics& gfx);
	void draw_gotHat(Graphics& gfx);
	void draw_truly(Graphics& gfx);
	void draw_trueCowboy(Graphics& gfx);
	void draw_beautiful(Graphics& gfx);
};