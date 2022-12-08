#include "task.h"

TASK createTask(int taskNUM) {
	TASK task;

	task.taskNUM = taskNUM;
	task.isThereATask = true;

	printf("\nEnter the name for the task you wish to add: ");
	fseek(stdin, 0, SEEK_END);
	fgets(task.taskName, MAXTASKNAMELENGTH, stdin);

	printf("\nPlease enter the name of the month in which this task takes place: ");
	if (scanf("%s", task.month)!=1) {
		printf("\nInvalid Input");
		exit(1);
	}

	printf("\nPlease enter the year in which the task takes place: ");
	if (scanf("%d", &task.year)!=1) {
		printf("\nInvalid Input");
		exit(1);
	}

	printf("\nPlease enter the number of the day on which the task takes place: ");
	if (scanf("%d", &task.day)!=1) {
		printf("\nInvalid Input");
		exit(1);
	}

	return task;
}

void taskDelete(TASK tdList[], int taskNUM) {
	tdList[taskNUM].isThereATask = false;				// When creating a task only checks if the bool is false or not
}														// So nothing else needs to be removed

TASK updateExistingTask(TASK tdList[]) {

}

bool isListFull(TASK tdList[]) {
	int counter = 0;
	bool isFull = false;

	for (int i = 0; i < MAXNUMOFTASKS; i++) {
		if (tdList[i].isThereATask == true) {
			counter++;
		}
	}

	if (counter == MAXNUMOFTASKS) {
		isFull = true;
	}

	return isFull;
}

void displayOneTask(TASK tdList[], int taskNUM) {
	if (tdList[taskNUM].isThereATask == true) {
		printf("\nYou have selected to display task %d", taskNUM);

		printf("\nTask Name: %s", tdList[taskNUM].taskName);
		printf("Date of task: %d %s %d", tdList[taskNUM].year, tdList[taskNUM].month, tdList[taskNUM].day);
	}
	else {
		printf("\nThere is no task in that slot.");
	}
}

void displayRangeOfTasks(TASK tdList[], int rangeStart, int rangeEnd) {
	for (int i = rangeStart; i <= rangeEnd; i++) {
		if (tdList[i].isThereATask == true) {
			printf("\nTask Number: %d", i);

			printf("\nTask Name: %s", tdList[i].taskName);
			printf("Date of task: %d %s %d", tdList[i].year, tdList[i].month, tdList[i].day);
		}
	}
}

void listOfAllTasks(TASK tdList[]) {
	for (int i = 0; i < MAXNUMOFTASKS; i++) {
		if (tdList[i].isThereATask == false) {}
		else {
			printf("\nTask Number: %d", i);

			printf("\nTask Name: %s", tdList[i].taskName);
			printf("Date of task: %d %s %d\n", tdList[i].year, tdList[i].month, tdList[i].day);
		}
	}
}

void searchForATAsk(TASK tdList[]) {
	char name[MAXTASKNAMELENGTH];
	bool isPresent = false;

	printf("\nEnter the name for the task you wish to find: ");
	fgets(name, MAXTASKNAMELENGTH, stdin);

	for (int i = 0; i < MAXNUMOFTASKS; i++) {
		if (strcmp(tdList[i].taskName, name) == 0) {
			printf("That task is on the list, its number is: %d", i);
			isPresent = true;
		}
	}
	if (isPresent == false) {
		printf("That task is not on the list");
	}
}