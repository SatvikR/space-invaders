// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#pragma once

#include "Screen.h"
#include "Alien.h"
#include "AlienOne.h"
#include "AlienTwo.h"
#include "AlienThree.h"
#include "Globals.h"
#include "Player.h"
#include "Laser.h"
#include <LCGE/lcge.h>
#include <vector>


class PlayScreen : public Screen
{
public:
	PlayScreen(LCGE_clock *clock);
	~PlayScreen();

	bool update();
private:
	void spawn_aliens();

	std::vector<Alien*> m_aliens;
	std::vector<Laser*> m_lasers;
	Player *m_player;

	int m_shoot_cooldown;

	static constexpr int m_num_aliens_per_row = 11;

	static constexpr float m_alien_x_end = 700.0f;
	static constexpr float m_alien_x_offset =
		(Globals::WIDTH - m_alien_x_end) / 2.0f - Alien::move_width / 2.0f;
	static constexpr float m_alien_y_offset = 90.0f;
	static constexpr float m_alien_row_height = 36.0f;

#define _SPACING(width) (m_alien_x_end - (m_num_aliens_per_row * width)) \
			/ (m_num_aliens_per_row - 1) + width

	static constexpr float m_alien_one_spacing = _SPACING(AlienOne::sprite_width);
	static constexpr float m_alien_two_spacing = _SPACING(AlienTwo::sprite_width);
	static constexpr float m_alien_three_spacing = _SPACING(AlienThree::sprite_width);
};
