// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Util.h"
#include "Laser.h"
#include "Player.h"
#include <LCGE/lcge.h>
#include <sstream>

Player::Player()
{
	m_sprite = lcge_image_load(
		m_sprite_path,
		0,
		0,
		m_sprite_width,
		m_sprite_height
	);

	m_score_font = lcge_font_load(
		"assets/fonts/Eight-Bit Madness.ttf",
		36.0f
	);

	m_score_text = lcge_text_load(
		"Score: 0",
		m_score_xoff,
		m_score_yoff,
		m_score_font
	);

	m_x = m_default_x;
	m_y = m_default_y;
	m_score = 0;
}

Player::~Player()
{
	lcge_image_delete(m_sprite);
	lcge_text_delete(m_score_text);
	lcge_font_delete(m_score_font);
}

void Player::draw()
{
	lcge_image_set(
		m_sprite,
		m_x,
		m_y,
		m_sprite_width,
		m_sprite_height
	);
	lcge_image_draw(m_sprite);
	lcge_text_draw(m_score_text, Globals::GREEN.r, Globals::GREEN.g,
		       Globals::GREEN.b);
}

void Player::update()
{
	if (lcge_get_key(LCGE_KEY_RIGHT) == LCGE_KEY_PRESSED)
	{
		m_x += m_speed;
	}
	if (lcge_get_key(LCGE_KEY_LEFT) == LCGE_KEY_PRESSED)
	{
		m_x -= m_speed;
	}

	if (m_x < 0.0f)
		m_x = 0.0f;
	else if (m_x > (Globals::WIDTH - m_sprite_width))
		m_x = Globals::WIDTH - m_sprite_width;

	std::stringstream score_format;
	score_format << "Score: " << m_score;
	lcge_text_set(
		m_score_text,
		score_format.str().c_str(),
		m_score_xoff,
		m_score_yoff
	);
}

Laser *Player::spawn_laser()
{
	return new Laser(((2.0f * m_x) + m_sprite_width) / 2.0f);
}

void Player::set_score(unsigned int score)
{
	m_score = score;
}


unsigned int Player::get_score()
{
	return m_score;
}