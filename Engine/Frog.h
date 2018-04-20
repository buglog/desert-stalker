#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Sprite.h"

class Frog
{
public:
	void ClampToScreen();
	void Init(int setx, int sety);
	void update(const Keyboard& kbd);
	void Walk(Graphics& gfx);
	void skull(Graphics& gfx);
	bool jump = false;
private:
	int count = 0;
	int speed = 4;
	//speed 25
	// height 6
	int jumpSpeed  = 24;
	int jumpHeight =  6;
	int jumpCount  =  0;
	int fallSpeed  = 20;
	//controls horizontal speed while jumping
	int yaw = 3;
	bool faceRight = true;
	bool faceLeft = false;
	Sprite sprites;
public:
	int x = 101;
	int y = 420;
	int vx = 0;
	int vy = 0;
	static constexpr int width  = 20;
	static constexpr int height = 24;
	bool onGround = false;
	bool isStabbed = false;
	bool isSpawned = false;
};