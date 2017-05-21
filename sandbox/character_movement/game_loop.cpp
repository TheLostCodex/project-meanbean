#include <ncurses.h>
#include "game_loop.h"

void game_loop(char player, int row, int column, int user_input) {
    // Check for quit condition
    if(user_input == 'q' || user_input == 'Q') return;

    mvaddch(row, column, player);
    refresh();

    while(1) {
        user_input = getch();

        if(user_input == KEY_LEFT) {
            erase(row, column);
            column -= 1;
            mvaddch(row, column, player);
            refresh();
        }

        else if(user_input == KEY_RIGHT) {
            erase(row, column);
            column += 1;
            mvaddch(row, column, player);
            refresh();
        }

        else if(user_input == KEY_UP) {
            erase(row, column);
            row -= 1;
            mvaddch(row, column, player);
            refresh();
        }

        else if(user_input == KEY_DOWN) {
            erase(row, column);
            row += 1;
            mvaddch(row, column, player);
            refresh();
        }

        else if(user_input == 'q' || user_input == 'Q') {
            break;
        }
    }
}

void erase(int row, int column) {
    mvaddch(row, column, '#');
}
