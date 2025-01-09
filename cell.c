#include "headers.h"

// arguments: struct table of table info; int row, col of cell; string input for cell
// returns void 
// udpates specified cell with input
void update_cell(struct table * tbl, int row, int col, char * input){
    (tbl->input[row][col])->input = input; 


}

// arguments: row, col of cell
// returns the cleared input 
// prompts user for row and col of cell to modify and clear the cell's input
char * clear_cell(struct table * tbl, int row, int col){
    char cleared_input[10] = tbl->input[row][col]; 
    tbl->input[row][col] = NULL; 
    return cleared_input; 
}

// no arguments
// returns void 
// adds a row to the end of spreadsheet and prompts user for input
void add_row(){

}

// no arguments
// returns void 
// adds a column to the spreadsheet and prompts user for input
void add_column(){

}
