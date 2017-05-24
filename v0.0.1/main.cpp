#include <ncurses.h>
#include <panel.h>

#include "screen.h"

int main() {
    Screen screen;

    while(1) {
        int ch = screen.start_screen();
        ch = screen.game_over();

        if(ch == 'Q' || ch == 'q') break;
    }

    return 0;
}
