// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Util.h"
#include "Laser.h"
#include "Player.h"
#include <LCGE/lcge.h>

Player::Player()
{
	m_sprite = lcge_image_load(
		m_sprite_path,
		0,
		0,
		m_sprite_width,
		m_sprite_height
	);

	m_x = m_default_x;
	m_y = m_default_y;
}

Player::~Player()
{
	lcge_image_delete(m_sprite);
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
}

Laser *Player::spawn_laser()
{
	return new Laser(((2.0f * m_x) + m_sprite_width) / 2.0f);
}