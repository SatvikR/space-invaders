// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "MainMenu.h"
#include "Screen.h"
#include "Util.h"
#include "Globals.h"
#include <LCGE/lcge.h>

MainMenu::MainMenu(LCGE_clock *clock)
	: Screen(clock)
{
	m_title_font = lcge_font_load(
		"assets/fonts/Eight-Bit Madness.ttf", m_title_height
	);
	m_title = lcge_text_load(m_title_text, 0, 0, m_title_font);

	m_play_font = lcge_font_load(
		"assets/fonts/Eight-Bit Madness.ttf", m_play_height
	);
	m_play = lcge_text_load(m_play_text, 0, 0, m_play_font);

	Util::center_text_x(m_title, m_title_text);
	lcge_text_set(
		m_title,
		m_title_text,
		lcge_text_get_x(m_title),
		250.0f
	);

	Util::center_text(m_play, m_play_text);
}

MainMenu::~MainMenu()
{
	lcge_text_delete(m_title);
	lcge_font_delete(m_title_font);

	lcge_text_delete(m_play);
	lcge_font_delete(m_play_font);
}

bool MainMenu::update()
{
	if (lcge_get_key(LCGE_KEY_SPACE) == LCGE_KEY_PRESSED)
		return false;

	lcge_text_draw(
		m_title, Globals::GREEN.r, Globals::GREEN.g, Globals::GREEN.b
	);
	lcge_text_draw(
		m_play, Globals::GREEN.r, Globals::GREEN.g, Globals::GREEN.b
	);

	return true;
}