#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
    int row;
    int column;
    char symbol;

  public:
    // Constructor and Destructor
    Character(char symbol, int row_init, int column_init);
    ~Character();

    // Mutator Functions
    void pos(int row_new, int column_new);

    // Accessor Functions
    int getRow();
    int getColumn();
    char getSymbol();
};

#endif
