#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "templates.h"

#define LOG_LEN 120
#define LOG_LEVEL 3
#define F_NAME "log.txt"

FILE *LogFileOpen(char *fName)
{
	FILE *fLogOut;
	fLogOut = fopen(fName, "a");
	if (fLogOut == NULL)
	{
		perror("Cannot Open Log File!");
		exit(EXIT_FAILURE);
	}
	return fLogOut;
}

int LogOutput(int lvl, char *logMsg)
{
	FILE *fLogOut;
	char msg[LOG_LEN] = "";
	time_t currentTime;
	char *enum_names[4] = {" OFF: ", " ERROR: ", " WARNING: ", " INFO: "};
	
	time(&currentTime);
	
	if (lvl >= LOG_LEVEL)
	{
		fLogOut = LogFileOpen(F_NAME);
		
		strcat(msg, ctime(&currentTime));
		strcat(msg, enum_names[lvl]);
		strcat(msg, logMsg);
		
		fprintf(fLogOut, "%s\n", msg);

		fclose(fLogOut);
	}
	return 0;
}
