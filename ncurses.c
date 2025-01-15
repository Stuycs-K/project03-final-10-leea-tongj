#include "headers.h"
#include <ncurses.h>

extern struct table * curr_tbl;
extern int curr_row;
extern int curr_col;
extern char *clipboard;

void ncurses() {
    // init screen and sets up screen
    initscr();

    keypad(stdscr, TRUE); // Enable keypad mode to recognize special keys
    noecho(); // Don't echo input characters to the screen

    int ch;
    while ((ch = getch()) != 'q') {
        switch (ch) {
            case KEY_UP:
                if (curr_row > 0) {
                    curr_row--;
                    move(curr_row, curr_col*10);
                }
                break;
            case KEY_DOWN:
                if (curr_row < 10) {
                    curr_row++;
                    move(curr_row, curr_col*10);
                }
                break;
            case KEY_LEFT:
                if (curr_col > 0) {
                    curr_col--;
                    move(curr_row, curr_col*10);
                }
                break;
            case KEY_RIGHT:
                if (curr_col < 10) {
                    curr_col++;
                    move(curr_row, curr_col*10);
                }
                break;
            default:
                printw("Character pressed: %c\n", ch);
                break;
        }
    }

    // deallocates memory and ends ncurses
    endwin();
}