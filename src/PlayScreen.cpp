// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "PlayScreen.h"
#include "Screen.h"
#include "Globals.h"
#include "Alien.h"
#include "AlienOne.h"
#include "AlienTwo.h"
#include "AlienThree.h"
#include "Laser.h"
#include <LCGE/lcge.h>
#include <vector>

void PlayScreen::spawn_aliens()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < m_num_aliens_per_row; j++)
		{
			Alien *a;
			if (i < 2)
				a = new AlienOne(
					m_alien_x_offset + (j * m_alien_one_spacing),
					m_alien_y_offset + (i * m_alien_row_height)
				);
			else if (i < 4)
				a = new AlienTwo(
					m_alien_x_offset + (j * m_alien_two_spacing),
					m_alien_y_offset + (i * m_alien_row_height)
				);
			else if (i < 6)
				a = new AlienThree(
					m_alien_x_offset + (j * m_alien_three_spacing),
					m_alien_y_offset + (i * m_alien_row_height)
				);

			m_aliens.push_back(a);
		}
	}

	m_shoot_cooldown = 0;
}

PlayScreen::PlayScreen(LCGE_clock *clock)
	: Screen(clock)
{
	spawn_aliens();
	m_player = new Player();
}

PlayScreen::~PlayScreen()
{
	AlienOne::delete_sprite();
	AlienTwo::delete_sprite();
	AlienThree::delete_sprite();

	Laser::delete_sprite();

	delete m_player;
}

bool PlayScreen::update()
{
	m_lasers.erase(
		std::remove_if(m_lasers.begin(), m_lasers.end(),
			[&](Laser* &l) { return l->collided(m_aliens); }),
		m_lasers.end()
	);

	m_aliens.erase(
		std::remove_if(m_aliens.begin(), m_aliens.end(),
			[&](Alien* &a) { return a->is_dead(); }),
		m_aliens.end()
	);

	for (auto &l : m_lasers)
	{
		l->update();
		l->draw();
	}

	for (auto &a : m_aliens)
	{
		a->update();
		a->draw();
	}

	m_player->update();
	m_player->draw();

	if (lcge_get_key(LCGE_KEY_SPACE) == LCGE_KEY_PRESSED)
	{
		if (!m_shoot_cooldown)
		{
			m_lasers.push_back(m_player->spawn_laser());
			m_shoot_cooldown = Globals::FPS / 2;
		}
	}
	if (m_shoot_cooldown > 0)
		m_shoot_cooldown--;

	return true;
}