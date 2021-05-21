/*
 * Copyright (c) 2021, Satvik Reddy
 * Use of this source code is governed by a BSD-style license that can be found
 * in the LICENSE file
 */

#include <LCGE/lcge.h>

#define WIDTH  800
#define HEIGHT 800

#define CANNON_W (52.0f * 1.5f)
#define CANNON_H (32.0f * 1.5f)

#define PLAYER_SPEED 10.0f

/* Local function defs */
static void game();
static void main_menu();

static LCGE_clock *clock;

static LCGE_image *player_sprite;

static LCGE_font *title_font;
static LCGE_font *subtitle_font;

static void load_sprites()
{
	player_sprite = lcge_image_load("assets/images/cannon-small.png",
					(WIDTH - CANNON_W) / 2.0f, 700.0f,
					CANNON_W, CANNON_H);

	title_font =
		lcge_font_load("assets/fonts/Eight-Bit Madness.ttf", 54.0f);
	subtitle_font =
		lcge_font_load("assets/fonts/Eight-Bit Madness.ttf", 32.0f);
}

static void delete_sprites()
{
	lcge_image_delete(player_sprite);
	lcge_font_delete(title_font);
	lcge_font_delete(subtitle_font);
}

/* Global state */
static struct {
	float x;
} player_state;

static void main_menu()
{
	char in_menu = 1;
	LCGE_text *title =
		lcge_text_load("Space Invaders", 0.0f, 200.0f, title_font);
	LCGE_text *subtitle = lcge_text_load("Press space to play", -1000.0f, -1000.0f,
					     subtitle_font);

	lcge_text_set(title, "Space Invaders",
		      (WIDTH - lcge_text_get_width(title)) / 2.0f, 200.0f);

	lcge_text_set(subtitle, "Press space to play",
		      (WIDTH - lcge_text_get_width(subtitle)) / 2.0f, 500.0f);

	while (lcge_window_is_open() && in_menu) {
		if (lcge_get_key(LCGE_KEY_SPACE) == LCGE_KEY_PRESSED) {
			in_menu = 0;
		}

		lcge_window_clear();
		lcge_text_draw(title, 0.0f, 255.0f, 0.0f);
		lcge_text_draw(subtitle, 0.0f, 255.0f, 0.0f);

		lcge_clock_tick(clock);
		lcge_window_update();
	}

	if (!in_menu) {
		game();
	}
	lcge_text_delete(title);
}

static void game()
{
	player_state.x = (WIDTH - CANNON_W) / 2.0f;
	while (lcge_window_is_open()) {
		/* Udpating */
		if (lcge_get_key(LCGE_KEY_LEFT) == LCGE_KEY_PRESSED) {
			if (player_state.x >= PLAYER_SPEED) {
				player_state.x -= PLAYER_SPEED;
			}
		}
		if (lcge_get_key(LCGE_KEY_RIGHT) == LCGE_KEY_PRESSED) {
			if ((player_state.x + CANNON_W) <=
			    (WIDTH - PLAYER_SPEED)) {
				player_state.x += PLAYER_SPEED;
			}
		}

		lcge_image_set(player_sprite, player_state.x, 700.0f, CANNON_W,
			       CANNON_H);
		/* Drawing */
		lcge_window_clear();

		lcge_image_draw(player_sprite);

		/* Get ready for next iteration */
		lcge_clock_tick(clock);
		lcge_window_update();
	}
}

int main(int argc, char const *argv[])
{
	/* Initialize LCGE */
	if (lcge_init("assets/") == LCGE_INIT_ERR) {
		lcge_exit();
		return -1;
	}

	/* Create a window */
	int success = lcge_create_context(WIDTH, HEIGHT, "Space Invaders",
					  LCGE_NON_RESIZEABLE);

	/* Check if there was an error creating the window */
	if (success == LCGE_CONTEXT_ERR) {
		lcge_exit();
		return -1;
	}

	/* Create clock with a max fps */
	clock = lcge_clock_create(60);

	load_sprites();

	main_menu();

	/* Clean up */
	lcge_clock_delete(clock);

	delete_sprites();

	lcge_exit();

	return 0;
}
