#include "Vampire.h"

void Vampire::ClampToScreen()
{
	if (x <= 0)
	{
		x = 0;
		vx = 0;
	}
	if (x + width >= Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - width;
		vx = 0;
	}
	if (y <= 0)
	{
		y = 2;
		vy = 0;
	}
	if (y + height >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - height;
		onGround = true;
	}
}

void Vampire::Init(int setx, int sety)
{
	x = setx;
	y = sety;
}

void Vampire::update(const Keyboard & kbd)
{
	if (kbd.KeyIsPressed(VK_UP) || kbd.KeyIsPressed('W'))
	{
		vy = -speed;
	}
	else if (kbd.KeyIsPressed(VK_DOWN) || kbd.KeyIsPressed('S'))
	{
		vy = speed;
	}
	else
	{
		vy = 0;
	}
	if (kbd.KeyIsPressed(VK_LEFT) || kbd.KeyIsPressed('A'))
	{
		vx = -speed;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT) || kbd.KeyIsPressed('D'))
	{
		vx = speed;
	}
	else
	{
		vx = 0;
	}
	//update position.
	x += vx;
	y += vy;
}

void Vampire::draw(Graphics & gfx)
{
	cvamp.SetR(255);
	cvamp.SetG(255);
	cvamp.SetB(255);
	gfx.Rectangle(x, y, x + width, y + height, 2, cvamp);
}

