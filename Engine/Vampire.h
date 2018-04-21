#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Sprite.h"

class Vampire
{
public:
	void ClampToScreen();
	void Init(int setx, int sety);
	void update(const Keyboard& kbd);
	void draw(Graphics& gfx);
	void skull(Graphics& gfx);
private:
	int count = 0;
	int speed = 4;
	//controls horizontal speed while jumping
	bool faceRight = true;
	bool faceLeft = false;
	Sprite sprites;
	Color cvamp;
public:
	int x = 400;
	int y = 300;
	int vx = 0;
	int vy = 0;
	static constexpr int width  = 20;
	static constexpr int height = 24;
	bool onGround = false;
	bool isStabbed = false;
	bool isSpawned = false;
};