#include "headers.h"

int main(){
    char name[10] = "first table"; 
    int rows = 2; 
    int cols = 2; 
    struct table * tbl = create_table(name, rows, cols);
    display_table(tbl); 

}