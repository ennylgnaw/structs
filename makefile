all: work06.o
	gcc -o test work06.o

work06.o: work06.c
	gcc -c work06.c

run:
	./test