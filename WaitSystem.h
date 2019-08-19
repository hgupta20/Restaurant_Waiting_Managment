// header file to connect three .c source files which are main.c linkedListImp.c linkedListFunctions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {waiting = 0, sitting = 1} empty;
typedef enum {FALSE = 0, TRUE, NO = 0, YES} boolean;

typedef struct node{
	char *name;
	int groupSize;
	empty status;
	struct node *next;
} waitinglist;

// Functions in all the three source files

void doAdd(waitinglist **phead, int debugMode);
void doCallAhead(waitinglist **phead, int debugMode);
void doWaiting(waitinglist **phead, int debugMode);
void doRetrieve(waitinglist **phead, int debugMode);
void doList(waitinglist **phead, int debugMode);
void doDisplay(waitinglist **phead);
void addToList(waitinglist **phead, char *name, int size, empty status);
int doesNameExist(waitinglist **phead, char *name);
boolean updateStatus(waitinglist **phead, char *name, int debugMode);
void retrieveAndRemove(waitinglist **phead, int tablesize, int debugMode);
int countGroupsAhead(waitinglist **phead, char *name, int debugMode);
void displayGroupSizeAhead(waitinglist **phead, int ahead);
void displayListInformation(waitinglist **phead);
void clearToEoln();
int getNextNWSChar();
int getPosInt();
char *getName();
void printCommands();
