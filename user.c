#include "headers.h"

// arguments: str inputted, max size of str, prompt to repeat 
// returns void
// notifies user if they exceed the intended size of the str/input unintended info
void strerr(char * str, int size, char * repeat){
    if (strlen(str) > size){
        printf("Maximum size of input is %d\n", size); 
        printf("%s", repeat);
    }
}

void parse_args(char * line, char ** arg_ary){
    char *curr = line; 
    int i = 0; 
    while (curr){
        arg_ary[i] = strsep(&curr, " ");
        i++; 
    }
    arg_ary[i] = NULL; 
}

// pointer to tbl_list
// int home indicates whether previous command was home 
// int view indicates whether previous command was view list
// int access indicates whether previous command was access table
// returns void 
// displays the menu depending on tbl_list size and whether view was called
void display_menu(struct table ** tbl_list, int home, int view, int select){
    char menu[400] = "Choose from the menu below: \n"; 
    strcat(menu, "[home] return to home page \n"); 
    strcat(menu, "[create] create table \n"); 
    strcat(menu, "[import] import csv file to table \n"); 
    //if no tables created, only display create table option
    if (tbl_list[0]){
        if (home){
            strcat(menu, "[view_list] view table list \n"); 
        }
        if (view){
            strcat(menu, "[edit n] edit nth table in new window \n"); 
            strcat(menu, "[delete n] delete nth table \n"); 
            strcat(menu, "[export n] export nth table to csv file \n");
        }
    }
    printf("%s", menu);
}

// prompts user with table list function options
int table_lst_func(struct table ** tbl_lst){
    printf("Welcome to the spreadsheet. Begin by typing in the prompt with a menu directive\n");
    display_menu(tbl_lst, 0, 0, 0);
    printf("Prompt: "); 
    char buff[100]; 
    fgets(buff, sizeof(buff), stdin); 
    char * args[3]; 
    parse_args(buff, args);
    if (!strcmp(args[0], "home")){
        display_menu(tbl_lst, 1, 0, 0);
    }

    if (!strcmp(args[0], "import")){
        printf("Provide the path to the csv you'd like to import: "); 
        char path[256]; 
        fgets(path, sizeof(path), stdin); 
        printf("Name the new file: "); 
        char name[256]; 
        fgets(name, sizeof(name), stdin); 
        read_csv(name, path);
    }

    if (!strcmp(args[0], "view_list")){
        display_menu(tbl_lst, 0, 1, 0);
        display_table_list(tbl_lst); 
    }

    if (!strcmp(args[0], "edit")){
        ncurses(); 
    }

    if (!strcmp(args[0], "delete")){
        printf("Before deletion, would you like to export this table? (Y/N)"); 
        char val[5];
        fgets(val, sizeof(char), stdin); 
        delete_table(tbl_lst, args[1], strcmp(val, "Y"));
    }
}