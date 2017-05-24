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

/* Accessor Functions */
int Screen::getHeight() {
    return height;
}

int Screen::getWidth() {
    return width;
}

/* Display Message to the Screen */
void Screen::display(const char *msg) {
    printw(msg);
}

int Screen::start_screen() {
    // Initialize array of windows and panels
    WINDOW *windows[4];
    PANEL *panels[4];

    // Determine appropriate offsets to render windows in the center of the screen
    int terminal_height = height;
    int terminal_width = width;
    int horizontal_offset = (int)((width - 80)/2);
    int vertical_offset = (int)((height - 42)/2);

    // Create the background window
    windows[0] = newwin(height, width, 0, 0);
    box(windows[0], 0, 0);

    // Create the title window
    windows[1] = newwin(8, 85, vertical_offset, horizontal_offset);

    // Create the swords window
    windows[2] = newwin(5, 80, vertical_offset + 9, horizontal_offset + 4);

    // Create the castle window
    windows[3] = newwin(26, 80, vertical_offset + 15, horizontal_offset + 7);

    // Assign each window to a panel
    for(int i = 0; i < 4; i++) {
        panels[i] = new_panel(windows[i]);
    }

    // Display the title in ASCII art
    // Link: http://patorjk.com/software/taag/#p=display&f=Big&t=Project%20Meanbean
    wprintw(windows[1], "  _____           _           _     __  __                  _                      \n |  __ \\         (_)         | |   |  \\/  |                | |                     \n | |__) | __ ___  _  ___  ___| |_  | \\  / | ___  __ _ _ __ | |__   ___  __ _ _ __  \n |  ___/ '__/ _ \\| |/ _ \\/ __| __| | |\\/| |/ _ \\/ _` | '_ \\| '_ \\ / _ \\/ _` | '_ \\ \n | |   | | | (_) | |  __/ (__| |_  | |  | |  __/ (_| | | | | |_) |  __/ (_| | | | |\n |_|   |_|  \\___/| |\\___|\\___|\\__| |_|  |_|\\___|\\__,_|_| |_|_.__/ \\___|\\__,_|_| |_|\n                _/ |\n               |__/                                                                \n");

    // Display swords in ASCII art
    // Link:
    wprintw(windows[2], "           /\\                                                 /\\\n _         )( ______________________   ______________________ )(         _\n(_)///////(**)______________________\\ /______________________(**)\\\\\\\\\\\\\\(_)\n           )(                                                 )(\n           \\/                                                 \\/\n");

    // Display castle in ASCII art
    // Link: http://www.ascii-code.com/ascii-art/buildings-and-places/castles.php
    wprintw(windows[3], "                                                  !_\n                     Press any key to continue.   |*~=-.,\n                                                  |_,-'`\n                                                  |\n                                                  |\n                                                 /^\\\n                   !_                           /   \\\n                   |*`~-.,                     /,    \\\n                   |.-~^`                     /#\"     \\\n                   |                        _/##_   _  \\_\n              _   _|  _   _   _            [ ]_[ ]_[ ]_[ ]\n             [ ]_[ ]_[ ]_[ ]_[ ]            |_=_-=_ - =_|\n           !_ |_=_ =-_-_  = =_|           !_ |=_= -    |\n           |*`--,_- _        |            |*`~-.,= []  |\n           |.-'|=     []     |   !_       |_.-\"`_-     |\n           |   |_=- -        |   |*`~-.,  |  |=_-      |\n          /^\\  |=_= -        |   |_,-~`  /^\\ |_ - =[]  |\n      _  /   \\_|_=- _   _   _|  _|  _   /   \\|=_-      |\n     [ ]/,    \\[ ]_[ ]_[ ]_[ ]_[ ]_[ ]_/,    \\[ ]=-    |\n      |/#\"     \\_=-___=__=__- =-_ -=_ /#\"     \\| _ []  |\n     _/##_   _  \\_-_ =  _____       _/##_   _  \\_ -    |\\\n    [ ]_[ ]_[ ]_[ ]=_0~{_ _ _}~0   [ ]_[ ]_[ ]_[ ]=-   | \\\n    |_=__-_=-_  =_|-=_ |  ,  |     |_=-___-_ =-__|_    |  \\\n     | _- =-     |-_   | ((* |      |= _=       | -    |___\\\n     |= -_=      |=  _ |  `  |      |_-=_       |=_    |/+\\|\n     | =_  -     |_ = _ `-.-`       | =_ = =    |=_-   ||+||\n");

    // Update panels as necessary to display
    update_panels();
    doupdate();

    return getch();
}

