#include "headers.h"

// global variables
struct table * curr_tbl;
int curr_row;
int curr_col;
char *clipboard;
int uhome = 1; 
int uview = 0; 

int main() {
    struct table ** tbl_list = init_table_list();
    printf("Welcome to the spreadsheet. Begin by typing in the prompt with a menu directive.");
    while(1){
        printf("\n");
        if (uhome){
            display_home_menu(tbl_list);
        }
        if (uview){
            display_view_menu(tbl_list);
        }
        table_lst_func(tbl_list, &uhome, &uview);
    }
}