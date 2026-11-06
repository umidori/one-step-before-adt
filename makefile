all: get_line

clean:
	rm -f get_line main.o line.o

get_line: main.o line.o
	cc -o get_line main.o line.o

main.o: main.c line.h
	cc -c main.c

line.o: line.c line.h
	cc -c line.c
