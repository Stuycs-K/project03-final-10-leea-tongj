#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

struct entry {
    char input[256]; 
    int row; 
    int col;
};

// cell/table edits
void update_cell(char ** table, int row, int col, char * input);
char * clear_cell(int row, int col);
void add_row();
void add_column();

// tab creation + display
char ** create_tab(char* name, int rows, int cols);
void display_tab();
void tab_list();
void access_tab(char* name);
void delete_tab(char* name); 

//csv
void read_csv(char *PATH);