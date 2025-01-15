#include "headers.h"
#include <ncurses.h>

void ncurses() {
    // init screen and sets up screen
    initscr();

    // print to screen
    printw("Hello World");

    // refreshes the screen
    refresh();

    // pause the screen output
    getch();

    // deallocates memory and ends ncurses
    endwin();
}