all: main.o linkedListFunc.o linkedList.o
	gcc main.o linkedListFunc.o linkedList.o -o all

main.o: main.c WaitSystem.h
	gcc -c main.c

linkedListFunc.o: linkedListFunc.c WaitSystem.h
	gcc -c linkedListFunc.c

linkedList.o: linkedList.c WaitSystem.h
	gcc -c linkedList.c
