#include <stdio.h>
#include <string.h>
#include "templates.h"

#define MIN 0
#define MAX 1

int IntPrompt(char *prompt, int range[2])
{
	int success = 0;
	int test;
	int output;

	do{
		char buf[BUFSIZ];
				
		printf("%s\n", prompt);
		fgets(buf, sizeof(buf), stdin);
		test = sscanf(buf, "%d", &output);

		if(test != 1 || output < range[MIN] || output > range[MAX])
			puts("Invalid Entry");
		else
			success = 1;
	} while(!success);

	return output;
}

void StrPrompt(char *prompt, char *output, int outputLen)
{	
	int success = 0;
	int test;

	do{
		char buf[BUFSIZ];

		printf("%s\n", prompt);
		fgets(buf, sizeof(buf), stdin);
		
		if (strlen(buf) > outputLen)
		{
			puts("Input too long!");
			continue;
		}
		else if (strlen(buf) <= 1)
		{
			puts("Empty Input!");
			continue;
		}
		else if (buf[strlen(buf) - 1] != '\n')       // Checks if full line read
        {
            printf("Invalid Input. Line exceeds maximum length (%d chars)\n",
				   outputLen - 1);
            continue;
        }

		test = sscanf(buf, "%s", output);

		if(test != 1)
			puts("Invalid Entry");
		else
			success = 1;

	} while(!success);
}
