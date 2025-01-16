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

void draw_grid(struct table * tbl) {
    refresh();
    WINDOW *windows[10][10];
    for (int i = 0; i < tbl->rows; i++) {
        for (int j = 0; j < tbl->cols; j++) {
            windows[i][j] = newwin(3, 12, 3*i, 12*j+1);
            box(windows[i][j], 0, 0);
            wrefresh(windows[i][j]);
        }
    }
    curr_row = 0;
    curr_col = 0;
    move(1, 2);
}

void ncurses(struct table * tbl) {
    sig();
    // initize screen
    initscr();

    keypad(stdscr, TRUE); // Enable keypad mode to recognize special keys
    
    draw_grid(tbl);
    
    int ch;
    int count = 0;
    while (1) { 
        ch = getch();
        echo();
        switch (ch) {
            case KEY_UP:
                if (curr_row > 0) {
                    curr_row--;
                    move(3*curr_row+1, curr_col*12+2);
                    count = 0;
                    echo();
                }
                break;
            case KEY_DOWN:
                if (curr_row < tbl->rows-1) {
                    curr_row++;
                    move(3*curr_row+1, curr_col*12+2);
                    count = 0;
                    echo();
                }
                break;
            case KEY_LEFT:
                if (curr_col > 0) {
                    curr_col--;
                    move(3*curr_row+1, curr_col*12+2);
                    count = 0;
                    echo();
                }
                break;
            case KEY_RIGHT:
                if (curr_col < tbl->cols-1) {
                    curr_col++;
                    move(3*curr_row+1, curr_col*12+2);
                    count = 0;
                    echo();
                }
                break;
            case KEY_BACKSPACE:
                delch();
                if (count > 0) {
                    count--;
                }
                break;
            case 27: //escape key
                noecho();
                endwin();
                break;
            case 10: //enter key
                move(1, 2);
                delch();
                delch();
                break;
            default:
                //printw("Character pressed: %c\n", ch);
                count++;
                if (count > 9) {
                    noecho();
                }
                break;
        }
    }
}