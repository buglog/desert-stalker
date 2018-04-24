#pragma once
#include "Graphics.h"
#include "Frame.h"
#include "Message.h"

class ProgressBar
{
public:
	void init(int setx,int sety, Color setc, int setType, float setP);
	void draw(Graphics& gfx, Message& msg);
	void incr(int n);
	int getProg();
private:
	void draw_cowboy(Graphics& gfx);
	void draw_terror(Graphics& gfx);
public:
	int x = 0;
	int y = 0;
	static constexpr int height = 15;
	static constexpr int width = 170;
private:
	bool cowboyMsgDone = false;
	int type = 0;
	Color c;
	Color cFrame;
	Frame frame;
	float setProg = 100;
	float progress = 0;
};