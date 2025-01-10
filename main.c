#include "headers.h"

int main(){
    char name[10] = "first table"; 
    int rows = 2; 
    int cols = 2; 
    struct table * tbl = create_table(name, rows, cols);
    srand(time(NULL)); 
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            tbl->arr[i][j] = rand() % 10; 
        }
    }

    display_table(tbl); 

}