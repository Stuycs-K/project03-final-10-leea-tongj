# Dev Log:

This document must be updated daily by EACH group member.

## Anastasia Lee

### 2025-01-06 - Getting the repo started
- Added formatted proposal to PROPOSAL.md (20 minutes)
- Filled in README.md (10 minutes)
- Created git branch (1 minute)
- Added skeleton files (7 minutes)

### 2025-01-07 - Planning + starting csv.c
- Discussed creating structs for tables and cells (10 minutes)
- Discussed maximum number of columns for tables and maximum character length for entries (7 minutes)
- Discussed only exporting the spreadsheet to a file if the user asks for it (10 minutes)
- Started writing read_csv method to convert csv (10 minutes)

### 2025-01-08 - Work on csv.c
- Finished read_csv method (30 minutes)

### 2025-01-08 to 2024-01-12 - Excused absences due to travel

### 2025-01-13 - Progress on write_csv and signal.c
- Did some research for and started working on signal.c (20 minutes)
- Realized that windows.h doesn't work so brainstormed new plan for use of signals (10 minutes)
- Moved and modified write_csv (10 minutes)
- Updated tab.c based on changes (10 minutes)
- Tested and fixed write_csv (20 minutes)

### 2025-01-14 - 
- Discussed how deletion of tables should work (10 minutes)
- Improved formatting of display_table (10 minutes)
- Created global variables (5 minutes)
- Implemented clipboard for copying/pasting from/to cells (10 minutes)

## Janet Tong

### 2025-01-06 - Skeleton Files + Function Design
- Created git branch (1 minute) 
- Added cell.c and tab.c files (3 minutes)
- Designed functions and documentation comments for cell.c and tab.c (20 minutes)
- Updated header file (5 minutes)

### 2025-01-07 - Planning + create_table & udpate_cell
- Discussed using structs for table list and cells (10 minutes)
- Discussed maximum columns for tables (7 minutes) 
- Discussed using files with a new method "export" when prompted instead (10 minutes) 
- Began create_table(5 minutes)

### 2025-01-09 - Completed create_table, display_table, update_cell, and clear_cell
- Wrote create_table (15 minutes)
- Wrote display_table (5 minutes)
- Began update_cell and clear_cell (15 minutes)
- Modified create_table, update_call, and clear_cell to use struct cell (20 minutes)
- Wrote makefile (5 minutes)
- Tested completed methods in main (10 minutes) 
- Wrote export_file (10 minutes) 
- Began read_file (7 minutes)

### 2025-01-10 - Began table list functions 
- Wrote init_table_list (15 minutes)
- Wrote display_table_list(5 minutes) 
- Began writing add_table (10 minutes)
- Testing and debugging in main (7 minutes) 

### 2025-01-13 - Debugging table list functions 
- Wrote select_cell (5 minutes)
- Debugging init_table_list and add_list (20 minutes) 
- Began writing delete_table(15 minutes) 

### 2025-01-14 - Delete_table, add_row, add_column
- Considered using linked list + removed (5 minutes)
- Discussed how deletion of tables should work (10 minutes)
- Discussed and wrote add_row and add_column (15 minutes)
- Wrote delete_table (20 minutes)