// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#pragma once

#include <vector>
#include <LCGE/lcge.h>

class Util
{
public:
	static void center_text(LCGE_text *text, const char *c);

	static void center_text_x(LCGE_text *text, const char *c);
	static void center_text_y(LCGE_text *text, const char *c);

	static bool rect_collding(float r1x, float r1y, float r1w, float r1h,
				  float r2x, float r2y, float r2w, float r2h);
};