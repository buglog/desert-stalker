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
	int got_hat = 2;
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
	void draw_gotHat(Graphics& gfx);
};