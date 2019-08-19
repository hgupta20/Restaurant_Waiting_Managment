//The second half of the project base, functions which use linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WaitSystem.h"

extern debugMode;

void doAdd(waitinglist **phead, int debugMode){
	/* get group size from input */
	int size = getPosInt();
	if(size < 1){
		printf("Error: Add command requires an integer value of at least 1\n");
		printf("Add command is of form: a <size> <name>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		printf("         <name> is the name of the group making the reservation\n");
		return;
	}

	/* get group name from input */
	char *name = getName();
	if(NULL == name){
		printf("Error: Add command requires a name to be given\n");
		printf("Add command is of form: a <size> <name>\n");
		printf("  where: <size> is the size of the group making the reservation\n");
		printf("         <name> is the name of the group making the reservation\n");
		return;
	}
	// add code to perform this operation here

	//check waiting list if the name is already there
	if(doesNameExist(phead, name) == FALSE){
		if(debugMode == TRUE){
			printf("Adding the group to the list\n");
			displayListInformation(phead);
		}
		printf("Adding the group \"%s\" of size %d\n", name, size);
		addToList(phead, name, size, waiting);
		return;
	}
	else{
		printf("Name already in the wait list\n");
		return;
	}
}

void doCallAhead(waitinglist **phead, int debugMode){
	/* get group size from input */
	int size = getPosInt();
	if(size < 1){
		printf ("Error: Call-ahead command requires an integer value of at least 1\n");
		printf ("Call-ahead command is of form: c <size> <name>\n");
		printf ("  where: <size> is the size of the group making the reservation\n");
		printf ("         <name> is the name of the group making the reservation\n");
		return;
	}

	/* get group name from input */
	char *name = getName();
	if (NULL == name){
		printf ("Error: Call-ahead command requires a name to be given\n");
		printf ("Call-ahead command is of form: c <size> <name>\n");
		printf ("  where: <size> is the size of the group making the reservation\n");
		printf ("         <name> is the name of the group making the reservation\n");
		return;
	}

	// add code to perform this operation here

	if(doesNameExist(phead, name)== FALSE){
		if(debugMode == TRUE){
			displayListInformation(phead);
		}
		printf ("Call-ahead group \"%s\" of size %d\n", name, size);
		addToList(phead, name, size, sitting);
		return;
	}
	else{
		printf("Name already in the wait list\n");
		return;
	}
}

void doWaiting(waitinglist **phead, int debugMode){
	/* get group name from input */
	char *name = getName();
	if (NULL == name){
		printf ("Error: Waiting command requires a name to be given\n");
		printf ("Waiting command is of form: w <name>\n");
		printf ("  where: <name> is the name of the group that is now waiting\n");
		return;
	}

	printf ("Waiting group \"%s\" is now in the restaurant\n", name);

	// add code to perform this operation here
	if(doesNameExist(phead, name)== FALSE){
		if(debugMode == TRUE){
			displayListInformation(phead);
		}
		printf("Name does not exist wait list\n");
		return;
	}
	if(updateStatus(phead, name, debugMode) == FALSE){
		return;
	}
	else{
		updateStatus(phead, name, debugMode);
		return;
	}

}

void doRetrieve(waitinglist **phead, int debugMode){
	/* get table size from input */
	int size = getPosInt();
	if (size < 1){
		printf ("Error: Retrieve command requires an integer value of at least 1\n");
		printf ("Retrieve command is of form: r <size>\n");
		printf ("  where: <size> is the size of the group making the reservation\n");
		return;
	}
	clearToEoln();
	printf ("Retrieve (and remove) the first group that can fit at a tabel of size %d\n", size);

	// add code to perform this operation here
	retrieveAndRemove(phead, size, debugMode);
	return;

}

void doList(waitinglist **phead, int debugMode){
	/* get group name from input */
	char *name = getName();
	if (NULL == name){
		printf ("Error: List command requires a name to be given\n");
		printf ("List command is of form: l <name>\n");
		printf ("  where: <name> is the name of the group to inquire about\n");
		return;
	}

	// add code to perform this operation here
	if(doesNameExist(phead, name)){
		int counter=countGroupsAhead(phead, name, debugMode);
		printf("Number of groups ahead of \"%s\": %d\n", name, counter);

		printf ("Group \"%s\" is behind the following groups\n", name);
		//count size of group
		int count=countGroupsAhead(phead, name, debugMode);
		displayGroupSizeAhead(phead, count);
		return;
	}
	else{
		printf("Name does not exist in list\n");
		return;
	}


}

void doDisplay(waitinglist **phead){
	clearToEoln();
	printf ("Display information about all groups\n");

	// add code to perform this operation here
	displayListInformation(phead);
}