void Vampire::skull(Graphics & gfx)
{
	gfx.PutPixel(x + 0, y + 3, 0, 0, 0);
	gfx.PutPixel(x + 0, y + 4, 0, 0, 0);
	gfx.PutPixel(x + 0, y + 5, 0, 0, 0);
	gfx.PutPixel(x + 0, y + 6, 0, 0, 0);
	gfx.PutPixel(x + 0, y + 7, 0, 0, 0);
	gfx.PutPixel(x + 0, y + 8, 0, 0, 0);
	gfx.PutPixel(x + 0, y + 9, 0, 0, 0);
	gfx.PutPixel(x + 0, y + 10, 0, 0, 0);
	gfx.PutPixel(x + 0, y + 11, 0, 0, 0);
	gfx.PutPixel(x + 0, y + 12, 0, 0, 0);
	gfx.PutPixel(x + 1, y + 1, 0, 0, 0);
	gfx.PutPixel(x + 1, y + 2, 0, 0, 0);
	gfx.PutPixel(x + 1, y + 3, 0, 0, 0);
	gfx.PutPixel(x + 1, y + 4, 104, 255, 0);
	gfx.PutPixel(x + 1, y + 5, 104, 255, 0);
	gfx.PutPixel(x + 1, y + 6, 104, 255, 0);
	gfx.PutPixel(x + 1, y + 7, 104, 255, 0);
	gfx.PutPixel(x + 1, y + 8, 104, 255, 0);
	gfx.PutPixel(x + 1, y + 9, 104, 255, 0);
	gfx.PutPixel(x + 1, y + 10, 104, 255, 0);
	gfx.PutPixel(x + 1, y + 11, 104, 255, 0);
	gfx.PutPixel(x + 1, y + 12, 0, 0, 0);
	gfx.PutPixel(x + 1, y + 13, 0, 0, 0);
	gfx.PutPixel(x + 1, y + 14, 0, 0, 0);
	gfx.PutPixel(x + 1, y + 15, 0, 0, 0);
	gfx.PutPixel(x + 2, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 2, y + 1, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 2, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 3, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 4, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 5, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 6, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 7, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 8, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 9, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 10, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 11, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 12, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 13, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 14, 104, 255, 0);
	gfx.PutPixel(x + 2, y + 15, 0, 0, 0);
	gfx.PutPixel(x + 2, y + 16, 0, 0, 0);
	gfx.PutPixel(x + 2, y + 17, 0, 0, 0);
	gfx.PutPixel(x + 3, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 3, y + 1, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 2, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 3, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 4, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 5, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 6, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 7, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 8, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 9, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 10, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 11, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 12, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 13, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 14, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 17, 104, 255, 0);
	gfx.PutPixel(x + 3, y + 18, 0, 0, 0);
	gfx.PutPixel(x + 3, y + 19, 0, 0, 0);
	gfx.PutPixel(x + 3, y + 20, 0, 0, 0);
	gfx.PutPixel(x + 4, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 4, y + 1, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 2, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 3, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 4, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 5, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 6, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 7, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 8, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 9, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 10, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 11, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 12, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 13, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 14, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 17, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 18, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 19, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 20, 104, 255, 0);
	gfx.PutPixel(x + 4, y + 21, 0, 0, 0);
	gfx.PutPixel(x + 4, y + 22, 0, 0, 0);
	gfx.PutPixel(x + 5, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 5, y + 1, 104, 255, 0);
	gfx.PutPixel(x + 5, y + 2, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 3, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 4, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 5, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 6, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 7, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 8, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 9, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 10, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 11, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 12, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 13, 71, 104, 255);
	gfx.PutPixel(x + 5, y + 14, 104, 255, 0);
	gfx.PutPixel(x + 5, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 5, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 5, y + 17, 104, 255, 0);
	gfx.PutPixel(x + 5, y + 18, 104, 255, 0);
	gfx.PutPixel(x + 5, y + 19, 104, 255, 0);
	gfx.PutPixel(x + 5, y + 20, 104, 255, 0);
	gfx.PutPixel(x + 5, y + 21, 104, 255, 0);
	gfx.PutPixel(x + 5, y + 22, 104, 255, 0);
	gfx.PutPixel(x + 5, y + 23, 0, 0, 0);
	gfx.PutPixel(x + 6, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 6, y + 1, 71, 104, 255);
	gfx.PutPixel(x + 6, y + 2, 71, 104, 255);
	gfx.PutPixel(x + 6, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 5, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 6, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 10, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 11, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 12, 255, 255, 255);
	gfx.PutPixel(x + 6, y + 13, 71, 104, 255);
	gfx.PutPixel(x + 6, y + 14, 71, 104, 255);
	gfx.PutPixel(x + 6, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 6, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 6, y + 17, 104, 255, 0);
	gfx.PutPixel(x + 6, y + 18, 104, 255, 0);
	gfx.PutPixel(x + 6, y + 19, 104, 255, 0);
	gfx.PutPixel(x + 6, y + 20, 104, 255, 0);
	gfx.PutPixel(x + 6, y + 21, 104, 255, 0);
	gfx.PutPixel(x + 6, y + 22, 104, 255, 0);
	gfx.PutPixel(x + 6, y + 23, 104, 255, 0);
	gfx.PutPixel(x + 7, y + 0, 71, 104, 255);
	gfx.PutPixel(x + 7, y + 1, 71, 104, 255);
	gfx.PutPixel(x + 7, y + 2, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 5, 255, 58, 0);
	gfx.PutPixel(x + 7, y + 6, 255, 58, 0);
	gfx.PutPixel(x + 7, y + 7, 255, 58, 0);
	gfx.PutPixel(x + 7, y + 8, 255, 58, 0);
	gfx.PutPixel(x + 7, y + 9, 255, 58, 0);
	gfx.PutPixel(x + 7, y + 10, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 11, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 12, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 13, 255, 255, 255);
	gfx.PutPixel(x + 7, y + 14, 71, 104, 255);
	gfx.PutPixel(x + 7, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 7, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 7, y + 17, 104, 255, 0);
	gfx.PutPixel(x + 7, y + 18, 104, 255, 0);
	gfx.PutPixel(x + 7, y + 19, 71, 104, 255);
	gfx.PutPixel(x + 7, y + 20, 71, 104, 255);
	gfx.PutPixel(x + 7, y + 21, 71, 104, 255);
	gfx.PutPixel(x + 7, y + 22, 71, 104, 255);
	gfx.PutPixel(x + 7, y + 23, 104, 255, 0);
	gfx.PutPixel(x + 8, y + 0, 71, 104, 255);
	gfx.PutPixel(x + 8, y + 1, 71, 104, 255);
	gfx.PutPixel(x + 8, y + 2, 71, 104, 255);
	gfx.PutPixel(x + 8, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 5, 255, 58, 0);
	gfx.PutPixel(x + 8, y + 6, 255, 58, 0);
	gfx.PutPixel(x + 8, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 10, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 11, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 12, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 13, 71, 104, 255);
	gfx.PutPixel(x + 8, y + 14, 71, 104, 255);
	gfx.PutPixel(x + 8, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 8, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 8, y + 17, 71, 104, 255);
	gfx.PutPixel(x + 8, y + 18, 71, 104, 255);
	gfx.PutPixel(x + 8, y + 19, 71, 104, 255);
	gfx.PutPixel(x + 8, y + 20, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 21, 255, 255, 255);
	gfx.PutPixel(x + 8, y + 22, 71, 104, 255);
	gfx.PutPixel(x + 8, y + 23, 71, 104, 255);
	gfx.PutPixel(x + 9, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 9, y + 1, 71, 104, 255);
	gfx.PutPixel(x + 9, y + 2, 71, 104, 255);
	gfx.PutPixel(x + 9, y + 3, 71, 104, 255);
	gfx.PutPixel(x + 9, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 5, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 6, 255, 58, 0);
	gfx.PutPixel(x + 9, y + 7, 255, 58, 0);
	gfx.PutPixel(x + 9, y + 8, 255, 58, 0);
	gfx.PutPixel(x + 9, y + 9, 255, 58, 0);
	gfx.PutPixel(x + 9, y + 10, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 11, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 12, 71, 104, 255);
	gfx.PutPixel(x + 9, y + 13, 71, 104, 255);
	gfx.PutPixel(x + 9, y + 14, 104, 255, 0);
	gfx.PutPixel(x + 9, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 9, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 9, y + 17, 71, 104, 255);
	gfx.PutPixel(x + 9, y + 18, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 19, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 20, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 21, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 22, 255, 255, 255);
	gfx.PutPixel(x + 9, y + 23, 71, 104, 255);
	gfx.PutPixel(x + 10, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 10, y + 1, 0, 255, 0);
	gfx.PutPixel(x + 10, y + 2, 71, 104, 255);
	gfx.PutPixel(x + 10, y + 3, 71, 104, 255);
	gfx.PutPixel(x + 10, y + 4, 71, 104, 255);
	gfx.PutPixel(x + 10, y + 5, 255, 255, 255);
	gfx.PutPixel(x + 10, y + 6, 255, 255, 255);
	gfx.PutPixel(x + 10, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 10, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 10, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 10, y + 10, 255, 255, 255);
	gfx.PutPixel(x + 10, y + 11, 71, 104, 255);
	gfx.PutPixel(x + 10, y + 12, 71, 104, 255);
	gfx.PutPixel(x + 10, y + 13, 71, 104, 255);
	gfx.PutPixel(x + 10, y + 14, 104, 255, 0);
	gfx.PutPixel(x + 10, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 10, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 10, y + 17, 71, 104, 255);
	gfx.PutPixel(x + 10, y + 18, 255, 255, 255);
	gfx.PutPixel(x + 10, y + 19, 255, 255, 255);
	gfx.PutPixel(x + 10, y + 20, 255, 255, 255);
	gfx.PutPixel(x + 10, y + 21, 255, 255, 255);
	gfx.PutPixel(x + 10, y + 22, 255, 255, 255);
	gfx.PutPixel(x + 10, y + 23, 71, 104, 255);
	gfx.PutPixel(x + 11, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 11, y + 1, 0, 255, 0);
	gfx.PutPixel(x + 11, y + 2, 0, 255, 0);
	gfx.PutPixel(x + 11, y + 3, 71, 104, 255);
	gfx.PutPixel(x + 11, y + 4, 71, 104, 255);
	gfx.PutPixel(x + 11, y + 5, 255, 255, 255);
	gfx.PutPixel(x + 11, y + 6, 255, 255, 255);
	gfx.PutPixel(x + 11, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 11, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 11, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 11, y + 10, 255, 255, 255);
	gfx.PutPixel(x + 11, y + 11, 255, 255, 255);
	gfx.PutPixel(x + 11, y + 12, 255, 255, 255);
	gfx.PutPixel(x + 11, y + 13, 71, 104, 255);
	gfx.PutPixel(x + 11, y + 14, 71, 104, 255);
	gfx.PutPixel(x + 11, y + 15, 71, 104, 255);
	gfx.PutPixel(x + 11, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 11, y + 17, 71, 104, 255);
	gfx.PutPixel(x + 11, y + 18, 71, 104, 255);
	gfx.PutPixel(x + 11, y + 19, 255, 255, 255);
	gfx.PutPixel(x + 11, y + 20, 255, 255, 255);
	gfx.PutPixel(x + 11, y + 21, 255, 255, 255);
	gfx.PutPixel(x + 11, y + 22, 71, 104, 255);
	gfx.PutPixel(x + 11, y + 23, 71, 104, 255);
	gfx.PutPixel(x + 12, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 12, y + 1, 71, 104, 255);
	gfx.PutPixel(x + 12, y + 2, 71, 104, 255);
	gfx.PutPixel(x + 12, y + 3, 71, 104, 255);
	gfx.PutPixel(x + 12, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 12, y + 5, 255, 255, 255);
	gfx.PutPixel(x + 12, y + 6, 255, 255, 255);
	gfx.PutPixel(x + 12, y + 7, 255, 58, 0);
	gfx.PutPixel(x + 12, y + 8, 255, 58, 0);
	gfx.PutPixel(x + 12, y + 9, 255, 58, 0);
	gfx.PutPixel(x + 12, y + 10, 255, 58, 0);
	gfx.PutPixel(x + 12, y + 11, 255, 58, 0);
	gfx.PutPixel(x + 12, y + 12, 255, 255, 255);
	gfx.PutPixel(x + 12, y + 13, 255, 255, 255);
	gfx.PutPixel(x + 12, y + 14, 255, 255, 255);
	gfx.PutPixel(x + 12, y + 15, 71, 104, 255);
	gfx.PutPixel(x + 12, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 12, y + 17, 104, 255, 0);
	gfx.PutPixel(x + 12, y + 18, 71, 104, 255);
	gfx.PutPixel(x + 12, y + 19, 71, 104, 255);
	gfx.PutPixel(x + 12, y + 20, 71, 104, 255);
	gfx.PutPixel(x + 12, y + 21, 71, 104, 255);
	gfx.PutPixel(x + 12, y + 22, 71, 104, 255);
	gfx.PutPixel(x + 12, y + 23, 104, 255, 0);
	gfx.PutPixel(x + 13, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 13, y + 1, 71, 104, 255);
	gfx.PutPixel(x + 13, y + 2, 71, 104, 255);
	gfx.PutPixel(x + 13, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 13, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 13, y + 5, 255, 255, 255);
	gfx.PutPixel(x + 13, y + 6, 255, 255, 255);
	gfx.PutPixel(x + 13, y + 7, 255, 58, 0);
	gfx.PutPixel(x + 13, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 13, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 13, y + 10, 255, 255, 255);
	gfx.PutPixel(x + 13, y + 11, 255, 255, 255);
	gfx.PutPixel(x + 13, y + 12, 255, 255, 255);
	gfx.PutPixel(x + 13, y + 13, 255, 255, 255);
	gfx.PutPixel(x + 13, y + 14, 255, 255, 255);
	gfx.PutPixel(x + 13, y + 15, 71, 104, 255);
	gfx.PutPixel(x + 13, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 13, y + 17, 104, 255, 0);
	gfx.PutPixel(x + 13, y + 18, 104, 255, 0);
	gfx.PutPixel(x + 13, y + 19, 104, 255, 0);
	gfx.PutPixel(x + 13, y + 20, 104, 255, 0);
	gfx.PutPixel(x + 13, y + 21, 104, 255, 0);
	gfx.PutPixel(x + 13, y + 22, 104, 255, 0);
	gfx.PutPixel(x + 13, y + 23, 104, 255, 0);
	gfx.PutPixel(x + 14, y + 0, 71, 104, 255);
	gfx.PutPixel(x + 14, y + 1, 71, 104, 255);
	gfx.PutPixel(x + 14, y + 2, 71, 104, 255);
	gfx.PutPixel(x + 14, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 14, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 14, y + 5, 255, 255, 255);
	gfx.PutPixel(x + 14, y + 6, 255, 255, 255);
	gfx.PutPixel(x + 14, y + 7, 255, 58, 0);
	gfx.PutPixel(x + 14, y + 8, 255, 58, 0);
	gfx.PutPixel(x + 14, y + 9, 255, 58, 0);
	gfx.PutPixel(x + 14, y + 10, 255, 58, 0);
	gfx.PutPixel(x + 14, y + 11, 255, 58, 0);
	gfx.PutPixel(x + 14, y + 12, 255, 255, 255);
	gfx.PutPixel(x + 14, y + 13, 255, 255, 255);
	gfx.PutPixel(x + 14, y + 14, 71, 104, 255);
	gfx.PutPixel(x + 14, y + 15, 71, 104, 255);
	gfx.PutPixel(x + 14, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 14, y + 17, 104, 255, 0);
	gfx.PutPixel(x + 14, y + 18, 104, 255, 0);
	gfx.PutPixel(x + 14, y + 19, 104, 255, 0);
	gfx.PutPixel(x + 14, y + 20, 104, 255, 0);
	gfx.PutPixel(x + 14, y + 21, 104, 255, 0);
	gfx.PutPixel(x + 14, y + 22, 104, 255, 0);
	gfx.PutPixel(x + 14, y + 23, 0, 0, 0);
	gfx.PutPixel(x + 15, y + 0, 71, 104, 255);
	gfx.PutPixel(x + 15, y + 1, 104, 255, 0);
	gfx.PutPixel(x + 15, y + 2, 71, 104, 255);
	gfx.PutPixel(x + 15, y + 3, 255, 255, 255);
	gfx.PutPixel(x + 15, y + 4, 255, 255, 255);
	gfx.PutPixel(x + 15, y + 5, 255, 255, 255);
	gfx.PutPixel(x + 15, y + 6, 255, 255, 255);
	gfx.PutPixel(x + 15, y + 7, 255, 255, 255);
	gfx.PutPixel(x + 15, y + 8, 255, 255, 255);
	gfx.PutPixel(x + 15, y + 9, 255, 255, 255);
	gfx.PutPixel(x + 15, y + 10, 255, 255, 255);
	gfx.PutPixel(x + 15, y + 11, 255, 255, 255);
	gfx.PutPixel(x + 15, y + 12, 71, 104, 255);
	gfx.PutPixel(x + 15, y + 13, 71, 104, 255);
	gfx.PutPixel(x + 15, y + 14, 71, 104, 255);
	gfx.PutPixel(x + 15, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 15, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 15, y + 17, 104, 255, 0);
	gfx.PutPixel(x + 15, y + 18, 104, 255, 0);
	gfx.PutPixel(x + 15, y + 19, 104, 255, 0);
	gfx.PutPixel(x + 15, y + 20, 104, 255, 0);
	gfx.PutPixel(x + 15, y + 21, 104, 255, 0);
	gfx.PutPixel(x + 15, y + 22, 0, 0, 0);
	gfx.PutPixel(x + 15, y + 23, 0, 0, 0);
	gfx.PutPixel(x + 16, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 16, y + 1, 104, 255, 0);
	gfx.PutPixel(x + 16, y + 2, 71, 104, 255);
	gfx.PutPixel(x + 16, y + 3, 71, 104, 255);
	gfx.PutPixel(x + 16, y + 4, 71, 104, 255);
	gfx.PutPixel(x + 16, y + 5, 71, 104, 255);
	gfx.PutPixel(x + 16, y + 6, 71, 104, 255);
	gfx.PutPixel(x + 16, y + 7, 71, 104, 255);
	gfx.PutPixel(x + 16, y + 8, 71, 104, 255);
	gfx.PutPixel(x + 16, y + 9, 71, 104, 255);
	gfx.PutPixel(x + 16, y + 10, 71, 104, 255);
	gfx.PutPixel(x + 16, y + 11, 71, 104, 255);
	gfx.PutPixel(x + 16, y + 12, 104, 255, 0);
	gfx.PutPixel(x + 16, y + 13, 104, 255, 0);
	gfx.PutPixel(x + 16, y + 14, 104, 255, 0);
	gfx.PutPixel(x + 16, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 16, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 16, y + 17, 104, 255, 0);
	gfx.PutPixel(x + 16, y + 18, 104, 255, 0);
	gfx.PutPixel(x + 16, y + 19, 104, 255, 0);
	gfx.PutPixel(x + 16, y + 20, 104, 255, 0);
	gfx.PutPixel(x + 16, y + 21, 0, 0, 0);
	gfx.PutPixel(x + 16, y + 22, 0, 0, 0);
	gfx.PutPixel(x + 17, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 17, y + 1, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 2, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 3, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 4, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 5, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 6, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 7, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 8, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 9, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 10, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 11, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 12, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 13, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 14, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 16, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 17, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 18, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 19, 104, 255, 0);
	gfx.PutPixel(x + 17, y + 20, 0, 0, 0);
	gfx.PutPixel(x + 17, y + 21, 0, 0, 0);
	gfx.PutPixel(x + 18, y + 0, 0, 0, 0);
	gfx.PutPixel(x + 18, y + 1, 0, 0, 0);
	gfx.PutPixel(x + 18, y + 2, 0, 0, 0);
	gfx.PutPixel(x + 18, y + 3, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 4, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 5, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 6, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 7, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 8, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 9, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 10, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 11, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 12, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 13, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 14, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 15, 104, 255, 0);
	gfx.PutPixel(x + 18, y + 16, 0, 0, 0);
	gfx.PutPixel(x + 18, y + 17, 0, 0, 0);
	gfx.PutPixel(x + 18, y + 18, 0, 0, 0);
	gfx.PutPixel(x + 18, y + 19, 0, 0, 0);
	gfx.PutPixel(x + 18, y + 20, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 2, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 3, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 4, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 5, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 6, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 7, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 8, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 9, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 10, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 11, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 12, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 13, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 14, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 15, 0, 0, 0);
	gfx.PutPixel(x + 19, y + 16, 0, 0, 0);
}

