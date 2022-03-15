#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <stdio.h>
#include <argp.h>

#define MAX_ARGS 4

// structure for function arguments
typedef struct arguments 
{
    char *args[MAX_ARGS];
    unsigned int outputFlag;
    unsigned int fileFlag;
    char *fOutput;
    char *fInput;
} arguments;

/**
 *	Desc:	Opens file for log output
 *
 *	Param:	fName -- char *, output fName
 *
 *	Return: fLogOut -- FILE *, output ptr
 */
FILE *LogFileOpen(char *fName);

/**
 *	Desc:	Outputs formatted msg to log with timestamp depending on lvl
 *
 *	Param:	lvl -- int, level of logging
 *			logMsg -- char *, message content
 *
 *	Return: 0 on success
 */
int LogOutput(int lvl, char *logMsg);

/**
 *	Desc:	Do/While loop to capture user integer input within range using
 *			supplied prompt
 *
 *	Param:	prompt -- char *, User Prompt
 *			range[2] -- 2-len int array, first position minimum, second position
 *										 maximum
 *
 *	Return: output -- int, valid integer input
 */
int IntPrompt(char *prompt, int range[2]);

/**
 *	Desc:	Do/While loop to capture user string input up to given len
 *
 *	Param:	prompt -- char *, User Prompt
 *			output -- char *, String ptr for capturing input
 *			len -- outputLen, length of string pointed to by output
 *
 *	Return: none
 */
void StrPrompt(char *prompt, char *output, int outputLen);

/**
 * Desc:     Option Parser for argp.h
 *
 * Param:      key -- integer, indicates option key from options struct
 *             arg -- char ptr, string value of argument
 *             state -- argp_state struct ptr, passes state value of
 *                     input while options are parsed
 *
 * Return:     error_t value to be parsed via argp.h
 */
static error_t ParseOpt(int key, char *arg, struct argp_state *state);

/**
 * Desc:	Wrapper for argp_parse
 *
 * Param:	argc -- int, passed from cmd line
 *			argv -- char **, passed from cmd line
 *			arguments -- arguments struct
 *
 * Return:	none
 */
void ParseArgs(int argc, char **argv, arguments arguments);

#endif // End TEMPLATE_H