int Screen::game_over() {
    // Initialize array of windows and panels
    WINDOW *windows[4];
    PANEL *panels[4];

    // Determine appropriate offsets to render windows in the center of the screen
    int terminal_height = height;
    int terminal_width = width;
    int horizontal_offset = (int)((width - 80)/2);
    int vertical_offset = (int)((height - 42)/2);

    windows[0] = newwin(height, width, 0, 0);
    box(windows[0], 0, 0);

    // Create the title window
    windows[1] = newwin(8, 85, vertical_offset, horizontal_offset);

    // Create the swords window
    windows[2] = newwin(5, 80, vertical_offset + 9, horizontal_offset + 4);

    // Create the castle window
    windows[3] = newwin(26, 80, vertical_offset + 15, horizontal_offset + 7);

    // Assign each window to a panel
    for(int i = 0; i < 4; i++) {
       panels[i] = new_panel(windows[i]);
    }

    // Display the title in ASCII art
    // Link: http://patorjk.com/software/taag/#p=display&f=Big&t=Project%20Meanbean
    wprintw(windows[1], "  _____           _           _     __  __                  _                      \n |  __ \\         (_)         | |   |  \\/  |                | |                     \n | |__) | __ ___  _  ___  ___| |_  | \\  / | ___  __ _ _ __ | |__   ___  __ _ _ __  \n |  ___/ '__/ _ \\| |/ _ \\/ __| __| | |\\/| |/ _ \\/ _` | '_ \\| '_ \\ / _ \\/ _` | '_ \\ \n | |   | | | (_) | |  __/ (__| |_  | |  | |  __/ (_| | | | | |_) |  __/ (_| | | | |\n |_|   |_|  \\___/| |\\___|\\___|\\__| |_|  |_|\\___|\\__,_|_| |_|_.__/ \\___|\\__,_|_| |_|\n                _/ |\n               |__/                                                                \n");

    // Display swords in ASCII art
    // Link:
    wprintw(windows[2], "           /\\                                                 /\\\n _         )( ______________________   ______________________ )(         _\n(_)///////(**)______________________\\ /______________________(**)\\\\\\\\\\\\\\(_)\n           )(                                                 )(\n           \\/                                                 \\/\n");

    // Display castle in ASCII art
    // Link: http://www.ascii-code.com/ascii-art/buildings-and-places/castles.php
    wprintw(windows[3], "                                                  !_\n                        Game over! Try again?     |*~=-.,\n                     Press any key to try again.  |_,-'`\n                          Press 'Q' to quit.      |\n                                                  |\n                                                 /^\\\n                   !_                           /   \\\n                   |*`~-.,                     /,    \\\n                   |.-~^`                     /#\"     \\\n                   |                        _/##_   _  \\_\n              _   _|  _   _   _            [ ]_[ ]_[ ]_[ ]\n             [ ]_[ ]_[ ]_[ ]_[ ]            |_=_-=_ - =_|\n           !_ |_=_ =-_-_  = =_|           !_ |=_= -    |\n           |*`--,_- _        |            |*`~-.,= []  |\n           |.-'|=     []     |   !_       |_.-\"`_-     |\n           |   |_=- -        |   |*`~-.,  |  |=_-      |\n          /^\\  |=_= -        |   |_,-~`  /^\\ |_ - =[]  |\n      _  /   \\_|_=- _   _   _|  _|  _   /   \\|=_-      |\n     [ ]/,    \\[ ]_[ ]_[ ]_[ ]_[ ]_[ ]_/,    \\[ ]=-    |\n      |/#\"     \\_=-___=__=__- =-_ -=_ /#\"     \\| _ []  |\n     _/##_   _  \\_-_ =  _____       _/##_   _  \\_ -    |\\\n    [ ]_[ ]_[ ]_[ ]=_0~{_ _ _}~0   [ ]_[ ]_[ ]_[ ]=-   | \\\n    |_=__-_=-_  =_|-=_ |  ,  |     |_=-___-_ =-__|_    |  \\\n     | _- =-     |-_   | ((* |      |= _=       | -    |___\\\n     |= -_=      |=  _ |  `  |      |_-=_       |=_    |/+\\|\n     | =_  -     |_ = _ `-.-`       | =_ = =    |=_-   ||+||\n");

    // Update panels as necessary to display
    update_panels();
    doupdate();

    return getch();
}
