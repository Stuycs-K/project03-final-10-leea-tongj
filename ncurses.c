#include "headers.h"
#include <ncurses.h>

extern struct table * curr_tbl;
extern int curr_row;
extern int curr_col;
extern char *clipboard;

static void sighandler(int signo) {
    if (signo == SIGINT) { //copy info 
        clipboard = curr_tbl->arr[curr_row][curr_col]->input;
    }
    if (signo == SIGSTOP) { //paste info
        update_cell(curr_tbl, curr_row, curr_col, clipboard);
    }
    if (signo == SIGQUIT) { //exit
        endwin();
        exit(0);
    }
}

void sig() {
    signal(SIGINT, sighandler);
    signal(SIGSTOP, sighandler);
    signal(SIGQUIT, sighandler);
}

//if the user wants to edit a table
void edit_table(struct table * tbl){
    curr_row = 0;
    curr_col = 0;
    for (int i = 0; i < tbl->rows; i++){
        for (int j = 0; j < tbl->cols; j++){
            printw("%10.10s %s", tbl->arr[i][j]->input, " "); 
            if (j == tbl->cols -1){
                printw("\n"); 
            }
        }
    }
    move(0, 9);
    refresh();
}

void ncurses(struct table * tbl) {
    sig();
    // initize screen
    initscr();

    keypad(stdscr, TRUE); // Enable keypad mode to recognize special keys
    //noecho(); // Don't echo input characters to the screen
    edit_table(tbl);
    WINDOW *win = newwin(3, 12, 0, 0);
    box(win, 0, 0);
    wrefresh(win);
    int ch;
    while (1) { 
        ch = getch();
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
            case KEY_BACKSPACE:
                delch();
                break;
            default:
                //printw("Character pressed: %c\n", ch);
                break;
        }
    }
}