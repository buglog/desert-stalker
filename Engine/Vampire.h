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
	float speed = 4.0f;
	//controls horizontal speed while jumping
	bool faceLeft = false;
	bool faceRight = true;
	bool faceUp = false;
	bool faceDown = false;
	Sprite sprites;
	Color cvamp;
public:
	float x = 400;
	float y = 300;
	float vx = 0;
	float vy = 0;
	float accel = 0.5f;
	// width and height are no longer static constexpr so you can change size of vamp between stages.
	// also, make hitbox around feet for walls and spikes, but around entire vamp for frame.clamp(vamp).
	float width  = 20.0f;
	float height = 24.0f;
	bool onGround = false;
	bool isStabbed = false;
	bool isSpawned = false;
};