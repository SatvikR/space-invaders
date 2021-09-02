// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Game.h"
#include "Globals.h"
#include "Screen.h"
#include "MainMenu.h"
#include "PlayScreen.h"
#include "EndScreen.h"
#include <LCGE/lcge.h>

Game::~Game()
{
	lcge_clock_delete(m_clock);
	lcge_exit();
}

bool Game::setup()
{
	if (lcge_init(LCGE_RES_DIR) == LCGE_INIT_ERR)
	{
		lcge_exit();
		return false;
	}

	if (!lcge_create_context(
		Globals::WIDTH, Globals::HEIGHT, Globals::TITLE, LCGE_NON_RESIZEABLE
	))
	{
		lcge_exit();
		return false;
	}

	m_clock = lcge_clock_create(Globals::FPS);
	return true;
}

void Game::run()
{
	Screen *screens[] = {
		new MainMenu(m_clock),
		new PlayScreen(m_clock),
		new EndScreen(m_clock)
	};
	for (auto &s : screens)
	{
		s->run();
		delete s;
	}
}