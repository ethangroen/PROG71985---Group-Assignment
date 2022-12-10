// Group Assignment - To Do / Task List
// For this project we were tasked with creating a to do list
// The list needs to have the options to add, remove, edit and view the tasks
// The program also needs to save data between instances and load data from previous sessions if there is any

// Task Functions File
// PROG71985 - 22F
// Ethan Groen, Jordan Sinclair - December 2022

// revision history
// 1.0			2022-December-04			initial

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

TASK updateExistingTask(TASK tdList[], int taskNUM) {					// Author: Jordan
	TASK task;
	task.taskNUM = taskNUM;
	task.isThereATask = true;
	char whatToUpdate;

	printf("\nWhich part would you like to update\n\n");

	printf("a) The name of the task\nb) The month of the task\nc) The year of the task\nd) The day of the task\ne) All\n");

	fseek(stdin, 0, SEEK_END);
	if (scanf("%c", &whatToUpdate) != 1) {
		printf("\nInvalid Input");
		exit(1);
	}

	switch (whatToUpdate)
	{
	case 'a':
		printf("\nWhat would you like to rename the task to?\n"); 
		fgets(task.taskName, MAXTASKNAMELENGTH, stdin);
		break;
	case 'b':
		printf("\nWhat would you like to change the new month to?\n");
		if (scanf("%s", &tdList[taskNUM].month) != 1) {
			printf("\nInvalid Input");
			exit(1);
		}
		break;
	case 'c':
		printf("\nWhat would you like to change the new year to?\n");
		if (scanf("%d", &tdList[taskNUM].year) != 1) {
			printf("\nInvalid Input");
			exit(1);
		}
		break;
	case 'd':
		printf("\nWhat would you like to change the new day to?\n");
		if (scanf("%d", &tdList[taskNUM].day) != 1) {
			printf("\nInvalid Input");
			exit(1);
		}
		
		break;
	case 'e':
		printf("\nWhat would you like to rename the task to?\n");
		if (scanf("%s", &tdList[taskNUM].taskName) != 1) {
			printf("\nInvalid Input");
			exit(1);
		}
		printf("\nWhat would you like to change the new month to?\n");
		if (scanf("%s", &tdList[taskNUM].month) != 1) {
			printf("\nInvalid Input");
			exit(1);
		}
		printf("\nWhat would you like to change the new year to?\n");
		if (scanf("%d", &tdList[taskNUM].year) != 1) {
			printf("\nInvalid Input");
			exit(1);
		}
		printf("\nWhat would you like to change the new day to?\n");
		if (scanf("%d", &tdList[taskNUM].day) != 1) {
			printf("\nInvalid Input");
			exit(1);
		}
		break;


	}

}

bool isListFull(TASK tdList[]) {						// Author: Ethan & Jordan
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

void displayOneTask(TASK tdList[], int taskNUM) {					// Author: Ethan
	if (tdList[taskNUM].isThereATask == true) {
		printf("\nYou have selected to display task %d", taskNUM);

		printf("\nTask Name: %s\n", tdList[taskNUM].taskName);
		printf("Date of task: %d %s %d", tdList[taskNUM].year, tdList[taskNUM].month, tdList[taskNUM].day);
	}
	else {
		printf("\nThere is no task in that slot.");
	}
}

void displayRangeOfTasks(TASK tdList[], int rangeStart, int rangeEnd) {			// Author: Ethan
	for (int i = rangeStart; i <= rangeEnd; i++) {
		if (tdList[i].isThereATask == true) {
			printf("\nTask Number: %d", i);

			printf("\nTask Name: %s", tdList[i].taskName);
			printf("Date of task: %d %s %d", tdList[i].year, tdList[i].month, tdList[i].day);
		}
	}
}

void listOfAllTasks(TASK tdList[]) {							// Author: Ethan
	for (int i = 0; i < MAXNUMOFTASKS; i++) {
		if (tdList[i].isThereATask == false) {}
		else {
			printf("\nTask Number: %d", i);

			printf("\nTask Name: %s\n", tdList[i].taskName);
			printf("Date of task: %d %s %d\n", tdList[i].year, tdList[i].month, tdList[i].day);
		}
	}
}

void searchForATAsk(TASK tdList[]) {							// Author: Jordan
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