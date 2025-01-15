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
}

// prompts user with table function options
int table_func(struct table * tbl){

}



// prompts user with table list function options
int table_lst_func(struct table ** tbl_lst){
    printf("Welcome to the spreadsheet. Choose from menu below: "); 
    char buff[10]; 
    fgets(buff, sizeof(buff), stdin);
    if (!strcmp(buff, "Y")){
        display_table_list(tbl_lst); 
        printf("Select a table: "); 
        int val; 
        fgets(&val, sizeof(int), stdin); 
        printf("Would you like to access or delete table %d?", val); 
        char acde[10]; 
        fgets(acde, sizeof(acde), stdin); 
        if (!strcmp(acde, "delete")){
            delete_table(tbl_lst, val, 0);
        }
    }
}