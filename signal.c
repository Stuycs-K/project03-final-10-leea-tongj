#include "headers.h"

static void sighandler(int signo) {
    if (signo == SIGINT) { //copy info 
        clipboard = tbl->arr[row][col]->input;
    }
    if (signo == SIGSTOP) { //paste info
        update_cell(tbl, row, col, clipboard);
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