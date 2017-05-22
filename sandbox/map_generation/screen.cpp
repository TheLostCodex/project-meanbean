#include "screen.h"

/* Constructor */
Screen::Screen() {
    initscr();
    start_color();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    // Get screen dimensions
    getmaxyx(stdscr, height, width);
}

/* Destructor */
Screen::~Screen() {
    endwin();
}

/* Display Message to the Screen */
void Screen::display(const char *msg) {
    printw(msg);
}

/* Accessor Functions */
int Screen::getHeight() {
    return height;
}

int Screen::getWidth() {
    return width;
}
