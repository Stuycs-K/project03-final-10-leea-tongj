#include "headers.h"

// global variables
struct table * curr_tbl;
int curr_row;
int curr_col;
char *clipboard;
int uhome = 1; 
int uview = 0; 

int main(){
    
    struct table ** tbl_list = init_table_list();
    
    char name[10] = "table1"; 
    int rows = 5; 
    int cols = 3; 
    struct table * tbl = create_table(tbl_list, name, rows, cols);
    // display_table(tbl); 
    //table_lst_func(tbl_list);

    // update_cell(tbl, 0, 0, "anas");
    // update_cell(tbl, 0, 1, "hell");
    //ncurses(tbl);
    // display_table(tbl);
    // write_csv(tbl);
    // char output[10];
    // strcpy(output, clear_cell(tbl, 0, 1)); 
    // display_table(tbl); 
    // printf("Value removed: %s\n", output);

    // display_table_list(tbl_list);
    // printf("\n");
    // char name2[10] = "table2";
    // struct table * tbll = create_table(tbl_list, name2, rows, cols);
    // display_table_list(tbl_list);
    // printf("\n");
    // add_row(tbl); 
    // add_column(tbll);
    // display_table_list(tbl_list);
    // printf("\n");
    // delete_table(tbl_list, 1, 0);
    // display_table_list(tbl_list);
    // printf("\n");

    // sig();

     // if user chooses this option, they will be prompted for the name of the table and the path to the csv file
    // e.g. read_csv("NYC Population Data", "../lab09-structrw-alee51/nyc_pop.csv");
}

void run(){
    struct table ** tbl_list = init_table_list();
    printf("Welcome to the spreadsheet. Begin by typing in the prompt with a menu directive\n");
    table_lst_func(tbl_list, uhome, uview);
}