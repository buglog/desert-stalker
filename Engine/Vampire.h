#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Sprite.h"
#include "CowboyHat.h"

class Vampire
{
public:
	void ClampToScreen();
	void init(int setx, int sety);
	void update(const Keyboard& kbd, CowboyHat& hat);
	void draw(Graphics& gfx);
	void skull(Graphics& gfx);
private:
	void moveControls(const Keyboard& kbd);
	//to put the code for the E key, once it does different stuff
	void eControl(const Keyboard& kbd);
private:
	//small vamp (desert scene)
	void sml_drawLeft(Graphics& gfx);
	void sml_drawRight(Graphics& gfx);
	void sml_drawUp(Graphics& gfx);
	void sml_drawDown(Graphics& gfx);
	void sml_drawScary(Graphics& gfx);
	//medium vamp
private:
	int count = 0;
	float speed = 3.0f;
	//controls horizontal speed while jumping
	bool facingLeft = false;
	bool facingRight = true;
	bool facingUp = false;
	bool facingDown = false;
	Sprite sprites;
	Color cvamp;
public:
	bool isSmall = true;
	bool isScary = false;
	bool isStabbed = false;
	bool hasHat = false;
public:
	float x = 250;
	float y = 400;
	float vx = 0;
	float vy = 0;
	float accel = 0.5f;
	float decel = 0.1f;
	// width and height are no longer static constexpr so you can change size of vamp between stages.
	// also, make hitbox around feet for walls and spikes, but around entire vamp for frame.clamp(vamp).
	float hitOffset = -60.0f;
	float width  = 50.0f;
	float height = 20.0f;
	float trueWidth = 50.0f;
	float trueHeight = 80.0f;
	//make Frame take realHeight instead of height
	//and make hitbox smaller.
	float realHeight = 0.0f;
};
