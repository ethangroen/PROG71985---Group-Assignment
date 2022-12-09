// Group Assignment - To Do / Task List
// For this project we were tasked with creating a to do list
// The list needs to have the options to add, remove, edit and view the tasks
// The program also needs to save data between instances and load data from previous sessions if there is any

// loadAndSave Header File
// PROG71985 - 22F
// Ethan Groen, Jordan Sinclair - December 2022

// revision history
// 1.0			2022-December-04			initial

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define MAXFILESIZE 256

#include "task.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool SavetdListToDisk(TASK[], char*);

void SaveTaskToStream(TASK, FILE*);

bool LoadtdListFromDisk(TASK[], char*);

void removeNfromChar(char*);
