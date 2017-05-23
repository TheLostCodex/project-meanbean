#include "game_loop.h"
#include <cmath>

void game_loop(Frame &game_map, Frame &viewport, Character &main_char, Character &monster, int ch) {
    // Check if user wants to quit
    if(ch == 'q' || ch == 'Q') return;

    // Display main character on the screen
    game_map.add(main_char);
    game_map.add(monster);
    viewport.center(main_char);
    viewport.refresh();

    while(1) {
        ch = getch();

        bool gameOver = FALSE;

        // Movement
        if(ch == KEY_LEFT) {
            gameOver = game_map.add(main_char, main_char.getRow(), main_char.getColumn() - 1);
            viewport.center(main_char);
            viewport.refresh();
        }

        else if(ch == KEY_RIGHT) {
            gameOver = game_map.add(main_char, main_char.getRow(), main_char.getColumn() + 1);
            viewport.center(main_char);
            viewport.refresh();
        }

        else if(ch == KEY_UP) {
            gameOver = game_map.add(main_char, main_char.getRow() - 1, main_char.getColumn());
            viewport.center(main_char);
            viewport.refresh();
        }

        else if(ch == KEY_DOWN) {
            gameOver = game_map.add(main_char, main_char.getRow() + 1, main_char.getColumn());
            viewport.center(main_char);
            viewport.refresh();
        }

        else if(ch == 'q' || ch == 'Q' || gameOver) {
            break;
        }

        int pos = -1;
        int score = game_map.getHeight() * game_map.getHeight() + game_map.getWidth()*game_map.getWidth();
        int dist = -1;

        if(game_map.target_position(monster.getRow(), monster.getColumn() - 1)) {
            dist = std::pow(main_char.getRow() - monster.getRow(), 2) + std::pow(main_char.getColumn() - (monster.getColumn() - 1), 2);
            if(score > dist) {
                score = dist;
                pos = 0;
            }
        }

        if(game_map.target_position(monster.getRow(), monster.getColumn() + 1)) {
            dist = std::pow(main_char.getRow() - monster.getRow(), 2) + std::pow(main_char.getColumn() - (monster.getColumn() + 1), 2);
            if(score > dist) {
                score = dist;
                pos = 1;
            }
        }

        if(game_map.target_position(monster.getRow() - 1, monster.getColumn())) {
            dist = std::pow(main_char.getRow() - (monster.getRow() - 1), 2) + std::pow(main_char.getColumn() - (monster.getColumn()), 2);
            if(score > dist) {
                score = dist;
                pos = 2;
            }
        }

        if(game_map.target_position(monster.getRow() + 1, monster.getColumn())) {
            dist = std::pow(main_char.getRow() - (monster.getRow() + 1), 2) + std::pow(main_char.getColumn() - (monster.getColumn()), 2);
            if(score > dist) {
                score = dist;
                pos = 3;
            }
        }

        switch(pos) {
            case 0:
                gameOver = game_map.add(monster, monster.getRow(), monster.getColumn() - 1);
                break;
            case 1:
                gameOver = game_map.add(monster, monster.getRow(), monster.getColumn() + 1);
                break;
            case 2:
                gameOver = game_map.add(monster, monster.getRow() - 1, monster.getColumn());
                break;
            case 3:
                gameOver = game_map.add(monster, monster.getRow() + 1, monster.getColumn());
                break;
        }

        viewport.center(main_char);
        viewport.refresh();

        if(gameOver) return;
    }
}
