#include <LCGE/lcge.h>

int main(int argc, char const *argv[])
{
	// Initialize LCGE with the path to the res directory of LCGE (specific to you)
	if (lcge_init("lib/LCGE/res") == LCGE_INIT_ERR) {
		lcge_exit();
		return -1;
	}

	// Create a window
	int success = lcge_create_context(500, 500, "LCGE Example",
					  LCGE_NON_RESIZEABLE);

	// Create clock with a max fps
	LCGE_clock *clock = lcge_clock_create(60);

	// Check if there was an error creating the window
	if (success == LCGE_CONTEXT_ERR) {
		lcge_exit();
		return -1;
	}

	while (lcge_window_is_open()) {
		// Do any udpating here

		// Do any drawing here
		lcge_window_clear();

		// Get ready for next iteration
		lcge_clock_tick(clock);
		lcge_window_update();
	}

	// Clean up
	lcge_clock_delete(clock);

	lcge_exit();

	return 0;
}
