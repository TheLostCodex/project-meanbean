#include <ncurses.h>
#include "screen.h"
#include "frame.h"
#include "character.h"

#ifndef GAME_LOOP_H
#define GAME_LOOP_H

void game_loop(Frame &game_map, Frame &viewport, Character &main_char, int ch);

#endif
