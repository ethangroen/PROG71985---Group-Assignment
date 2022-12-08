// Group Assignment - To Do / Task List
// For this project we were tasked with creating a to do list
// The list needs to have the options to add, remove, edit and view the tasks
// The program also needs to save data between instances and load data from previous sessions if there is any

// Task Header File
// PROG71985 - 22F
// Ethan Groen, Jordan Sinclair - December 2022

// revision history
// 1.0			2022-December-04			initial

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define MAXTASKNAMELENGTH 50
#define MAXMONTHNAME 10
#define MAXNUMOFTASKS 20

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct date {
	char month[MAXMONTHNAME];
	int year;
	int day;
}DATE;

typedef struct task {
	int taskNUM;
	bool isThereATask;
	char taskName[MAXTASKNAMELENGTH];
	DATE;
}TASK;


TASK createTask(int);

void taskDelete(TASK[], int);

TASK updateExistingTask(TASK[]);

bool isListFull(TASK[]);

void displayOneTask(TASK[], int);

void displayRangeOfTasks(TASK[], int, int);

void listOfAllTasks(TASK[]);

void searchForATAsk(TASK[]);