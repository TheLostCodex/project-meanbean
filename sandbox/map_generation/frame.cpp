#include "frame.h"
#include "perlin_noise.h"

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
void Frame::genPerlin(const unsigned int &seed) {
    PerlinNoise pn(seed);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            double x = (double)j/((double)width);
            double y = (double)i/((double)height);

            double n = pn.noise(10 * x, 10 * y, 0.8);

            if(n < 0.35) {
                // Add water
                init_pair(1, COLOR_BLUE, COLOR_BLACK);
                mvwaddch(w, i, j, '~' | COLOR_PAIR(1));
            } else if(n >= 0.35 && n < 0.6) {
                // Add Grass
                init_pair(2, COLOR_GREEN, COLOR_BLACK);
                mvwaddch(w, i, j, '^' | COLOR_PAIR(2) | A_BOLD);
            } else if(n >= 0.6 && n < 0.8) {
                // Add Mountains
                init_pair(3, COLOR_YELLOW, COLOR_BLACK);
                mvwaddch(w, i, j, '#' | COLOR_PAIR(3));
            } else {
                // Add Snow
                mvwaddch(w, i, j, '*');
            }
        }
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
        char target = (char)mvwinch(w, row_init, column_init);

        if(target == '~' || target == '#' || target == '*') return;

        replace(x, target);
        mvwaddch(w, row_init, column_init, x.getSymbol());
        x.pos(row_init, column_init);
    }
}

void Frame::erase(Character &x) {
    mvwaddch(w, x.getRow(), x.getColumn(), ' ');
}

void Frame::replace(Character &x, char tile) {
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

    mvwaddch(w, x.getRow(), x.getColumn(), tile | COLOR_PAIR(2));
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
