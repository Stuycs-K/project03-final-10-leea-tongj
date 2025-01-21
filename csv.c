#include "headers.h"

// arguments: name of file, 
// returns pointer to table struct
// converts csv to table
struct table * read_csv(char *name, char *PATH) {
    char s[256];
    FILE *csv = fopen(PATH, "r");
    fgets(s, 255, csv);
    char *curr = s;
    int cols = 0;
    while (curr) {
        strsep(&curr, ",");
        cols++;
    }
    int rows = 1;
    while (fgets(s, 255, csv)) {
        rows++;
    }
    // printf("rows: %d columns: %d\n", rows, cols);
    struct table ** tbl_list = init_table_list();
    return create_table(tbl_list, name, rows, cols);
}

// arguments: pointer to table struct 
// returns void 
// exports table info to a csv file
void write_csv(struct table *tbl) { 
    char filename[256]; 
    strcpy(filename, tbl->name);
    strcat(filename, ".csv");
    int w_file = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0611);
    if (w_file == -1){
        err();
        printf("w_file : %u\n", w_file);
    }
    for (int i = 0; i < tbl->rows; i++){
        for (int j = 0; j < tbl->cols; j++){
            char *entry = tbl->arr[i][j]->input;
            write(w_file, entry, sizeof(entry));
            if (j != tbl->cols-1) {
                write(w_file, ",", 1);
            }
        }
        write(w_file, "\n", 1);
    }
    close(w_file);
}

void view_csv_file(char* name){
    char cat[256] = "cat "; 
    strcat(cat, name); 
    char * arg_ary[3]; 
    parse_args(cat, " ", arg_ary); 
    pid_t p1 = fork();
    if (p1 < 0){
        perror("forkfail"); 
        exit(1); 
    } else if (p1 == 0){
        execvp(arg_ary[0], arg_ary); 
    }
    else{
        int status; 
        wait(&status); 
    }
}

void view_csv_stats(char * name){
    
}