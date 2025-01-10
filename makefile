compile: main.o cell.o tab.o 
	@gcc -o spread main.o cell.o tab.o
main.o: main.c headers.h
	@gcc -c main.c
cell.o: cell.c headers.h
	@gcc -c cell.c
tab.o: tab.c headers.h
	@gcc -c tab.c
run: spread
	@./spread
clean:
	rm *o
	rm structrw