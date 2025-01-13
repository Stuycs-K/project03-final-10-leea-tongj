# Final Project Proposal

## Group Members:

Anastasia Lee, Janet Tong
       
# Intentions:

We're making a simple spreadsheet with features including basic cell editing, multiple tabs in a sheet, and copy-and-paste functions.
    
# Intended Usage:

- Users can create new tables by adding a tab to the spreadsheet
- Users can view a list of all their tables, with the title and dimensions
- Users can then choose a table and indicate whether they want to access or delete that table
- Within a table, users can add rows/columns or select a cell and:
  - Insert/edit info (type value)
  - Copy info (`ctrl-C`)
  - Paste info (`ctrl-Z`)
- Users can convert a csv file to a table by providing the path to the csv file
- Users can use the arrow keys to move their cursor to adjacent cells (if possible)
- Users can use `ctrl-\` to exit the program

  
# Technical Details:

## Topics Used
1. Allocating Memory: store and edit cell information 
2. Working with files: convert csv files given their path (using dirent()) to a new table in a new file, reading and writing to tables
3. Finding information about files: use stat() to view a list of all the tables (files) and their respective number of rows and columns; prompt the user and ask which table they want to access/delete. 
4. Signals: intercept SIGINT (`ctrl-C`) to copy info, SIGSTP (`ctrl-Z`) to paste info, SIGQUIT (`ctrl-\`) to exit the program

## Division of Tasks
Anastasia: 
- Convert csv to table 
- List of tables, selecting a specific table to access/remove it
- Signals
- Moving cursor with arrow keys
- Record video

Janet: 
- Inserting + editing cells
- Tabs with different files/spreadsheets
- Adding rows/columns
- Moving cursor with arrow keys
- Record video

## Algorithms and Data Structures
We will be using arrays to store the data in each table.
    
# Intended pacing:

Jan 8: Inserting + editing cells + Convert csv to table
Jan 11: Tabs with different files/spreadsheets
Jan 13: List of tables, selecting a specific table to access/remove it 
Jan 15: Signals + Adding rows/columns (Basic working version) 
Jan 18: Moving cursor with arrow keys 
Jan 18: Record video
