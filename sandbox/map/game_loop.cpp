#include "game_loop.h"

void game_loop(Frame &game_map, Frame &viewport, Character &main_char, int ch) {
    // Check if user wants to quit
    if(ch == 'q' || ch == 'Q') return;

    // Display main character on the screen
    game_map.add(main_char);
    viewport.center(main_char);
    viewport.refresh();

    while(1) {
        ch = getch();

        // Movement
        if(ch == KEY_LEFT) {
            game_map.add(main_char, main_char.getRow(), main_char.getColumn() - 1);
            viewport.center(main_char);
            viewport.refresh();
        }

        else if(ch == KEY_RIGHT) {
            game_map.add(main_char, main_char.getRow(), main_char.getColumn() + 1);
            viewport.center(main_char);
            viewport.refresh();
        }

        else if(ch == KEY_UP) {
            game_map.add(main_char, main_char.getRow() - 1, main_char.getColumn());
            viewport.center(main_char);
            viewport.refresh();
        }

        else if(ch == KEY_DOWN) {
            game_map.add(main_char, main_char.getRow() + 1, main_char.getColumn());
            viewport.center(main_char);
            viewport.refresh();
        }

        else if(ch == 'q' || ch == 'Q') {
            break;
        }
    }
}
