#include "headers.h"

int err(){
    printf("errno %d\n",errno);
    printf("%s\n",strerror(errno));
    exit(1);
} 

// arguments: name and dimensions of new table
// returns void 
// returns table struct containing table array, name, rows, and cols 
struct table * create_table(char* name, int rows, int cols){
    struct table *tbl = (struct table*) malloc(sizeof(struct table)); 
    strcpy(tbl->name, name); 
    tbl->rows = rows; 
    tbl->cols = cols; 
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            struct cell * cll = (struct cell *) malloc(sizeof(struct cell)); 
            cll->row = i; 
            cll->col = j; 
            strcpy(cll->input, "0"); 
            tbl->arr[i][j] = cll;
        }
    }
    return tbl; 
}

// no arguments 
// returns void 
// displays contents of table in spreadsheet format 
void display_table(struct table * tbl){
    for (int i = 0; i < tbl->rows; i++){
        for (int j = 0; j < tbl->cols; j++){
            printf("|%s", tbl->arr[i][j]->input); 
            if (j == tbl->cols -1){
                printf("|\n"); 
            }
        }
    }
}

void export_file(struct table *tbl){ 
    char filename[256]; 
    strcpy(filename, tbl->name);
    strcat(filename, ".txt");
    int w_file = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0611);
    if (w_file == -1){
        err();
        printf("w_file : %u\n", w_file);
    }
    for (int i = 0; i < tbl->rows; i++){
        for (int j = 0; j < tbl->cols; j++){
            write(w_file, tbl->arr[i][j]->input, sizeof(tbl->arr[i][j]->input));
        }
    }
}

// void read_file(char* name){
//     int r_file = open(name, O_RDONLY, 0);
//     if (r_file == -1){
//         err(); 
//         printf("r_file: %u\n", r_file); 
//     }
//     char buff[1000]; 
// }


//no arguments
//returns pointer to array of struct tables 
//initializies array of struct tables
struct table ** init_table_list(){
    struct table * tab[20];
    for (int i = 0; i < 20; i++){
        tab[i] = (struct table *)malloc(sizeof(struct table));
    }
    return tab; 
}

// no arguments 
// returns void 
// displays all available tables with their names and dimensions
void display_table_list(struct table ** lst){
    for (int i = 0; lst[i]; i++){
        printf("[%d]%s", i, lst[i]->name); 
        printf("Dimensions: %d x %d", lst[i]->rows, lst[i]->cols);
    }
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