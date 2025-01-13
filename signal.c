#include "headers.h"
#include <windows.h>

static void sighandler(int signo) {
    if (signo == SIGINT) { //copy info 
        
    }
    if (signo == SIGSTP) { //paste info
        if (OpenClipboard(NULL)) {
            HANDLE hClipboardData = GetClipboardData(CF_TEXT);
            if (hClipboardData) {
                char *clipboardText = (char *)GlobalLock(hClipboardData);
                printf("Clipboard text: %s\n", clipboardText);
                GlobalUnlock(hClipboardData);
            }
            CloseClipboard(); 
        } else {
            printf("Error accessing clipboard\n");
        }
    }
    if (signo == SIGQUIT) { //exit
        exit(0);
    }
}
void sig() {
    signal(SIGINT, sighandler);
    signal(SIGSTP, sighandler);
    signal(SIGQUIT, sighandler);
}