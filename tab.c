#include "headers.h"

// global variables
extern struct table * curr_tbl;
extern int curr_row;
extern int curr_col;
extern char *clipboard;

int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
} 

//no arguments
//returns pointer to array of struct tables 
//initializies array of struct tables
struct table ** init_table_list(){
    struct table** tbl_lst = malloc(20 * sizeof(struct table *));
    for (int i = 0; i < 20; i++){
        tbl_lst[i] = NULL;
    }
    return tbl_lst; 
}

// no arguments 
// returns void 
// displays all available tables with their names and dimensions
void display_table_list(struct table ** tbl_lst){
    printf("TABLE LIST: \n");
    for (int i = 0; tbl_lst[i]; i++){
        printf("[%d] %s\n", i, tbl_lst[i]->name); 
        printf("Dimensions: %d x %d\n\n", tbl_lst[i]->rows, tbl_lst[i]->cols);
    }
}

// arguments: name and dimensions of new table
// returns void 
// returns table struct containing table array, name, rows, and cols 
struct table * create_table(struct table ** tbl_list, char* name, int rows, int cols){
    struct table *tbl = (struct table*) malloc(sizeof(struct table)); 
    strcpy(tbl->name, name); 
    tbl->rows = rows; 
    tbl->cols = cols; 
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            struct cell * cll = (struct cell *) malloc(sizeof(struct cell)); 
            cll->row = i; 
            cll->col = j; 

            strcpy(cll->input, (char *)calloc(10, sizeof(char))); 
            tbl->arr[i][j] = cll;
        }
    }
    int place = add_table(tbl_list, tbl); 
    return tbl; 
}

// arguments: name of table to access
// returns int, place in table 
// display contents of accessed table, prompt user to read/write
int add_table(struct table ** tbl_lst, struct table * tbl){
    for (int i = 0; i < 20; i++){
        if (!tbl_lst[i]){
            tbl_lst[i] = tbl; 
            return i;
        }
        if (i == 19){
            printf("Met max size of table_list!");
        }
    }
    return -1;
}

// arguments: int place of table in tbl_list, asks if user would like to export file
// returns void
// deletes specified table and displays updated tab list
void delete_table(struct table ** tbl_lst, int place, int export){
   if (export){
       write_csv(tbl_lst[place]);
   }
   free(tbl_lst[place]);
   for (int i = place+1; ((tbl_lst[i]) || (i == place + 1)); i++){
       tbl_lst[i-1] = tbl_lst[i];
       if (tbl_lst[i+1] == NULL){
           tbl_lst[i] = NULL;
       }
   }
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
