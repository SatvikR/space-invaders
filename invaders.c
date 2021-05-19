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

static LCGE_image *player_sprite;

static void load_sprites()
{
	player_sprite = lcge_image_load("assets/cannon-small.png", (WIDTH - CANNON_W) / 2.0f, 700.0f ,CANNON_W, CANNON_H);
}

static void delete_sprites()
{
	lcge_image_delete(player_sprite);
}

/* Global state */
static struct {
	float x;
} player_state;

int main(int argc, char const *argv[])
{
	/* Initialize LCGE with the path to the res directory of LCGE (specific to you) */
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

	player_state.x = (WIDTH - CANNON_W) / 2.0f;

	/* Create clock with a max fps */
	LCGE_clock *clock = lcge_clock_create(60);

	load_sprites();

	while (lcge_window_is_open()) {
		/* Udpating */
		if (lcge_get_key(LCGE_KEY_LEFT) == LCGE_KEY_PRESSED) {
			if (player_state.x >= PLAYER_SPEED) {
				player_state.x -= PLAYER_SPEED;
			}
		}
		if (lcge_get_key(LCGE_KEY_RIGHT) == LCGE_KEY_PRESSED) {
			if ((player_state.x + CANNON_W) <= (WIDTH - PLAYER_SPEED)) {
				player_state.x += PLAYER_SPEED;
			}
		}

		lcge_image_set(player_sprite, player_state.x, 700.0f, CANNON_W, CANNON_H);
		/* Drawing */
		lcge_window_clear();

		lcge_image_draw(player_sprite);

		/* Get ready for next iteration */
		lcge_clock_tick(clock);
		lcge_window_update();
	}

	/* Clean up */
	lcge_clock_delete(clock);

	delete_sprites();

	lcge_exit();

	return 0;
}
