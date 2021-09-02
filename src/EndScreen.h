// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#pragma once

#include "Screen.h"
#include <LCGE/lcge.h>

class EndScreen : public Screen
{
public:
	EndScreen(LCGE_clock *clock);
	~EndScreen();

	bool update();
private:
	LCGE_font *m_title_font;
	LCGE_text *m_title;

	LCGE_font *m_play_font;
	LCGE_text *m_play;

	static constexpr char m_title_text[] = "Thanks for playing!";
	static constexpr float m_title_height = 50.0f;

	static constexpr char m_play_text[] = "Copyright (c) 2021, Satvik Reddy";
	static constexpr float m_play_height = 28.0f;
};
