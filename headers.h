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
#include <signal.h>
#include <wait.h>

struct table{
    char name[256]; 
    struct cell * arr[10][10]; 
    int rows; 
    int cols; 
};

struct cell {
    char input[10];  
    int row; 
    int col;
};

// cell/table edits
void update_cell(struct table * tbl, int row, int col, char * input);
void resize(struct table *tbl, int row, int col);

// tab creation + display
int err();
struct table * create_table(struct table ** tbl_list, char* name, int rows, int cols);
void export_file(struct table *tbl);
struct table ** init_table_list();
void display_table_list(struct table ** lst);
int add_table(struct table ** tbl_lst, struct table * tbl);
void delete_table(struct table ** tbl_lst, int place, int export);

//csv
struct table * read_csv(struct table ** tbl_lst, char *name, char *PATH);
void write_csv(struct table *tbl);
void view_csv_file(char* name);
void view_csv_stats(char * name);
char* conv(long long n);

//signal
static void sighandler(int signo);
void sig();

//ncurses
void ncurses(struct table * tbl);
void draw_grid(struct table * tbl);

//user 
void parse_args(char * line, char * sep, char ** arg_ary);
int tbl_lst_size(struct table ** tbl_lst);
void display_home_menu(struct table ** tbl_list);
void display_view_menu(struct table ** tbl_list);
void table_lst_func(struct table ** tbl_lst, int *uhome, int *uview);

#endif
