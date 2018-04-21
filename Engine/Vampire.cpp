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
	}
}

void Vampire::init(int setx, int sety)
{
	x = float(setx);
	y = float(sety);
}

void Vampire::update(const Keyboard & kbd)
{
	// left right
	if (kbd.KeyIsPressed(VK_LEFT) || kbd.KeyIsPressed('A'))
	{
		if (vx > -speed)
		{	//accelerate negative
			vx -= accel;
		}
	}
	else if (kbd.KeyIsPressed(VK_RIGHT) || kbd.KeyIsPressed('D'))
	{
		if (vx < speed)
		{
			vx += accel;
		}
	}
	else
	{
		//slow down when no key is pressed.
		if (vx > 0.0f)
		{
			vx -= accel;
		}
		else if (vx < 0.0f)
		{
			vx += accel;
		}
	}
	// up down
	if (kbd.KeyIsPressed(VK_UP) || kbd.KeyIsPressed('W'))
	{	
		if (vy > -speed)
		{	//decelerate
			vy -= accel;
		}
	}
	else if (kbd.KeyIsPressed(VK_DOWN) || kbd.KeyIsPressed('S'))
	{
		if (vy < speed)
		{	//accelerate
			vy += accel;
		}
	}
	else
	{
		if (vy > 0.0f)
		{
			vy -= accel;
		}
		else if (vy < 0.0f)
		{
			vy += accel;
		}
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
	gfx.Rectangle(int(x), int(y), int(x + width), int(y + height), 2, cvamp);
}

void Vampire::skull(Graphics & gfx)
{
	int x_int = int(x);
	int y_int = int(y);
	gfx.PutPixel(x_int + 0, y_int + 3, 0, 0, 0);
	gfx.PutPixel(x_int + 0, y_int + 4, 0, 0, 0);
	gfx.PutPixel(x_int + 0, y_int + 5, 0, 0, 0);
	gfx.PutPixel(x_int + 0, y_int + 6, 0, 0, 0);
	gfx.PutPixel(x_int + 0, y_int + 7, 0, 0, 0);
	gfx.PutPixel(x_int + 0, y_int + 8, 0, 0, 0);
	gfx.PutPixel(x_int + 0, y_int + 9, 0, 0, 0);
	gfx.PutPixel(x_int + 0, y_int + 10, 0, 0, 0);
	gfx.PutPixel(x_int + 0, y_int + 11, 0, 0, 0);
	gfx.PutPixel(x_int + 0, y_int + 12, 0, 0, 0);
	gfx.PutPixel(x_int + 1, y_int + 1, 0, 0, 0);
	gfx.PutPixel(x_int + 1, y_int + 2, 0, 0, 0);
	gfx.PutPixel(x_int + 1, y_int + 3, 0, 0, 0);
	gfx.PutPixel(x_int + 1, y_int + 4, 104, 255, 0);
	gfx.PutPixel(x_int + 1, y_int + 5, 104, 255, 0);
	gfx.PutPixel(x_int + 1, y_int + 6, 104, 255, 0);
	gfx.PutPixel(x_int + 1, y_int + 7, 104, 255, 0);
	gfx.PutPixel(x_int + 1, y_int + 8, 104, 255, 0);
	gfx.PutPixel(x_int + 1, y_int + 9, 104, 255, 0);
	gfx.PutPixel(x_int + 1, y_int + 10, 104, 255, 0);
	gfx.PutPixel(x_int + 1, y_int + 11, 104, 255, 0);
	gfx.PutPixel(x_int + 1, y_int + 12, 0, 0, 0);
	gfx.PutPixel(x_int + 1, y_int + 13, 0, 0, 0);
	gfx.PutPixel(x_int + 1, y_int + 14, 0, 0, 0);
	gfx.PutPixel(x_int + 1, y_int + 15, 0, 0, 0);
	gfx.PutPixel(x_int + 2, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 2, y_int + 1, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 2, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 3, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 4, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 5, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 6, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 7, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 8, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 9, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 10, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 11, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 12, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 13, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 14, 104, 255, 0);
	gfx.PutPixel(x_int + 2, y_int + 15, 0, 0, 0);
	gfx.PutPixel(x_int + 2, y_int + 16, 0, 0, 0);
	gfx.PutPixel(x_int + 2, y_int + 17, 0, 0, 0);
	gfx.PutPixel(x_int + 3, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 3, y_int + 1, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 2, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 3, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 4, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 5, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 6, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 7, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 8, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 9, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 10, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 11, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 12, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 13, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 14, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 17, 104, 255, 0);
	gfx.PutPixel(x_int + 3, y_int + 18, 0, 0, 0);
	gfx.PutPixel(x_int + 3, y_int + 19, 0, 0, 0);
	gfx.PutPixel(x_int + 3, y_int + 20, 0, 0, 0);
	gfx.PutPixel(x_int + 4, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 4, y_int + 1, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 2, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 3, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 4, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 5, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 6, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 7, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 8, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 9, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 10, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 11, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 12, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 13, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 14, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 17, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 18, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 19, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 20, 104, 255, 0);
	gfx.PutPixel(x_int + 4, y_int + 21, 0, 0, 0);
	gfx.PutPixel(x_int + 4, y_int + 22, 0, 0, 0);
	gfx.PutPixel(x_int + 5, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 5, y_int + 1, 104, 255, 0);
	gfx.PutPixel(x_int + 5, y_int + 2, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 3, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 4, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 5, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 6, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 7, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 8, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 9, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 10, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 11, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 12, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 13, 71, 104, 255);
	gfx.PutPixel(x_int + 5, y_int + 14, 104, 255, 0);
	gfx.PutPixel(x_int + 5, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 5, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 5, y_int + 17, 104, 255, 0);
	gfx.PutPixel(x_int + 5, y_int + 18, 104, 255, 0);
	gfx.PutPixel(x_int + 5, y_int + 19, 104, 255, 0);
	gfx.PutPixel(x_int + 5, y_int + 20, 104, 255, 0);
	gfx.PutPixel(x_int + 5, y_int + 21, 104, 255, 0);
	gfx.PutPixel(x_int + 5, y_int + 22, 104, 255, 0);
	gfx.PutPixel(x_int + 5, y_int + 23, 0, 0, 0);
	gfx.PutPixel(x_int + 6, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 6, y_int + 1, 71, 104, 255);
	gfx.PutPixel(x_int + 6, y_int + 2, 71, 104, 255);
	gfx.PutPixel(x_int + 6, y_int + 3, 255, 255, 255);
	gfx.PutPixel(x_int + 6, y_int + 4, 255, 255, 255);
	gfx.PutPixel(x_int + 6, y_int + 5, 255, 255, 255);
	gfx.PutPixel(x_int + 6, y_int + 6, 255, 255, 255);
	gfx.PutPixel(x_int + 6, y_int + 7, 255, 255, 255);
	gfx.PutPixel(x_int + 6, y_int + 8, 255, 255, 255);
	gfx.PutPixel(x_int + 6, y_int + 9, 255, 255, 255);
	gfx.PutPixel(x_int + 6, y_int + 10, 255, 255, 255);
	gfx.PutPixel(x_int + 6, y_int + 11, 255, 255, 255);
	gfx.PutPixel(x_int + 6, y_int + 12, 255, 255, 255);
	gfx.PutPixel(x_int + 6, y_int + 13, 71, 104, 255);
	gfx.PutPixel(x_int + 6, y_int + 14, 71, 104, 255);
	gfx.PutPixel(x_int + 6, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 6, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 6, y_int + 17, 104, 255, 0);
	gfx.PutPixel(x_int + 6, y_int + 18, 104, 255, 0);
	gfx.PutPixel(x_int + 6, y_int + 19, 104, 255, 0);
	gfx.PutPixel(x_int + 6, y_int + 20, 104, 255, 0);
	gfx.PutPixel(x_int + 6, y_int + 21, 104, 255, 0);
	gfx.PutPixel(x_int + 6, y_int + 22, 104, 255, 0);
	gfx.PutPixel(x_int + 6, y_int + 23, 104, 255, 0);
	gfx.PutPixel(x_int + 7, y_int + 0, 71, 104, 255);
	gfx.PutPixel(x_int + 7, y_int + 1, 71, 104, 255);
	gfx.PutPixel(x_int + 7, y_int + 2, 255, 255, 255);
	gfx.PutPixel(x_int + 7, y_int + 3, 255, 255, 255);
	gfx.PutPixel(x_int + 7, y_int + 4, 255, 255, 255);
	gfx.PutPixel(x_int + 7, y_int + 5, 255, 58, 0);
	gfx.PutPixel(x_int + 7, y_int + 6, 255, 58, 0);
	gfx.PutPixel(x_int + 7, y_int + 7, 255, 58, 0);
	gfx.PutPixel(x_int + 7, y_int + 8, 255, 58, 0);
	gfx.PutPixel(x_int + 7, y_int + 9, 255, 58, 0);
	gfx.PutPixel(x_int + 7, y_int + 10, 255, 255, 255);
	gfx.PutPixel(x_int + 7, y_int + 11, 255, 255, 255);
	gfx.PutPixel(x_int + 7, y_int + 12, 255, 255, 255);
	gfx.PutPixel(x_int + 7, y_int + 13, 255, 255, 255);
	gfx.PutPixel(x_int + 7, y_int + 14, 71, 104, 255);
	gfx.PutPixel(x_int + 7, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 7, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 7, y_int + 17, 104, 255, 0);
	gfx.PutPixel(x_int + 7, y_int + 18, 104, 255, 0);
	gfx.PutPixel(x_int + 7, y_int + 19, 71, 104, 255);
	gfx.PutPixel(x_int + 7, y_int + 20, 71, 104, 255);
	gfx.PutPixel(x_int + 7, y_int + 21, 71, 104, 255);
	gfx.PutPixel(x_int + 7, y_int + 22, 71, 104, 255);
	gfx.PutPixel(x_int + 7, y_int + 23, 104, 255, 0);
	gfx.PutPixel(x_int + 8, y_int + 0, 71, 104, 255);
	gfx.PutPixel(x_int + 8, y_int + 1, 71, 104, 255);
	gfx.PutPixel(x_int + 8, y_int + 2, 71, 104, 255);
	gfx.PutPixel(x_int + 8, y_int + 3, 255, 255, 255);
	gfx.PutPixel(x_int + 8, y_int + 4, 255, 255, 255);
	gfx.PutPixel(x_int + 8, y_int + 5, 255, 58, 0);
	gfx.PutPixel(x_int + 8, y_int + 6, 255, 58, 0);
	gfx.PutPixel(x_int + 8, y_int + 7, 255, 255, 255);
	gfx.PutPixel(x_int + 8, y_int + 8, 255, 255, 255);
	gfx.PutPixel(x_int + 8, y_int + 9, 255, 255, 255);
	gfx.PutPixel(x_int + 8, y_int + 10, 255, 255, 255);
	gfx.PutPixel(x_int + 8, y_int + 11, 255, 255, 255);
	gfx.PutPixel(x_int + 8, y_int + 12, 255, 255, 255);
	gfx.PutPixel(x_int + 8, y_int + 13, 71, 104, 255);
	gfx.PutPixel(x_int + 8, y_int + 14, 71, 104, 255);
	gfx.PutPixel(x_int + 8, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 8, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 8, y_int + 17, 71, 104, 255);
	gfx.PutPixel(x_int + 8, y_int + 18, 71, 104, 255);
	gfx.PutPixel(x_int + 8, y_int + 19, 71, 104, 255);
	gfx.PutPixel(x_int + 8, y_int + 20, 255, 255, 255);
	gfx.PutPixel(x_int + 8, y_int + 21, 255, 255, 255);
	gfx.PutPixel(x_int + 8, y_int + 22, 71, 104, 255);
	gfx.PutPixel(x_int + 8, y_int + 23, 71, 104, 255);
	gfx.PutPixel(x_int + 9, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 9, y_int + 1, 71, 104, 255);
	gfx.PutPixel(x_int + 9, y_int + 2, 71, 104, 255);
	gfx.PutPixel(x_int + 9, y_int + 3, 71, 104, 255);
	gfx.PutPixel(x_int + 9, y_int + 4, 255, 255, 255);
	gfx.PutPixel(x_int + 9, y_int + 5, 255, 255, 255);
	gfx.PutPixel(x_int + 9, y_int + 6, 255, 58, 0);
	gfx.PutPixel(x_int + 9, y_int + 7, 255, 58, 0);
	gfx.PutPixel(x_int + 9, y_int + 8, 255, 58, 0);
	gfx.PutPixel(x_int + 9, y_int + 9, 255, 58, 0);
	gfx.PutPixel(x_int + 9, y_int + 10, 255, 255, 255);
	gfx.PutPixel(x_int + 9, y_int + 11, 255, 255, 255);
	gfx.PutPixel(x_int + 9, y_int + 12, 71, 104, 255);
	gfx.PutPixel(x_int + 9, y_int + 13, 71, 104, 255);
	gfx.PutPixel(x_int + 9, y_int + 14, 104, 255, 0);
	gfx.PutPixel(x_int + 9, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 9, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 9, y_int + 17, 71, 104, 255);
	gfx.PutPixel(x_int + 9, y_int + 18, 255, 255, 255);
	gfx.PutPixel(x_int + 9, y_int + 19, 255, 255, 255);
	gfx.PutPixel(x_int + 9, y_int + 20, 255, 255, 255);
	gfx.PutPixel(x_int + 9, y_int + 21, 255, 255, 255);
	gfx.PutPixel(x_int + 9, y_int + 22, 255, 255, 255);
	gfx.PutPixel(x_int + 9, y_int + 23, 71, 104, 255);
	gfx.PutPixel(x_int + 10, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 10, y_int + 1, 0, 255, 0);
	gfx.PutPixel(x_int + 10, y_int + 2, 71, 104, 255);
	gfx.PutPixel(x_int + 10, y_int + 3, 71, 104, 255);
	gfx.PutPixel(x_int + 10, y_int + 4, 71, 104, 255);
	gfx.PutPixel(x_int + 10, y_int + 5, 255, 255, 255);
	gfx.PutPixel(x_int + 10, y_int + 6, 255, 255, 255);
	gfx.PutPixel(x_int + 10, y_int + 7, 255, 255, 255);
	gfx.PutPixel(x_int + 10, y_int + 8, 255, 255, 255);
	gfx.PutPixel(x_int + 10, y_int + 9, 255, 255, 255);
	gfx.PutPixel(x_int + 10, y_int + 10, 255, 255, 255);
	gfx.PutPixel(x_int + 10, y_int + 11, 71, 104, 255);
	gfx.PutPixel(x_int + 10, y_int + 12, 71, 104, 255);
	gfx.PutPixel(x_int + 10, y_int + 13, 71, 104, 255);
	gfx.PutPixel(x_int + 10, y_int + 14, 104, 255, 0);
	gfx.PutPixel(x_int + 10, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 10, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 10, y_int + 17, 71, 104, 255);
	gfx.PutPixel(x_int + 10, y_int + 18, 255, 255, 255);
	gfx.PutPixel(x_int + 10, y_int + 19, 255, 255, 255);
	gfx.PutPixel(x_int + 10, y_int + 20, 255, 255, 255);
	gfx.PutPixel(x_int + 10, y_int + 21, 255, 255, 255);
	gfx.PutPixel(x_int + 10, y_int + 22, 255, 255, 255);
	gfx.PutPixel(x_int + 10, y_int + 23, 71, 104, 255);
	gfx.PutPixel(x_int + 11, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 11, y_int + 1, 0, 255, 0);
	gfx.PutPixel(x_int + 11, y_int + 2, 0, 255, 0);
	gfx.PutPixel(x_int + 11, y_int + 3, 71, 104, 255);
	gfx.PutPixel(x_int + 11, y_int + 4, 71, 104, 255);
	gfx.PutPixel(x_int + 11, y_int + 5, 255, 255, 255);
	gfx.PutPixel(x_int + 11, y_int + 6, 255, 255, 255);
	gfx.PutPixel(x_int + 11, y_int + 7, 255, 255, 255);
	gfx.PutPixel(x_int + 11, y_int + 8, 255, 255, 255);
	gfx.PutPixel(x_int + 11, y_int + 9, 255, 255, 255);
	gfx.PutPixel(x_int + 11, y_int + 10, 255, 255, 255);
	gfx.PutPixel(x_int + 11, y_int + 11, 255, 255, 255);
	gfx.PutPixel(x_int + 11, y_int + 12, 255, 255, 255);
	gfx.PutPixel(x_int + 11, y_int + 13, 71, 104, 255);
	gfx.PutPixel(x_int + 11, y_int + 14, 71, 104, 255);
	gfx.PutPixel(x_int + 11, y_int + 15, 71, 104, 255);
	gfx.PutPixel(x_int + 11, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 11, y_int + 17, 71, 104, 255);
	gfx.PutPixel(x_int + 11, y_int + 18, 71, 104, 255);
	gfx.PutPixel(x_int + 11, y_int + 19, 255, 255, 255);
	gfx.PutPixel(x_int + 11, y_int + 20, 255, 255, 255);
	gfx.PutPixel(x_int + 11, y_int + 21, 255, 255, 255);
	gfx.PutPixel(x_int + 11, y_int + 22, 71, 104, 255);
	gfx.PutPixel(x_int + 11, y_int + 23, 71, 104, 255);
	gfx.PutPixel(x_int + 12, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 12, y_int + 1, 71, 104, 255);
	gfx.PutPixel(x_int + 12, y_int + 2, 71, 104, 255);
	gfx.PutPixel(x_int + 12, y_int + 3, 71, 104, 255);
	gfx.PutPixel(x_int + 12, y_int + 4, 255, 255, 255);
	gfx.PutPixel(x_int + 12, y_int + 5, 255, 255, 255);
	gfx.PutPixel(x_int + 12, y_int + 6, 255, 255, 255);
	gfx.PutPixel(x_int + 12, y_int + 7, 255, 58, 0);
	gfx.PutPixel(x_int + 12, y_int + 8, 255, 58, 0);
	gfx.PutPixel(x_int + 12, y_int + 9, 255, 58, 0);
	gfx.PutPixel(x_int + 12, y_int + 10, 255, 58, 0);
	gfx.PutPixel(x_int + 12, y_int + 11, 255, 58, 0);
	gfx.PutPixel(x_int + 12, y_int + 12, 255, 255, 255);
	gfx.PutPixel(x_int + 12, y_int + 13, 255, 255, 255);
	gfx.PutPixel(x_int + 12, y_int + 14, 255, 255, 255);
	gfx.PutPixel(x_int + 12, y_int + 15, 71, 104, 255);
	gfx.PutPixel(x_int + 12, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 12, y_int + 17, 104, 255, 0);
	gfx.PutPixel(x_int + 12, y_int + 18, 71, 104, 255);
	gfx.PutPixel(x_int + 12, y_int + 19, 71, 104, 255);
	gfx.PutPixel(x_int + 12, y_int + 20, 71, 104, 255);
	gfx.PutPixel(x_int + 12, y_int + 21, 71, 104, 255);
	gfx.PutPixel(x_int + 12, y_int + 22, 71, 104, 255);
	gfx.PutPixel(x_int + 12, y_int + 23, 104, 255, 0);
	gfx.PutPixel(x_int + 13, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 13, y_int + 1, 71, 104, 255);
	gfx.PutPixel(x_int + 13, y_int + 2, 71, 104, 255);
	gfx.PutPixel(x_int + 13, y_int + 3, 255, 255, 255);
	gfx.PutPixel(x_int + 13, y_int + 4, 255, 255, 255);
	gfx.PutPixel(x_int + 13, y_int + 5, 255, 255, 255);
	gfx.PutPixel(x_int + 13, y_int + 6, 255, 255, 255);
	gfx.PutPixel(x_int + 13, y_int + 7, 255, 58, 0);
	gfx.PutPixel(x_int + 13, y_int + 8, 255, 255, 255);
	gfx.PutPixel(x_int + 13, y_int + 9, 255, 255, 255);
	gfx.PutPixel(x_int + 13, y_int + 10, 255, 255, 255);
	gfx.PutPixel(x_int + 13, y_int + 11, 255, 255, 255);
	gfx.PutPixel(x_int + 13, y_int + 12, 255, 255, 255);
	gfx.PutPixel(x_int + 13, y_int + 13, 255, 255, 255);
	gfx.PutPixel(x_int + 13, y_int + 14, 255, 255, 255);
	gfx.PutPixel(x_int + 13, y_int + 15, 71, 104, 255);
	gfx.PutPixel(x_int + 13, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 13, y_int + 17, 104, 255, 0);
	gfx.PutPixel(x_int + 13, y_int + 18, 104, 255, 0);
	gfx.PutPixel(x_int + 13, y_int + 19, 104, 255, 0);
	gfx.PutPixel(x_int + 13, y_int + 20, 104, 255, 0);
	gfx.PutPixel(x_int + 13, y_int + 21, 104, 255, 0);
	gfx.PutPixel(x_int + 13, y_int + 22, 104, 255, 0);
	gfx.PutPixel(x_int + 13, y_int + 23, 104, 255, 0);
	gfx.PutPixel(x_int + 14, y_int + 0, 71, 104, 255);
	gfx.PutPixel(x_int + 14, y_int + 1, 71, 104, 255);
	gfx.PutPixel(x_int + 14, y_int + 2, 71, 104, 255);
	gfx.PutPixel(x_int + 14, y_int + 3, 255, 255, 255);
	gfx.PutPixel(x_int + 14, y_int + 4, 255, 255, 255);
	gfx.PutPixel(x_int + 14, y_int + 5, 255, 255, 255);
	gfx.PutPixel(x_int + 14, y_int + 6, 255, 255, 255);
	gfx.PutPixel(x_int + 14, y_int + 7, 255, 58, 0);
	gfx.PutPixel(x_int + 14, y_int + 8, 255, 58, 0);
	gfx.PutPixel(x_int + 14, y_int + 9, 255, 58, 0);
	gfx.PutPixel(x_int + 14, y_int + 10, 255, 58, 0);
	gfx.PutPixel(x_int + 14, y_int + 11, 255, 58, 0);
	gfx.PutPixel(x_int + 14, y_int + 12, 255, 255, 255);
	gfx.PutPixel(x_int + 14, y_int + 13, 255, 255, 255);
	gfx.PutPixel(x_int + 14, y_int + 14, 71, 104, 255);
	gfx.PutPixel(x_int + 14, y_int + 15, 71, 104, 255);
	gfx.PutPixel(x_int + 14, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 14, y_int + 17, 104, 255, 0);
	gfx.PutPixel(x_int + 14, y_int + 18, 104, 255, 0);
	gfx.PutPixel(x_int + 14, y_int + 19, 104, 255, 0);
	gfx.PutPixel(x_int + 14, y_int + 20, 104, 255, 0);
	gfx.PutPixel(x_int + 14, y_int + 21, 104, 255, 0);
	gfx.PutPixel(x_int + 14, y_int + 22, 104, 255, 0);
	gfx.PutPixel(x_int + 14, y_int + 23, 0, 0, 0);
	gfx.PutPixel(x_int + 15, y_int + 0, 71, 104, 255);
	gfx.PutPixel(x_int + 15, y_int + 1, 104, 255, 0);
	gfx.PutPixel(x_int + 15, y_int + 2, 71, 104, 255);
	gfx.PutPixel(x_int + 15, y_int + 3, 255, 255, 255);
	gfx.PutPixel(x_int + 15, y_int + 4, 255, 255, 255);
	gfx.PutPixel(x_int + 15, y_int + 5, 255, 255, 255);
	gfx.PutPixel(x_int + 15, y_int + 6, 255, 255, 255);
	gfx.PutPixel(x_int + 15, y_int + 7, 255, 255, 255);
	gfx.PutPixel(x_int + 15, y_int + 8, 255, 255, 255);
	gfx.PutPixel(x_int + 15, y_int + 9, 255, 255, 255);
	gfx.PutPixel(x_int + 15, y_int + 10, 255, 255, 255);
	gfx.PutPixel(x_int + 15, y_int + 11, 255, 255, 255);
	gfx.PutPixel(x_int + 15, y_int + 12, 71, 104, 255);
	gfx.PutPixel(x_int + 15, y_int + 13, 71, 104, 255);
	gfx.PutPixel(x_int + 15, y_int + 14, 71, 104, 255);
	gfx.PutPixel(x_int + 15, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 15, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 15, y_int + 17, 104, 255, 0);
	gfx.PutPixel(x_int + 15, y_int + 18, 104, 255, 0);
	gfx.PutPixel(x_int + 15, y_int + 19, 104, 255, 0);
	gfx.PutPixel(x_int + 15, y_int + 20, 104, 255, 0);
	gfx.PutPixel(x_int + 15, y_int + 21, 104, 255, 0);
	gfx.PutPixel(x_int + 15, y_int + 22, 0, 0, 0);
	gfx.PutPixel(x_int + 15, y_int + 23, 0, 0, 0);
	gfx.PutPixel(x_int + 16, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 16, y_int + 1, 104, 255, 0);
	gfx.PutPixel(x_int + 16, y_int + 2, 71, 104, 255);
	gfx.PutPixel(x_int + 16, y_int + 3, 71, 104, 255);
	gfx.PutPixel(x_int + 16, y_int + 4, 71, 104, 255);
	gfx.PutPixel(x_int + 16, y_int + 5, 71, 104, 255);
	gfx.PutPixel(x_int + 16, y_int + 6, 71, 104, 255);
	gfx.PutPixel(x_int + 16, y_int + 7, 71, 104, 255);
	gfx.PutPixel(x_int + 16, y_int + 8, 71, 104, 255);
	gfx.PutPixel(x_int + 16, y_int + 9, 71, 104, 255);
	gfx.PutPixel(x_int + 16, y_int + 10, 71, 104, 255);
	gfx.PutPixel(x_int + 16, y_int + 11, 71, 104, 255);
	gfx.PutPixel(x_int + 16, y_int + 12, 104, 255, 0);
	gfx.PutPixel(x_int + 16, y_int + 13, 104, 255, 0);
	gfx.PutPixel(x_int + 16, y_int + 14, 104, 255, 0);
	gfx.PutPixel(x_int + 16, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 16, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 16, y_int + 17, 104, 255, 0);
	gfx.PutPixel(x_int + 16, y_int + 18, 104, 255, 0);
	gfx.PutPixel(x_int + 16, y_int + 19, 104, 255, 0);
	gfx.PutPixel(x_int + 16, y_int + 20, 104, 255, 0);
	gfx.PutPixel(x_int + 16, y_int + 21, 0, 0, 0);
	gfx.PutPixel(x_int + 16, y_int + 22, 0, 0, 0);
	gfx.PutPixel(x_int + 17, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 17, y_int + 1, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 2, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 3, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 4, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 5, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 6, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 7, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 8, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 9, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 10, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 11, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 12, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 13, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 14, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 16, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 17, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 18, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 19, 104, 255, 0);
	gfx.PutPixel(x_int + 17, y_int + 20, 0, 0, 0);
	gfx.PutPixel(x_int + 17, y_int + 21, 0, 0, 0);
	gfx.PutPixel(x_int + 18, y_int + 0, 0, 0, 0);
	gfx.PutPixel(x_int + 18, y_int + 1, 0, 0, 0);
	gfx.PutPixel(x_int + 18, y_int + 2, 0, 0, 0);
	gfx.PutPixel(x_int + 18, y_int + 3, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 4, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 5, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 6, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 7, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 8, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 9, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 10, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 11, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 12, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 13, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 14, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 15, 104, 255, 0);
	gfx.PutPixel(x_int + 18, y_int + 16, 0, 0, 0);
	gfx.PutPixel(x_int + 18, y_int + 17, 0, 0, 0);
	gfx.PutPixel(x_int + 18, y_int + 18, 0, 0, 0);
	gfx.PutPixel(x_int + 18, y_int + 19, 0, 0, 0);
	gfx.PutPixel(x_int + 18, y_int + 20, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 2, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 3, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 4, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 5, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 6, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 7, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 8, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 9, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 10, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 11, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 12, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 13, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 14, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 15, 0, 0, 0);
	gfx.PutPixel(x_int + 19, y_int + 16, 0, 0, 0);
}

