// Group Assignment - To Do / Task List
// For this project we were tasked with creating a to do list
// The list needs to have the options to add, remove, edit and view the tasks
// The program also needs to save data between instances and load data from previous sessions if there is any

// Main File
// PROG71985 - 22F
// Ethan Groen, Jordan Sinclair - December 2022

// revision history
// 1.0			2022-December-04			initial
#include "task.h"


int main(int argc, char* argv[]) {

	TASK tdList[MAXNUMOFTASKS];

	
	FILE* file;
	if ((file = fopen("Tasks.txt", "r")) != NULL)
	{
		// file exists
		printf("File found");

		char buffer[256];
		char bufferTwo[256];

		for (int i = 0; i < MAXNUMOFTASKS; i++) {			// Jordan this will need to be part of the loading I just need it
			
	
			if (fgets(buffer, 256, file) == NULL)			// in order to make my stuff for now
			{
				fclose(file);
			}
			int result;
			result = strcmp(bufferTwo, buffer);
			if (result != 0) {
				sscanf(buffer, "%d %d %s %s", &tdList[i].year, &tdList[i].day, &tdList[i].month, &tdList[i].taskName);
				tdList[i].isThereATask = true;
			}
			else
				tdList[i].isThereATask = false;

			strncpy(bufferTwo, buffer, 256);
		}

		fclose(file);
	}
	else
	{
		//File not found, no memory leak since 'file' == NULL
		//fclose(file) would cause an error
		for (int i = 0; i < MAXNUMOFTASKS; i++) {			// Jordan this will need to be part of the loading I just need it
			tdList[i].isThereATask = false;
		}
		printf("File not found");
	}
	


	char menuChoice;
	int taskNum;
	int rangeStart, rangeEnd;

	do {
		printf("\nTo choose a function, enter its letter label:\na) Add a new task to list\nb) Delete an existing task from list");
		printf("\nc) Update an existing task\nd) Display one task\ne) Display a range of tasks\nf) Display all existing tasks");
		printf("\ng) Search for an existing task\nz) Quit\n");
		
		fseek(stdin, 0, SEEK_END);
		if (scanf("%c", &menuChoice)!=1) {
			printf("\nInvalid Input");
			exit(1);
		}

		switch (menuChoice) {
		case 'a':					// Add new task	
			if (isListFull(tdList) == true) {
				printf("\nThe task list is full, there is no spcae for any additonal tasks.");
				break;
			}
			else {
				for (int i = 0; i < MAXNUMOFTASKS; i++) {
					if (tdList[i].isThereATask == false) {
						tdList[i] = createTask(i);
						i = MAXNUMOFTASKS;
					}
				}
			}
			break;
		case 'b':					// Delete existing task		
			taskNum = 0;
			printf("\nEnter the number of the task that you want to delete: ");
			if (scanf("%d", &taskNum)!=1) {
				printf("\nInvalid Input");
				exit(1);
			}
			taskDelete(tdList, taskNum);
			break;
		case 'c':					// Update an existing task	
			taskNum = 0;
			printf("\nWhich task would you like to update? (Task 1 = 0):");

			if (scanf("%d", &taskNum) != 1) {
				printf("\nInvalid Input");
				exit(1);
			}
			updateExistingTask(tdList, taskNum);

			break;
		case 'd':					// Display one task		
			taskNum = 0;
			printf("\nEnter the number of the task that you want to display (Task 1 = 0): ");
			if (scanf("%d", &taskNum) != 1) {
				printf("\nInvalid Input");
				exit(1);
			}
			displayOneTask(tdList, taskNum);
			break;
		case 'e':					// Display a range of tasks		
			rangeStart = 0;
			rangeEnd = 0;
			printf("\nEnter the number where you want the range to start (Task 1 = 0): ");
			if (scanf("%d", &rangeStart) != 1) {
				printf("\nInvalid Input");
				exit(1);
			}
			printf("\nEnter the number where you want the list to end (Last Task Slot = 19): ");
			if (scanf("%d", &rangeEnd) != 1) {
				printf("\nInvalid Input");
				exit(1);
			}
			displayRangeOfTasks(tdList, rangeStart, rangeEnd);
			break;
		case 'f':					// Display all existing tasks	
			listOfAllTasks(tdList);
			break;
		case 'g':					// Search for an existing task	
			searchForATAsk(tdList);
			break;
		case 'z':					// Quit

			fopen_s(&file, "Tasks.txt", "w");
			if (file == NULL) {
				printf("Error Writing");
			}
			char buffer_in[256], buffer_out[256];
			for (int i = 0; i < MAXNUMOFTASKS; i++) {			
				if (tdList[i].isThereATask == true) {
					fprintf(file,"%d %d %s %s\n", tdList[i].year, tdList[i].day, tdList[i].month, tdList[i].taskName);
				}
			}
			if (file == NULL) {

			}
			else
				fclose(file);
		
			break;
		case '\n':
			break;
		default:
			printf("\nInvalid input");
			exit(1);
		}
	} while (menuChoice != 'z');

	return 0;
}