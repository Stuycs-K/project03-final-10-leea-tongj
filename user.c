#include "headers.h"

// prompts user with table function options
int table_func(struct table * tbl){

}

// prompts user with table list function options
int table_lst_func(struct table ** tbl_lst){
    printf("Would you like to view your table list? (Y/N)"); 
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