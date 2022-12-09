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
#include "loadAndSave.h"


int main(int argc, char* argv[]) {

	TASK tdList[MAXNUMOFTASKS];

	for (int i = 0; i < MAXNUMOFTASKS; i++) {
		tdList[i].isThereATask = false;
	}

	if (LoadtdListFromDisk(tdList, "Tasks.txt") == false) {
		printf("There was no data to load\n");
	}
	else {
		printf("Data was loaded from previous session\n");
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
			break;
		case '\n':
			break;
		default:
			printf("\nInvalid input");
			exit(1);
		}
	} while (menuChoice != 'z');

	if (SavetdListToDisk(tdList, "Tasks.txt") == false) {
		printf("Save was unsuccessful");
	}

	return 0;
}