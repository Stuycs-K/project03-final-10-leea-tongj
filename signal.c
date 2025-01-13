#include "headers.h"
#include <windows.h>

static void sighandler(int signo) {
    if (signo == SIGINT) { //copy info 
        
    }
    if (signo == SIGSTP) { //paste info

    }
    if (signo == SIGQUIT) { //exit
        exit(0);
    }
}
int main() {
    signal(SIGINT, sighandler);
    signal(SIGSTP, sighandler);
    signal(SIGQUIT, sighandler);
}