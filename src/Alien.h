// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#pragma once

#include "Globals.h"
#include <LCGE/lcge.h>

class Alien
{
public:
	Alien(float x, float y);

	void update();

	float x();
	float y();

	void kill();
	bool is_dead();

	virtual void draw() = 0;
	virtual float width() = 0;
	virtual float height() = 0;
protected:
	void _draw(LCGE_image *sprite);
private:
	float m_x, m_y;
	float m_vel_x;
	float m_curr_frame;
	bool m_is_dead;

	static constexpr float m_speed = 0.5f;
	static constexpr float m_move_frames = Globals::FPS * 2;
public:
	static constexpr float move_width = m_speed * m_move_frames;
};
