/*
 * FILE: input.c
 * TITLE: Input handling
 * AUTHOR: Simas Bradaitis <simasbra@proton.me>
 * VERSION: 0.1.0
 * DESCRIPTION: Input handling inplementation
 *
 * Copyright (c) 2024 Simas Bradaitis
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "input.h"
#include <ncurses.h>

void i_handle_input(Monitor *const monitor)
{
	int exit_received = 0;
	while (!exit_received) {
		int value = getch();
		if (value == (int)'q') {
			exit_received = 1;
		}
		pthread_mutex_lock(&monitor->mutex);
		i_handle_received_key(monitor, value);
		pthread_cond_signal(&monitor->input_received);
		pthread_mutex_unlock(&monitor->mutex);
	}
}

void i_handle_received_key(Monitor *const monitor, const int value)
{
	switch (value) {
	case (int)'q':
		monitor->signal_type = SIGNAL_GAME_EXIT;
		break;
	case KEY_UP:
		monitor->signal_type = SIGNAL_MOVE_UP;
		break;
	case KEY_DOWN:
		monitor->signal_type = SIGNAL_MOVE_DOWN;
		break;
	case KEY_RIGHT:
		monitor->signal_type = SIGNAL_MOVE_RIGHT;
		break;
	case KEY_LEFT:
		monitor->signal_type = SIGNAL_MOVE_LEFT;
		break;
	default:
		break;
	}
}
