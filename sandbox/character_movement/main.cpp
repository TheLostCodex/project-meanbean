#include <ncurses.h>
#include "game_loop.h"

int main() {
    // Initialize NCurses
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    // Define the main character and initial position
    int row = 0;
    int column = 0;
    char player = '@';

    // Display welcome message
    printw("Welcome to the Sandbox.\n");
    printw("Press any key to start and 'Q' to exit at any time.\n");

    // Wait for user to press a key
    int user_input = getch();

    // Clear the screen
    clear();

    // Start the game loop
    game_loop(player, row, column, user_input);

    // End game
    endwin();

    return 0;
}
