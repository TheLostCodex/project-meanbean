/*
Compatibility Test

In order to test compatibility, run the command: make
*/

#include <ncurses.h>

int main() {
    // Initialize NCurses
    initscr();
    clear();

    // Print message on the screen
    printw("If this appears fine, you are compatible.\n");
    printw("Press any key to exit.\n");

    // Wait for user to press a key
    getch();

    // Clear NCurses data structures
    endwin();
}
