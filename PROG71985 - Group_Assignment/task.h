

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