#include "headers.h"

void parse_args(char * line, char * sep, char ** arg_ary){
    char *curr = line; 
    int i = 0; 
    while (curr){
        arg_ary[i] = strsep(&curr, sep);
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
void display_home_menu(struct table ** tbl_list){
    char menu[400] = "Choose from the menu below: \n";
    strcat(menu, "[create] create table \n"); 
    strcat(menu, "[import] import csv file to table \n"); 
    if (tbl_list[0]){ //if no tables created, only display create table option
        strcat(menu, "[view_list] view list of tables \n");
    }
    printf("%s", menu);
}

void display_view_menu(struct table ** tbl_list){
    char menu[400] = "\nChoose from the menu below: \n";
    strcat(menu, "[home] return to home page \n"); 
    strcat(menu, "[edit n] edit nth table in new window \n"); 
    strcat(menu, "[resize n] resize the dimenions of nth table \n"); 
    strcat(menu, "[delete n] delete nth table \n"); 
    strcat(menu, "[export n] export nth table to csv file \n");
    display_table_list(tbl_list);
    printf("%s", menu);
}

// prompts user with table list function options
void table_lst_func(struct table ** tbl_lst, int *uhome, int *uview){
    printf("Prompt: "); 
    char buff[100]; 
    fgets(buff, sizeof(buff), stdin); //read in user input
    buff[strlen(buff) - 1] = '\0';
    char * args[3]; 
    parse_args(buff, " ", args); 
    printf("\n");
    if (!strcmp(args[0], "home")){
        *uhome = 1; 
        *uview = 0; 
    }
    else if (!strcmp(args[0], "create")){ 
        printf("Input name of table: "); 
        char name[20];
        fgets(name, sizeof(name), stdin); 
        name[strlen(name) - 1] = '\0';
        printf("Input new dimensions (mxn): "); 
        char line[5]; 
        fgets(line, sizeof(line), stdin); 
        line[strlen(line) - 1] = '\0';
        char * dim[3]; 
        parse_args(line, "x", dim); 
        create_table(tbl_lst, name, *dim[0] -'0', *dim[1] -'0'); 
        *uhome = 1; 
        *uview = 0; 
    } 
    else if (!strcmp(args[0], "import")){
        printf("Provide the path to the csv you'd like to import: "); 
        char path[256]; 
        fgets(path, sizeof(path), stdin); 
        path[strlen(path) - 1] = '\0';
        printf("Name the new file: "); 
        char name[256]; 
        fgets(name, sizeof(name), stdin); 
        name[strlen(name) - 1] = '\0';
        read_csv(name, path);
        *uhome = 1; 
        *uview = 0;
    }

    else if (!strcmp(args[0], "view_list")){
        *uview = 1; 
        *uhome = 0;  
    }

    else if (!strcmp(args[0], "edit")){
        //ncurses(); 
        *uview = 1; 
        *uhome = 0; 
    }

    else if (!strcmp(args[0], "resize")){
        int table_num = *args[1] - '0'; 
        printf("Input new dimensions (mxn): "); 
        char line[5]; 
        fgets(line, sizeof(line), stdin); 
        line[strlen(line) - 1] = '\0';
        char * dim[3]; 
        parse_args(line, "x", dim); 
        resize(tbl_lst[table_num], *dim[0]-'0', *dim[1]-'0');
        *uview = 1; 
        *uhome = 0; 
    }

    else if (!strcmp(args[0], "delete")){
        printf("Before deletion, would you like to export this table? (Y/N)"); 
        char val[5];
        fgets(val, sizeof(val), stdin); 
        val[strlen(val) - 1] = '\0';
        delete_table(tbl_lst, *args[1]-'0', !strcmp(val, "Y"));
        *uview = 1; 
        *uhome = 0; 
    }

    else if (!strcmp(args[0], "export")){
        write_csv(tbl_lst[*args[1]-'0']);
        char export_menu[256]; 
        strcat(export_menu, "[view] view the exported csv file\n"); 
        strcat(export_menu, "[stat] stats of exported csv file\n"); 
        strcat(export_menu, "[exit] exit this menu if you would not like to use either menu item\n"); 
        char name[100]; 
        strcpy(name, tbl_lst[*args[1]-'0']->name);
        strcat(name, ".csv"); 
        char prompt[25]; 
        while (strcmp(prompt, "exit")){
            printf("%s", export_menu);
            fgets(prompt, sizeof(prompt), stdin);
            prompt[strlen(prompt) -1] = '\0';
            if (!strcmp(prompt, "view")){
                view_csv_file(name);
            }
            if (!strcmp(prompt, "stat")){
                view_csv_stats(name);
            }
        }
        *uview = 1; 
        *uhome = 0;
    }
    else{
        printf("Invalid input!"); 
    }
}