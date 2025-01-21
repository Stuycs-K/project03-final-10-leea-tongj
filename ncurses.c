#include "headers.h"
#include <ncurses.h>

extern struct table * curr_tbl;
extern int curr_row;
extern int curr_col;
extern char *clipboard;
WINDOW *windows[10][10];

static void sighandler(int signo) {
    if (signo == SIGINT) { //copy info
        sprintf(clipboard, "%-11s", curr_tbl->arr[curr_row][curr_col]->input);
        // clipboard = curr_tbl->arr[curr_row][curr_col]->input;
        // printw("%s", clipboard);
        // refresh();
    }
    if (signo == SIGQUIT) { //exit
        endwin();
        exit(0);
    }
}

void sig() {
    signal(SIGINT, sighandler);
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

void fill_table(struct table *tbl) {
    for (int i = 0; i < tbl->rows; i++) {
        for (int j = 0; j < tbl->cols; j++) {
            mvwprintw(windows[i][j], 1, 1, "%s", tbl->arr[i][j]->input);
            wrefresh(windows[i][j]);
        }
    }
    refresh();
    curr_row = 0;
    curr_col = 0;
    move(1, 2);
}

void ncurses(struct table * tbl) {
    curr_tbl = tbl;
    clipboard = (char *)calloc(11, sizeof(char));
    sig();
    // initize screen
    initscr();

    keypad(stdscr, TRUE); // Enable keypad mode to recognize special keys
    
    draw_grid(tbl);
    fill_table(tbl);
    
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
            case ('f' & 0x1F): //ctrl+v
                delch(); delch();
                update_cell(curr_tbl, curr_row, curr_col, clipboard);
                move(3*curr_row+1, 12*curr_col+2);
                printw("%s", clipboard);
                refresh();
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