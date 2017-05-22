#include "character.h"

/* Constructor */
Character::Character(char symbol_init, int row_init, int column_init) {
    symbol = symbol_init;
    row = row_init;
    column = column_init;
}

/* Destructor */
Character::~Character() {

}

/* Mutator Function */
void Character::pos(int row_new, int column_new) {
    row = row_new;
    column = column_new;
}

/* Accessor Functions */
int Character::getRow() {
    return row;
}

int Character::getColumn() {
    return column;
}

char Character::getSymbol() {
    return symbol;
}
