#include "headers.h"


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
    strcat(menu, "[import] import table \n"); 
    //if no tables created, only display create table option
    if (tbl_list[0]){
        if (home){
            strcat(menu, "[view_list] view table list \n"); 
        }
        if (view){
            strcat(menu, "[select n] select table #n\n"); 
        }
        if (select){
            strcat(menu, "[access] access the table in new window \n"); 
            strcat(menu, "[delete] delete table \n"); 
            strcat(menu, "[export] export table to file \n");
        }
    }
    printf("%s", menu);
}

// prompts user with table list function options
int table_lst_func(struct table ** tbl_lst){
    printf("Welcome to the spreadsheet. Begin by typing in the prompt with a menu directive");
    display_menu(tbl_lst, 0, 0, 0);
}