#include "headers.h"

// global variables
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
        exit(0);
    }
}
void sig() {
    signal(SIGINT, sighandler);
    signal(SIGSTOP, sighandler);
    signal(SIGQUIT, sighandler);
}