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
    display_table(tbl);
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

