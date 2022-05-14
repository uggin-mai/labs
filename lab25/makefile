# makefile 1
CC = gcc
LD = gcc

CCFLAGS = -g -Wall -pedantic -std=c99

LDFLAGS =

main: main.o list.o
	cc -o main main.o list.o
main.o:	main.c list.h
	cc -c main.c
list.o: list.c list.h
	cc -c list.c
main.o: list.h
