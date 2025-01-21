[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Vh67aNdh)
# Spreadsheet

## Tong-foolery with gLee

Anastasia Lee, Janet Tong
       
## Project Description:

We're making a simple spreadsheet with features including basic cell editing, multiple tabs in a sheet, importing/exporting to csv files, and copy-and-paste functionality.

## Link to video
[LINK!!!]
  
## Instructions:

### How does the user install/compile/run the program?

- Clone the repo
- `make compile`
- `make run`

### How does the user interact with this program?

<ins>HOME MENU:</ins>
Users will begin with a menu prompt. At the beginning of the program, the only available prompts are create and import. 
- create: prompts the user for the name and dimensions (max dimensions 10 x 10, min dimensions 1 x 1) of the table, creates the table, and adds it to your table list. 
- import: prompts the user for the path to the csv file and name, converts the csv file to a table, and adds it to your table list - note that the imported csv file must have max 10 characters per entry and have max dimensions 10 x 10

After a table is created, a new prompt is available to the user, view list. View list displays all the user's tables with their names and dimensions.

<ins>VIEW LIST MENU:</ins> Users can choose a table (identified by its index in the list) and indicate whether they want to access, resize, delete, or export that table. 
- access: sends user to new window where they can view/edit the table in a spreadsheet-like display
  - users can use the arrow keys to move their cursor to adjacent cells (if possible)
  - users can type into the cell to input information — max 10 characters per cell
  - the backspace key works as expected while you are typing in a cell
  - if you type in a cell, move away and then come back, typing again will clear the previous contents, replacing it with whatever you are currently typing (like Google Sheets)
  - ctrl+c copies information from the cell the user is currently on
  - ctrl+f pastes the copied information to the cell the user is currently on
  - the esc key exits the window
- resize: prompts user for new dimensions to resize table to 
  - max dimensions are 10 x 10, min dimensions are 1 x 1
  - if user inputs dimensions smaller than the current dimensions, the table will truncate cell information from outer columns and rows 
- delete: deletes specified table, asks user if they would like to export the table before deleting it 
- export: exports table contents to a csv file
  - view: allows the user to view the csv file 
  - stat: displays file stats (size, user id, group id, permissions)

<ins>Use ctrl+\ to exit the program! This should always work, whether you're in the viewing/editing window or not.</ins>

### Libraries
- In addition to standard libraries, we used ncurses. It does not need to be installed.

### OVERALL RESTRICTIONS: 
- max table dimensions are 10 x 10, min table dimensions are 1 x 1
- max 10 characters per cell 
- max 20 tables in table list 

POSSIBLE BUGS: none that we know of
