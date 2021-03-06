/*
SpiceTools HID Reader Tester
Licensed under the GPL v3.
--------------------------------
Note: The SpiceTools' source used in this has been minimized and stripped of functions to work for this particular use case.
Rather than using this as a reference, use the original SpiceTools' distribution source code.
*/

#include <conio.h>
#include "logging.h"
#include "cardio_runner.h"
#include "eamuse.h"

std::string module("hid-tester");

int main()
{
	log_info(module, "SpiceTools HID Tester 1.0");
	cardio_runner_start(true);
	log_info(module, "--- runner started ---");
	log_info(module, "Now scanning for cards...");

	while (!_kbhit()) {
		for (int i = 0; i <= 1; i++) {
			if (eamuse_card_insert_consume(i + 1, i)) {
				char card[8];
				eamuse_get_card(i + 1, i, card);
			}
		}
		Sleep(1000);
	}
	cardio_runner_stop();

	return 0;
}