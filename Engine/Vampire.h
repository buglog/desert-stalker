#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Sprite.h"

class Vampire
{
public:
	void ClampToScreen();
	void init(int setx, int sety);
	void update(const Keyboard& kbd);
	void draw(Graphics& gfx);
	void skull(Graphics& gfx);
private:
	//small vamp (desert scene)
	void sml_drawLeft(Graphics& gfx);
	void sml_drawRight(Graphics& gfx);
	void sml_drawUp(Graphics& gfx);
	void sml_drawDown(Graphics& gfx);
	//large vamp
private:
	int count = 0;
	float speed = 2.5f;
	//controls horizontal speed while jumping
	bool facingLeft = false;
	bool facingRight = true;
	bool facingUp = false;
	bool facingDown = false;
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
	int hitOffset = -40;
	float width  = 50.0f;
	float height = 40.0f;
	float trueWidth = 50.0f;
	float trueHeight = 80.0f;
	//make Frame take realHeight instead of height
	//and make hitbox smaller.
	float realHeight = 0.0f;
	bool isStabbed = false;
	bool isSpawned = false;
};