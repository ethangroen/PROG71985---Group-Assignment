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

bool SavetdListToDisk(TASK tdList[], char* filename)				// Author: Jordan
{
	FILE* file;
	fopen_s(&file, filename, "w");
	if (file == NULL) {
		printf("Error Writing");
		return false;
	}
	char buffer_in[MAXFILESIZE], buffer_out[MAXFILESIZE];
	for (int i = 0; i < MAXNUMOFTASKS; i++) {
		if (tdList[i].isThereATask == true) {
			fprintf(file, "%d %d %s %s\n", tdList[i].year, tdList[i].day, tdList[i].month, tdList[i].taskName);
		}
	}
	if (file == NULL) {

	}
	else
		fclose(file);
	return true;
}

bool LoadtdListFromDisk(TASK tdList[], char* filename)				// Author: Jordan
{
	FILE* file;
	if ((file = fopen(filename, "r")) != NULL)
	{
		// file exists

		char buffer[MAXFILESIZE];
		char bufferTwo[MAXFILESIZE];

		for (int i = 0; i < MAXNUMOFTASKS; i++) {			

			if (fgets(buffer, MAXFILESIZE, file) == NULL)			
			{
				fclose(file);
			}
			int result;
			result = strcmp(bufferTwo, buffer);
			if (result != 0) {
				sscanf(buffer, "%d %d %s %[^\n]%*c", &tdList[i].year, &tdList[i].day, &tdList[i].month, &tdList[i].taskName);
				tdList[i].isThereATask = true;
			}
			else
				tdList[i].isThereATask = false;

			strncpy(bufferTwo, buffer, MAXFILESIZE);
		}

		fclose(file);
		return true;
	}
	else
	{
		//File not found, no memory leak since 'file' == NULL
		//fclose(file) would cause an error
		for (int i = 0; i < MAXNUMOFTASKS; i++) {			// Jordan this will need to be part of the loading I just need it
			tdList[i].isThereATask = false;
		}
		return false;
	}
}
