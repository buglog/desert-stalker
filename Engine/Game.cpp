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
	vampire.update(wnd.kbd);
	desert.process(vampire, gfx, instr, msg);
	/*
	//check if vamp got stabbed by spikes
	if (!vampire.isStabbed)
	{
		vampire.update(wnd.kbd);
		desert.process(vampire, gfx, instr, msg);
	}
	//if stabbed, respawn vamp
	else if (deathCounter < deathPauseLength)
	{
		++deathCounter;
	}
	else if (deathCounter >= deathPauseLength)
	{
		deathCounter = 0;
		desert.spawn(400,300,vampire);
		vampire.isStabbed = false;
	}
	*/
}

void Game::ComposeFrame()
{
	if (!vampire.isStabbed)
	{
		vampire.draw(gfx);
	}
	else
	{
		vampire.skull(gfx);
	}
	if (wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		msg.message = msg.got_hat;
	}
	msg.draw(gfx);
	instr.draw(gfx);
}
