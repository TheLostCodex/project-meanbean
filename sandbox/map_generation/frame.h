#include <ncurses.h>
#include "character.h"

#ifndef FRAME_H
#define FRAME_H

class Frame {
    int height;
    int width;
    int row;
    int column;

    bool hasParent;

    WINDOW *w;
    WINDOW *parent_w;

  public:
    // Constructor for a window without a parent window
    Frame(int nr_rows, int nr_columns, int row_init, int column_init);

    // Constructor for a window with a parent window
    Frame(Frame &sw, int nr_rows, int nr_columns, int row_init, int column_init);

    // Destructor
    ~Frame();

    // Accessor Functions
    WINDOW* getWindow();
    WINDOW* getParentWindow();
    int getHeight();
    int getWidth();
    int getRow();
    int getColumn();
    bool getHasParent();

    // Mutator Functions
    void genPerlin(const unsigned int &seed);
    void refresh();
    void move(int r, int c);
    void add(Character &x);
    void add(Character &x, int row_init, int column_init);
    void erase(Character &x);
    void replace(Character &x, char tile);
    void center(Character &x);

};

#endif
