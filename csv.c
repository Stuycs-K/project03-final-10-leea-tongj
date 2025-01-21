#include "headers.h"

// arguments: name of file, path to csv file
// returns pointer to table struct
// converts csv to table
void read_csv(struct table ** tbl_lst, char *name, char *PATH) {
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
    struct table *tbl = create_table(tbl_lst, name, rows, cols);
    rewind(csv);
    int row = 0;
    char t[256];
    while (fgets(t, 255, csv)) {
        char *cc = t;
        int col = 0;
        while (cc) {
            char *token = strsep(&cc, ",");
            token = strsep(&token, "\n");
            update_cell(tbl, row, col, token);
            col++;
        }
        row++;
    }
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
    char PATH[56] = "./"; 
    strcat(PATH, name); 
    struct stat * stat_buffer = malloc(sizeof(struct stat));
    stat(PATH, stat_buffer); 
    int size = stat_buffer->st_size; 
    int st_uid = stat_buffer->st_uid; 
    int st_gid = stat_buffer->st_gid; 
    char* st_mode = conv(stat_buffer->st_mode);
    printf("File Name: %s\n", name); 
    printf("File Size: %d\n", size); 
    printf("User ID: %d\n", st_uid);
    printf("Group ID: %d\n", st_gid);
    printf("File Permissions: %s\n", st_mode);
}

char* conv(long long n){
  char*  str = malloc(sizeof(char) * 11); 
  if (n & S_IRUSR) strcat(str, "r"); //owner read 
  else strcat(str, "-"); 
  if (n & S_IWUSR) strcat(str, "w"); //owner write 
  else strcat(str, "-");
  if (n & S_IXUSR) strcat(str, "x"); //owner exec 
  else strcat(str, "-");
  if (n & S_IRGRP) strcat(str, "r"); //group read 
  else strcat(str, "-");
  if (n & S_IWGRP) strcat(str, "w"); //group write 
  else strcat(str, "-");
  if (n & S_IXGRP) strcat(str, "x"); //group exec 
  else strcat(str, "-");
  if (n & S_IROTH) strcat(str, "r"); //other read 
  else strcat(str, "-");
  if (n & S_IWOTH) strcat(str, "w"); //other write 
  else strcat(str, "-");
  if (n & S_IXOTH) strcat(str, "r"); //other exec 
  else strcat(str, "-");

  return str; 
}