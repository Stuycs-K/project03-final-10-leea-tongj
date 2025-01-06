#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cell/table edits
void update_cell(int row, int col, char * input);
char * clear_cell(int row, int col);
void add_row();
void add_column();

// tab creation + display
void create_tab(char* name, int rows, int cols);
void display_tab();
void tab_list();
void access_tab(char* name);
void delete_tab(char* name); 