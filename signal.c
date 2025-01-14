#include "headers.h"

static void sighandler(int signo) {
    if (signo == SIGINT) { //copy info 
        
    }
    if (signo == SIGSTOP) { //paste info
        
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