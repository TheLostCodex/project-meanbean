#include <ncurses.h>

#ifndef SCREEN_H
#define SCREEN_H

class Screen {
    int height;
    int width;

  public:
    // Constructor and Destructor
    Screen();
    ~Screen();

    // Displays message on the screen
    void display(const char *msg);

    // Accessor Functions
    int getHeight();
    int getWidth();
};

#endif
