/***************************	*************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	desert(vampire),
	msg()
{
	cowboyBar.init(20, 180, Colors::Cyan, 0, 10);
	terrorBar.init(20, cowboyBar.y + cowboyBar.height + 40, Colors::Red, 1, 10);
	hat.init(630, 450);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	vampire.update(wnd.kbd,hat);
	desert.process(vampire, gfx, instr, msg, terrorBar);
}

void Game::ComposeFrame()
{
	if (!vampire.hasHat)
	{
		if (desert.canDrawHat)
		{
			hat.draw(gfx);
			// check if vamp is in hat range.
			if (vampire.x + vampire.width >= float(hat.x - hat.pickUpRange) &&
				vampire.x <= hat.x + hat.width + hat.pickUpRange &&
				vampire.y + vampire.height >= hat.y - hat.pickUpRange &&
				vampire.y <= hat.y + hat.height + hat.pickUpRange)
			{
				instr.e_message = instr.pickup;
				if (wnd.kbd.KeyIsPressed('E'))
				{
					msg.message = msg.got_hat;
					msg.reset();
					vampire.hasHat = true;
				}
			}

		}
	}
	vampire.draw(gfx);
	if (vampire.hasHat)
	{
		cowboyBar.incr(180);
		hat.draw(gfx);
	}
	desert.drawInFront(vampire, gfx);
	instr.draw(gfx);
	cowboyBar.draw(gfx,msg);
	terrorBar.draw(gfx,msg);
	//you win, bsaically 
	if (cowboyBar.getProg() >= 169 &&
		terrorBar.getProg() >= 169)
	{
		msg.message = msg.beautiful;
		msg.reset();
	}
	//msg.draw comes after the progressbars because they update msg.
	msg.draw(gfx);
}
