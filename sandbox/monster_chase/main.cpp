#include <ncurses.h>
#include "screen.h"
#include "frame.h"
#include "character.h"
#include "game_loop.h"
#include "perlin_noise.h"

int main() {
    Screen scr;

    // Print a welcome message
    scr.display("Welcome to Project Meanbean\n");
    scr.display("Press any key to start.\n");
    scr.display("Press 'Q' to quit\n");

    // Get user input
    int ch = getch();

    // Create a NCurses window to store the map
    Frame game_map(2 * scr.getHeight(), 2 * scr.getWidth(), 0, 0);

    // Subwindow of game map
    Frame viewport(game_map, scr.getHeight(), scr.getWidth(), 0, 0);

    // Initialize the main character to middle of the map and a monster
    Character main_char('@', game_map.getHeight()/2, game_map.getWidth()/2);
    Character monster('$', game_map.getHeight()/2 + 7, game_map.getWidth()/2 + 22);

    // File the game map with numbers
    game_map.genPerlin(1);

    game_loop(game_map, viewport, main_char, monster, ch);
    clear();

    scr.display("Game Over! The Monster got you! Press any key to quit.\n");

    getch();

    return 0;
}
