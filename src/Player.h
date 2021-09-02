// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#pragma once

#include "Globals.h"
#include "Laser.h"
#include <LCGE/lcge.h>

class Player
{
public:
	Player();
	~Player();

	void draw();
	void update();

	Laser *spawn_laser();

	void set_score(unsigned int score);
	unsigned int get_score();
private:
	LCGE_image *m_sprite;
	LCGE_text *m_score_text;
	LCGE_font *m_score_font;

	float m_x, m_y;
	unsigned int m_score;

	static constexpr char m_sprite_path[]
		= "assets/images/cannon-small.png";
	static constexpr float m_sprite_width = 52.0f;
	static constexpr float m_sprite_height = 32.0f;

	static constexpr float m_default_x
		= (Globals::WIDTH - m_sprite_width) / 2.0f;
	static constexpr float m_default_y = Globals::HEIGHT * 0.8f;

	static constexpr float m_speed = 5.0f;

	static constexpr float m_score_xoff = 40.0f;
	static constexpr float m_score_yoff = 40.0f;
};