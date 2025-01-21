#include "headers.h"

// arguments: struct table of table info; int row, col of cell; string input for cell
// returns void 
// udpates specified cell with input
void update_cell(struct table * tbl, int row, int col, char * input){
    strcpy(tbl->arr[row][col]->input, input);
}

// arguments: pointer to tbl, row, col, new dimensions of table
// returns void 
// resizes the table dimensions 
void resize(struct table *tbl, int row, int col){
    if (row == 10 || col == 10){
        printf("Invalid dimensions! Max dimensions: 10 x 10");
        exit(0);
    }
    tbl->rows += row - tbl->rows; 
    tbl->cols += col - tbl->cols;
}

