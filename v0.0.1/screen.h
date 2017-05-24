#include <ncurses.h>
#include <panel.h>

#ifndef SCREEN_H
#define SCREEN_H

class Screen {
    int height;
    int width;

  public:
    // Constructor and Destructor
    Screen();
    ~Screen();

    // Accessor Functions
    int getHeight();
    int getWidth();

    // Displays message on the screen
    void display(const char *msg);
    int start_screen();
    int game_over();
};

#endif
