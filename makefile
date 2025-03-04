compile sheets: main.o cell.o tab.o csv.o ncurses.o user.o user.o
	@gcc -o sheets main.o cell.o tab.o csv.o ncurses.o user.o -lncurses
main.o: main.c headers.h
	@gcc -c main.c
cell.o: cell.c headers.h
	@gcc -c cell.c
csv.o: csv.c headers.h
	@gcc -c csv.c
tab.o: tab.c headers.h
	@gcc -c tab.c
ncurses.o: ncurses.c headers.h
	@gcc -c ncurses.c
user.o: user.c headers.h
	@gcc -c user.c
run: sheets
	@./sheets
clean:
	rm *o
	rm sheets
