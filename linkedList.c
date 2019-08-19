/* This source file has all the linked list functions and would add people remove
and do all other required tasks in the queue*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WaitSystem.h"

extern debugMode;

// add a new node in the list
void addToList(waitinglist **phead, char *name, int size, empty status){
	//create new node and set the values to default
	waitinglist *listW = (waitinglist *) malloc(sizeof(waitinglist));
	listW->name = name;
	listW->groupSize = size;
	if(status == sitting)
		listW->status = sitting;
	else
		listW->status = waiting;
	listW->next = NULL;

	//if list is empty
	if(*phead == NULL){
		*phead = listW; //set the new node as the head
		return;
	}
	else{
		waitinglist *temp = *phead; // make a temp list
		while(temp->next != NULL) temp = temp->next; // loop till you reach the end of the list
		temp->next = listW; //back as new node
		return;
	}
	return;
}
// check name if exists return a boolean value true for 1 and 0 for false
int doesNameExist(waitinglist **phead, char *name){
	waitinglist *temp = *phead;
	//if list is empty
	if(temp == NULL)
		return 0;
	//loop until reach end of list
	while(temp != NULL){
		if(strcmp(temp->name, name) == 0)
			return 1;
		else{
				temp = temp->next;
			}
	}
	return 0;
}

// to update status of a group of customers
boolean updateStatus(waitinglist **phead, char *name, int debugMode){
	waitinglist *temp = *phead;
	if(temp == NULL){
		printf("\nList is Empty: Nothing to Update\n");
		return FALSE;
	}
	if(debugMode == TRUE)
		printf("Debug Mode\n\tName\tSize\tStatus\n");

	//loop until end of the list
	int num=1;
	while(temp != NULL){
	if(strcmp(temp->name, name) == 0){
			if(temp->status == waiting){
				if(debugMode == TRUE){
					printf("%d\t%s\t%d\t", num, temp->name, temp->groupSize);
          printf("Still Waiting\n");
					num++;
				}
				return FALSE;
			}
			else{
				if(debugMode == TRUE){
					printf("%d\t%s\t%d\t", num, temp->name, temp->groupSize);
					printf("Not Waiting\n");
					num++;
				}
				temp->status = waiting;
				return TRUE;
			}
		}
		temp = temp->next;
	}
	return FALSE;
}

// Retrieve data of the customer and Remove
void retrieveAndRemove(waitinglist **phead, int tablesize, int debugMode){
	waitinglist *temp = *phead;
	waitinglist *temp1;
	//list is empty
	if(temp == NULL){
		printf("\nList is empty\n");
		return;
	}

	//check front
	if(temp->groupSize <= tablesize && temp->status == 0){
		*phead = (*phead)->next;
		free(temp);
		if(debugMode == TRUE){
			displayListInformation(phead);
		}
		return;
	}


	if(debugMode == TRUE)
		printf("Debug Mode- Information\n\tName\tSize\tStatus\n");
	int num = 1;
	while(temp->next != NULL){
		if(debugMode == TRUE){
			char *available;
			if(temp->status == waiting)
				available = "Still Waiting";
			else
				available = "Not Waiting";
			printf("%d\t%s\t%d\t%s\n", num, temp->name, temp->groupSize, available);
			num++;
		}
		if(temp->next->groupSize <= tablesize){
			if(temp->next->status == 0){
				temp1 = temp->next;
				temp->next = temp1->next;

				free(temp1);
				return;
			}
		}
		temp = temp->next;
	}
	printf("No valid group size for the table size\n");
	return;
}

// To count number of group waiting
int countGroupsAhead(waitinglist **phead, char *name, int debugMode){
	waitinglist *temp = *phead;
	if(temp == NULL)
		return 0;
	int result = 0, num = 1;
	if(debugMode == TRUE)
		printf("Debug Mode- Information\n\tName\tSize\tStatus\n");
	while(temp != NULL){
		if(debugMode == TRUE){
			char *available;
			if(temp->status == waiting)
				available = "Still Waiting";
			else
				available = "Not Waiting";
			printf("%d\t%s\t%d\t%s\n", num, temp->name, temp->groupSize, available);
			num++;
		}
		if(strcmp(temp->name, name) == 0){
			return result;
		}
		result++;
		temp = temp->next;
	}
	return 0;
}

// Print all the group size
void displayGroupSizeAhead(waitinglist **phead, int ahead){
	waitinglist *temp = *phead;
	int counter = 0;
	int num = 1;

	if(temp == NULL){
		printf("\nList is empty\n");
		return;
	}
	if(counter == ahead){
		printf("\nFirst on the list\n");
		return;
	}
	printf("\tName\tSize\tStatus\n");
	while(counter != ahead && temp != NULL){
		char *available;
		if(temp->status == waiting)
			available = "Still Waiting";
		else
			available = "Not Waiting";
		printf("%d\t%s\t%d\t%s\n", num, temp->name, temp->groupSize, available);
		num++;
		temp = temp->next;
		counter++;
	}
	return;
}

//print out the groups name, size, and status
void displayListInformation(waitinglist **phead){
	waitinglist *temp = *phead;
	int num = 1;
	if(temp == NULL){
		printf("\nList is empty\n");
		return;
	}
	printf("\n\tName\tSize\tStatus\n");
	while(temp != NULL){
		char *available;
		if(temp->status == waiting)
			available = "Still Waiting";
		else
			available = "Not Waiting";
		printf("%d\t%s\t%d\t%s\n", num, temp->name, temp->groupSize, available);
		num++;
		temp = temp->next;
	}
	return;
}
