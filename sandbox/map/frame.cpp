#include "frame.h"

/* Constructor (No Parent Window) */
Frame::Frame(int nr_rows, int nr_columns, int row_init, int column_init) {
    hasParent = FALSE;
    parent_w = NULL;
    w = newwin(nr_rows, nr_columns, row_init, column_init);
    height = nr_rows;
    width = nr_columns;
    row = row_init;
    column = column_init;
}

/* Constructor (With Parent Window) */
Frame::Frame(Frame &sw, int nr_rows, int nr_columns, int row_init, int column_init) {
    hasParent = TRUE;
    parent_w = sw.getWindow();
    w = derwin(sw.getWindow(), nr_rows, nr_columns, row_init, column_init);
    height = nr_rows;
    width = nr_columns;
    row = row_init;
    column = column_init;
}

/* Destructor */
Frame::~Frame() {
    delwin(w);
}

/* Accessor Functions */
WINDOW* Frame::getWindow() {
    return w;
}

WINDOW* Frame::getParentWindow() {
    return parent_w;
}

int Frame::getHeight() {
    return height;
}

int Frame::getWidth() {
    return width;
}

int Frame::getRow() {
    return row;
}

int Frame::getColumn() {
    return column;
}

bool Frame::getHasParent() {
    return hasParent;
}

/* Mutator Functions */
void Frame::fill_window() {
    int max_x = width/2;
    int max_y = height/2;

    // Fill the first region with 0's
    for(int y = 0; y < max_y; ++y) {
        for(int x = 0; x < max_x; ++x) {
            mvwaddch(w, y, x, '0');
        }
    }

    // Fill the second region with 1's
    for(int y = 0; y < max_y; ++y) {
        for(int x = max_x; x < width; ++x) {
            mvwaddch(w, y, x, '1');
        }
    }

    // Fill the third region with 2's
    for(int y = max_y; y < height; ++y) {
      for(int x = 0; x < max_x; ++x) {
        mvwaddch(w, y, x, '2');
      }
    }

    // Fill the fourth region with 3's
    for(int y = max_y; y < height; ++y) {
        for(int x = max_x; x < width; ++x) {
            mvwaddch(w, y, x, '3');
        }
    }

    for(int y = 0; y < height; ++y) {
        mvwaddch(w, y, 0, '-');
        mvwaddch(w, y, width - 1, '-');
    }

    for(int x = 0; x < width; ++x) {
        mvwaddch(w, 0, x, '|');
        mvwaddch(w, height - 1, x, '|');
    }
}

void Frame::refresh() {
    if(hasParent) {
        touchwin(parent_w);
    }

    wrefresh(w);
}

void Frame::move(int r, int c) {
    if(hasParent) {
        mvderwin(w, r, c);
        row = r;
        column = c;
        refresh();
    }
}

void Frame::add(Character &x) {
    mvwaddch(w, x.getRow(), x.getColumn(), x.getSymbol());
}

void Frame::add(Character &x, int row_init, int column_init) {
    if((row_init >= 0 && row_init < height) && (column_init >= 0 && column_init < width)) {
        erase(x);
        mvwaddch(w, row_init, column_init, x.getSymbol());
        x.pos(row_init, column_init);
    }
}

void Frame::erase(Character &x) {
    mvwaddch(w, x.getRow(), x.getColumn(), ' ');
}

void Frame::center(Character &x) {
    if(hasParent) {
        int rr = row;
        int cc = column;
        int hh;
        int ww;

        int r = x.getRow() - height/2;
        int c = x.getColumn() - width/2;

        getmaxyx(parent_w, hh, ww);

        if(c + width >= ww) {
            int delta = ww - (c + width);
            cc = c + delta;
        } else {
            cc = c;
        }

        if(r + height >= hh) {
            int delta = hh - (r + height);
            rr = r + delta;
        } else {
            rr = r;
        }

        if(r < 0) {
            rr = 0;
        }

        if(c < 0) {
            cc = 0;
        }

        move(rr, cc);
    }
}
