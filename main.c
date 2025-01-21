#include "headers.h"

// global variables
struct table * curr_tbl;
int curr_row;
int curr_col;
char *clipboard;
int uhome = 1; 
int uview = 0; 
int uedit = 0; 

int main() {
    struct table ** tbl_list = init_table_list();
    run(tbl_list);
}

void run(struct table ** tbl_list){
    if (!uedit){
        printf("Welcome to the spreadsheet. Begin by typing in the prompt with a menu directive.");
    }
    while(1){
        if (uhome){
            display_home_menu(tbl_list);
        }
        if (uview){
            display_view_menu(tbl_list);
        }
        int val = table_lst_func(tbl_list, &uhome, &uview, &uedit);
        if (val != 1){
            if (val == -2){
                printf("Invalid Table Number!\n\n"); 
            }
            if (val == -1){
                printf("Invalid Dimensions!\n\n");
            }
            if (val == 0){
                printf("Invalid Input!\n\n");
            }
            fflush(stdin);
        }
        
    }
}