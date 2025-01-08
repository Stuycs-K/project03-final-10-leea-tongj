compile sheets: main.o csv.o
	@gcc -o sheets main.o csv.o
run: sheets
	@./sheets
main.o: main.c headers.h
	@gcc -c main.c
csv.o: csv.c headers.h
	@gcc -c csv.c
clean:
	rm *.o
	rm sheets
