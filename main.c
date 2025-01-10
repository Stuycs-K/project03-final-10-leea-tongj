#include "headers.h"

int main(){
    char name[10] = "table1"; 
    int rows = 2; 
    int cols = 2; 
    struct table * tbl = create_table(name, rows, cols);
    display_table(tbl); 

    update_cell(tbl, 0, 0, "hi");
    update_cell(tbl, 0, 1, "hello");
    display_table(tbl);
    char output[10];
    strcpy(output, clear_cell(tbl, 0, 1)); 
    display_table(tbl); 
    printf("Value removed: %s", output);

     // if user chooses this option, they will be prompted for the name of the table and the path to the csv file
    // e.g. read_csv("NYC Population Data", "../lab09-structrw-alee51/nyc_pop.csv");
}