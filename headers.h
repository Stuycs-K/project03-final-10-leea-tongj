#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <errno.h>

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
int err();
struct table * create_table(char* name, int rows, int cols);
void display_table(struct table * tbl);
void export_file(struct table *tbl);
void read_file(char* name);
struct table ** init_table_list();
void display_table_list(struct table ** lst);
void access_table(char* name);
void delete_table(char* name); 

//csv
struct table * read_csv(char *name, char *PATH);

#endif
