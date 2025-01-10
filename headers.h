#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct table{
    char name[256]; 
    struct cell * arr[10][10]; 
    int rows; 
    int cols; 
};

struct cell {
    char input[20];  
    int row; 
    int col;
};

// cell/table edits
void update_cell(struct table * tbl, int row, int col, char * input);
char * clear_cell(struct table * tbl, int row, int col);
void add_row();
void add_column();

// tab creation + display
struct table * create_table(char* name, int rows, int cols);
void display_table(struct table * tbl);
void table_list();
void access_table(char* name);
void delete_table(char* name); 