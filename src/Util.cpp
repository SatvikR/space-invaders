// Copyright (c) 2021, Satvik Reddy <reddy.satvik@gmail.com>

#include "Util.h"
#include "Globals.h"
#include <LCGE/lcge.h>

void Util::center_text(LCGE_text *text, const char *c)
{
	float w = lcge_text_get_width(text);
	float h = lcge_text_get_height(text);
	lcge_text_set(
		text, c, (Globals::WIDTH-w) / 2, (Globals::HEIGHT-h) / 2 + h
	);
}

void Util::center_text_x(LCGE_text *text, const char *c)
{
	float w = lcge_text_get_width(text);
	float y = lcge_text_get_y(text);
	lcge_text_set(
		text, c, (Globals::WIDTH-w) / 2, y
	);
}

void Util::center_text_y(LCGE_text *text, const char *c)
{
	float h = lcge_text_get_height(text);
	float x = lcge_text_get_x(text);
	lcge_text_set(
		text, c, x, (Globals::HEIGHT-h) / 2 + h
	);
}

bool Util::rect_collding(float r1x, float r1y, float r1w, float r1h,
			 float r2x, float r2y, float r2w, float r2h)
{
	return (r1x < r2x + r2w) &&
		(r1x + r1w > r2x) &&
		(r1y < r2y + r2h) &&
		(r1y + r1h > r2y);
}