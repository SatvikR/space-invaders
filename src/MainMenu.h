// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#pragma once

#include "Screen.h"
#include <LCGE/lcge.h>

class MainMenu : public Screen
{
public:
	MainMenu(LCGE_clock *clock);
	~MainMenu();

	bool update();
private:
	LCGE_font *m_title_font;
	LCGE_text *m_title;

	LCGE_font *m_play_font;
	LCGE_text *m_play;

	static constexpr char m_title_text[] = "Space Invaders!";
	static constexpr float m_title_height = 54.0f;

	static constexpr char m_play_text[] = "Press space to play...";
	static constexpr float m_play_height = 28.0f;
};
