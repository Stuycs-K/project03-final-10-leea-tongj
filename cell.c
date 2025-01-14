#include "headers.h"

// arguments: struct table of table info; int row, col of cell
// returns char pointer  
// accesses the input of a cell
char * select_cell(struct table *tbl, int row, int col){
    return tbl->arr[row][col]->input;
}

// arguments: struct table of table info; int row, col of cell; string input for cell
// returns void 
// udpates specified cell with input
void update_cell(struct table * tbl, int row, int col, char * input){
    strcpy(tbl->arr[row][col]->input, input);  
}

// arguments: row, col of cell
// returns the cleared input 
// prompts user for row and col of cell to modify and clear the cell's input
char * clear_cell(struct table * tbl, int row, int col){
    char * cleared_input = malloc(10 * sizeof(char)); 
    strcpy(cleared_input, tbl->arr[row][col]->input); 
    strcpy(tbl->arr[row][col]->input, "0"); 
    return cleared_input; 
}

// no arguments
// returns void 
// adds a row to the end of spreadsheet and prompts user for input
void add_row(struct table * tbl){
    if (tbl->rows == 10){
        printf("Max Rows Reached!");
    }
    else{
        tbl->rows++;
    }
}

// no arguments
// returns void 
// adds a column to the spreadsheet and prompts user for input
void add_column(struct table * tbl){
    if (tbl->cols == 10){
        printf("Max Columns Reached!");
    }
    else{
        tbl->cols++;
    }
}
