#include "headers.h"

// arguments: struct table of table info; int row, col of cell; string input for cell
// returns void 
// udpates specified cell with input
void update_cell(struct table * tbl, int row, int col, char * input){
    strcpy(tbl->arr[row][col]->input, input);
}

