/* yetris - Tetris(tm) on the console.
 * Copyright (C) 2013 Alexandre Dantas (kure)
 *
 * This file is part of yetris.
 *
 * yetris is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * homepage: http://yetris.alexdantas.net
 * mailto:   eu@alexdantas.net
 */

#ifndef HSCORE_H_DEFINED
#define HSCORE_H_DEFINED

#include <stdbool.h>
#include "game.h"

/** Maximum number of high scores to store (both on the file and memory) */
#define MAX_HSCORES 10

/** Stores all stuff related to a single score. */
typedef struct score_s
{
	char name[11]; /**< Name of the player (10 chars + null) */
	char time[9];  /**< Time when this score was recorded (hh:mm:ss) */
	char date[11]; /**< Date when this score was recorded (dd/mm/yyyy) */
	char timer[9]; /**< Ammount of time the game lasted (hh:mm:ss) */
	int  points;   /**< How many points the player has scored */
	int  lines;    /**< How many lines the player cleared */
	int  level;    /**< On what level the player was when he lost */
} score_s;

/** Global variable storing the top scores list, ordered by points */
score_s hscores[MAX_HSCORES];

void hscore_handle(game_s* g);

/** Includes the score #s at it's according position on the global array.
 *	Also shifts any score after the one included.
 */
void hscore_insert(score_s* s);

/** Returns where the score will be on the global array */
int  get_hscore_index(int score);

/** Starts the high score list with default values	*/
void hscore_init();

/** Creates an empty high score element */
score_s new_score();

void hscore_copy(score_s* dest, score_s* orig);

/** Saves a score.
 *	It automagically handles date.
 */
void score_set(score_s* s, char name[], int points, int lines, int level, int hours, int minutes, int seconds);

bool is_on_hscore_list(int score);

/** Get the points from the first score on the list */
int  hscore_get_highest_points();

/** Get the points from the last score on the list */
int  hscore_get_lowest_points();

/** Zeroes the contents of the high score file */
void hscore_reset();

/** Writes the high scores into the file */
bool hscore_save();

bool hscore_load();

#endif /* HSCORE_H_DEFINED */

