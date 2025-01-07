#include "headers.h"

// arguments: name and dimensions of new table
// returns void 
// returns table struct containing table array, name, rows, and cols 
struct table create_table(char* name, int rows, int cols){
    struct table *tbl = malloc(sizeof(struct table)); 
}

// no arguments 
// returns void 
// displays contents of table in spreadsheet format 
void display_table(){

}

// no arguments 
// returns void 
// displays all available tables with their names and dimensions
void table_list(){

}

// arguments: name of table to access
// returns void
// display contents of accessed table, prompt user to read/write
void access_table(char* name){

}

// arguments: name of table to delete 
// returns void 
// deletes specified table and displays updated tab list
void delete_table(char* name){

}