compile sheets: main.o cell.o tab.o csv.o
	@gcc -o sheets main.o cell.o tab.o csv.o
main.o: main.c headers.h
	@gcc -c main.c
cell.o: cell.c headers.h
	@gcc -c cell.c
csv.o: csv.c headers.h
	@gcc -c csv.c
tab.o: tab.c headers.h
	@gcc -c tab.c
run: sheets
	@./sheets
clean:
	rm *o
	rm sheets
