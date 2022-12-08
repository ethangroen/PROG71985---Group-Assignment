// Group Assignment - To Do / Task List
// For this project we were tasked with creating a to do list
// The list needs to have the options to add, remove, edit and view the tasks
// The program also needs to save data between instances and load data from previous sessions if there is any

// loadAndSave Functions File
// PROG71985 - 22F
// Ethan Groen, Jordan Sinclair - December 2022

// revision history
// 1.0			2022-December-04			initial

#include "loadAndSave.h"

bool SavetdListToDisk(TASK tdList[], char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "w")) == NULL)
		return false;

	for (int i = 0; i < MAXNUMOFTASKS; i++)
	{
		SaveTaskToStream(tdList[i], fp);
	}

	fclose(fp);
	return true;
}

void SaveTaskToStream(TASK task, FILE* fp)
{
	fprintf(fp, "%d\n", task.taskNUM);
	fprintf(fp, "%d\n", task.year);
	fprintf(fp, "%s\n", task.month);
	fprintf(fp, "%d\n", task.day);
	fprintf(fp, "%s\n", task.taskName);
}

bool LoadtdListFromDisk(TASK tdList[], char* filename)
{
	FILE* fp;
	if ((fp = fopen(filename, "r")) == NULL)
		return false;

	char taskNUM[MAXTASKNAMELENGTH];
	char year[MAXTASKNAMELENGTH];
	char month[MAXTASKNAMELENGTH];
	char day[MAXTASKNAMELENGTH];
	char taskname[MAXTASKNAMELENGTH];


	for (int i = 0; i < MAXNUMOFTASKS; i++) {
		fgets(taskNUM,MAXTASKNAMELENGTH , fp);
		fgets(year, MAXTASKNAMELENGTH, fp);
		fgets(month, MAXTASKNAMELENGTH, fp);
		fgets(day, MAXTASKNAMELENGTH, fp);
		fgets(taskname, MAXTASKNAMELENGTH, fp);

		removeNfromChar(month);
		removeNfromChar(taskname);

		int counter = atoi(taskNUM);

		tdList[counter].isThereATask = true;
		tdList[counter].taskNUM = taskNUM;
		tdList[counter].year = atoi(year);
		strncpy(tdList[counter].month, month, MAXTASKNAMELENGTH);
		tdList[counter].day = atoi(day);
		strncpy(tdList[counter].taskName, taskname, MAXTASKNAMELENGTH);
	}

	fclose(fp);
	return true;
}

void removeNfromChar(char* userInput) {
	for (int i = 0; i < strlen(userInput); i++) {
		if (userInput[i] == '\n') {
			userInput[i] = '\0';
		}
	}
}