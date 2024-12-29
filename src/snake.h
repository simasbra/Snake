/*
 * FILE: snake.h
 * TITLE: Snake logic handling
 * AUTHOR: Simas Bradaitis <simasbra@proton.me>
 * VERSION: 0.1.0
 * DESCRIPTION: Snake movement, death and other logic handling header file
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

#ifndef SNAKE_H
#define SNAKE_H

#include "double-linked-list/src/double_linked_list.h"
#include "threads.h"
#include <ncurses.h>
#include <stddef.h>

/*
 * Struct for storing snake information
 */
typedef struct Snake {
	int x_head, y_head;
	int x_max, y_max;
	size_t length;
	WINDOW *window;
	struct double_linked_list *body;
} Snake;

/*
 * Creates new snake object
 * \RETURNS: pointer to the newly created snake object
 */
Snake *s_malloc(const WINDOW *const game_window);

/*
 * Frees the given snake object
 */
void s_free(Snake **snake);

/*
 * Handles snake movement
 */
void s_handle_move(Snake *const snake, Input *const input);

/*
 * Handles received signal type from input
 */
void s_handle_signal(Snake *const snake, Input *const input);

/*
 * Moves snake head up
 */
void s_move_up(Snake *const snake);

/*
 * Moves snake head down
 */
void s_move_down(Snake *const snake);

/*
 * Moves snake head to the right
 */
void s_move_right(Snake *const snake);

/*
 * Moves snake head to the left
 */
void s_move_left(Snake *const snake);

/*
 * Checks if given coordinates are not out of bounds
 * and not inside snake body
 */
int s_check_new_location(const Snake *const snake, int x, int y);

#endif
