// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "PlayScreen.h"
#include "Screen.h"
#include "Globals.h"
#include "Alien.h"
#include "AlienOne.h"
#include "AlienTwo.h"
#include "AlienThree.h"
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
}

PlayScreen::PlayScreen(LCGE_clock *clock)
	: Screen(clock)
{
	spawn_aliens();
}

PlayScreen::~PlayScreen()
{
	AlienOne::delete_sprite();
}

bool PlayScreen::update()
{
	for (auto &a : m_aliens)
	{
		a->update_pos();
		a->draw();
	}
	return true;
}