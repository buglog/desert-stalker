#include "Desert.h"

Desert::Desert(Vampire& vamp)
{
	spawn(500, 300, vamp);
	frame.init(200, 20, 780, 580);
	cact_A1[0].init(340, 120, 0);
	cact_A1[1].init(260, 500, 1);
	cact_A1[2].init(700, 70, 0);
	cact_A1[3].init(260, 190, 2);
	cact_A1[4].init(620, 100, 2);
	cact_A1[5].init(720, 490, 0);

	cact_A2[0].init(230, 100, 1);
	cact_A2[1].init(300, 130, 2);
	cact_A2[2].init(297, 320, 0);
	cact_A2[3].init(360, 374, 2);
	cact_A2[4].init(478, 499, 1);
	cact_A2[5].init(370, 87, 0);
	cact_A2[6].init(700, 129, 0);
	cact_A2[7].init(723, 501, 2);
	cact_A2[8].init(670, 540, 0);

	cact_B1[0].init(247, 239, 1);
	cact_B1[1].init(309, 287, 0);
	cact_B1[2].init(437, 537, 2);
	cact_B1[3].init(331, 450, 2);
	cact_B1[4].init(578, 397, 0);

	cact_B2[0].init(232, 523, 2);
	cact_B2[1].init(230, 239, 1);
	cact_B2[2].init(283, 92, 0);
	cact_B2[3].init(299, 547, 1);
	cact_B2[4].init(367, 176, 0);
	cact_B2[5].init(228, 121, 2);
	cact_B2[6].init(420, 77, 1); 
	cact_B2[7].init(489, 104, 0);
	cact_B2[8].init(497, 481, 0);
	cact_B2[9].init(563, 529, 1);
	cact_B2[10].init(613, 105, 2);
	cact_B2[11].init(657, 139, 0);
	cact_B2[12].init(683, 314, 0);
	cact_B2[13].init(731, 295, 2);
	cact_B2[14].init(706, 519, 1);
}

void Desert::process(Vampire & vamp, Graphics& gfx, Instructions& inst, Message& msg)
{
	//set e_message at the start of every frame. this way, it will have a default and only change when processed (soon, by Saloon.h and Graveyard.h)
	inst.e_message = 0;
	drawSand(gfx);
	changeStage(vamp);
	
	if (grid_x == 0 && grid_y == 0)
	{
		process_A1(vamp, gfx, inst, msg);
	}
	else if (grid_x == 1 && grid_y == 0)
	{
		process_A2(vamp, gfx, inst, msg);
	}
	else if (grid_x == 0 && grid_y == 1)
	{
		process_B1(vamp, gfx, inst, msg);
	}
	else if (grid_x == 1 && grid_y == 1)
	{
		process_B2(vamp, gfx, inst, msg);
	}

	frame.clamp(vamp);
	cframe.SetR(255);
	cframe.SetG(0);
	cframe.SetB(0);
	frame.draw(1, cframe, gfx);
}

void Desert::spawn(int x, int y, Vampire & vamp)
{
	vamp.x = float(x);
	vamp.y = float(y);
}

void Desert::drawInFront(Vampire & vamp, Graphics & gfx)
{
	if (grid_x == 0 && grid_y == 0)
	{
		for (int i = 0; i < 6; ++i)
		{
			cact_A1[i].drawInFront(gfx, vamp);
		}
	}
	else if (grid_x == 1 && grid_y == 0)
	{
		for (int i = 0; i < 9; ++i)
		{
			cact_A2[i].drawInFront(gfx, vamp);
		}
	}
}

void Desert::changeStage(Vampire & vamp)
{
	// horizontal
	if (vamp.x + vamp.width >= float(frame.width - 6) &&
		grid_x < gridDimX - 1)
	{
		grid_x += 1;
		vamp.x = float(frame.x + 2);
	}
	if (vamp.x <= float(frame.x + 1) &&
		grid_x > 0)
	{
		grid_x -= 1;
		vamp.x = float(frame.width - 8) - vamp.width;
	}
	// vertical
	if (vamp.y + vamp.hitOffset <= float(frame.y + 1) &&
		grid_y > 0)
	{
		grid_y -= 1;
		vamp.y = float(frame.height - 2) - vamp.height;
	}
	else if (vamp.y + vamp.height >= float(frame.height - 2) &&
		grid_y < gridDimY - 1)
	{
		grid_y += 1;
		vamp.y = float(frame.y + 2) - vamp.hitOffset;
	}
}

void Desert::drawSand(Graphics & gfx)
{
	// draws sand
	csand.SetR(150);
	csand.SetG(100);
	csand.SetB(70);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 1, csand);
	csand.SetR(255);
	csand.SetG(50);
	csand.SetB(30);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 5, csand);
	csand.SetR(100);
	csand.SetG(200);
	csand.SetB(50);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 12, csand);
	csand.SetR(255);
	csand.SetG(220);
	gfx.Rectangle(frame.x, frame.y, frame.width, frame.height, 24, csand);
	//draw vignette
	//csand.SetR(0);
	//csand.SetG(0);
	//csand.SetB(255);
	//gfx.Rectangle(frame.x, frame.y, frame.width,frame.y + 100,4,csand);
}

void Desert::process_A1(Vampire & vamp, Graphics& gfx, Instructions& inst, Message& msg)
{
	//cactuses
	for (int i = 0; i < 6; ++i)
	{
		cact_A1[i].place(gfx, vamp, inst, msg);
	}
}

void Desert::process_A2(Vampire & vamp, Graphics & gfx, Instructions & inst, Message & msg)
{
	for (int i = 0; i < 9; ++i)
	{
		cact_A2[i].place(gfx, vamp, inst, msg);
	}
}

void Desert::process_B1(Vampire & vamp, Graphics & gfx, Instructions & inst, Message & msg)
{
	for (int i = 0; i < 5; ++i)
	{
		cact_B1[i].place(gfx, vamp, inst, msg);
	}
}

void Desert::process_B2(Vampire & vamp, Graphics & gfx, Instructions & inst, Message & msg)
{
	for (int i = 0; i < 15; ++i)
	{
		cact_B2[i].place(gfx, vamp, inst, msg);
	}
}

