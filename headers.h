#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct table{
    char name[256]; 
    char input[10][10]; 
    int rows; 
    int cols; 
};

struct cell {
    char input[20]; 
    int row; 
    int col;
};

// cell/table edits
void update_cell(struct table table, int row, int col, char * input);
char * clear_cell(int row, int col);
void add_row();
void add_column();

// tab creation + display
char ** create_tab(char* name, int rows, int cols);
void display_tab();
void tab_list();
void access_tab(char* name);
void delete_tab(char* name); 