[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Vh67aNdh)
# Spreadsheet

### Tong-foolery with gLee

Anastasia Lee, Janet Tong
       
### Project Description:

We're making a simple spreadsheet with features including basic cell editing, multiple tabs in a sheet, importing/exporting to csv files, and copy-and-paste functionality.

### Link to video
[LINK!!!]
  
### Instructions:

How does the user install/compile/run the program?

- Clone the repo
- `make compile`
- `make run`

How does the user interact with this program?

HOME MENU: 
Users will begin with a menu prompt. At the beginning of the program, the only available prompts are create and import. 
- create: prompts the user for the name and dimensions (max dimensions 10 x 10) of the table, creates the table, and adds it to your table list. 
- import: prompts the user for the path to the csv file and name, converts the csv file to a table, and adds it to your table list - note that the imported csv file must have max 10 characters per entry

After a table is created, a new prompt is available to the user, view list. View list displays all the user's tables with their names and dimensions.

VIEW LIST MENU: Users can choose a table and indicate whether they want to edit, resize, delete, or export the table. 
- edit: sends user to new window where they can edit the table in a spreadsheet-like display
  - users can use the arrow keys to move their cursor to adjacent cells (if possible)
  - users can type into the cell to input information — max 10 characters per cell
  - the esc key exits the editing window
  - ctrl+c copies information from the cell the user is currently on
  - ctrl+f pastes the copied information to the cell the user is currently on
- resize: prompts user for new dimensions to resize table to 
  - max dimensions are 10 x 10
  - if user inputs dimensions smaller than the current dimensions, the table will truncate cell information from outer columns and rows 
- delete: deletes specified table, asks user if they would like to export the table before deleting it 
- export: exports table contents to a csv file
  - view: allows the user to view the csv file 
  - stat: displays file stats (size, user id, group id, permissions)

Users can use ctrl+\ outside of the editing mode to exit the entire spreadsheet program. 

OVERALL RESTRICTIONS: 
- max table dimensions are 10 x 10 
- max 10 characters per cell 
- max 20 tables in table list 

POSIBBLE BUGS: 
