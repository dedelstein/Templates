#include <argp.h>
#include "templates.h"

// argp.h-specific information for --help and -V output
// all argp.h-related code is adapted from:
// https://www.gnu.org/software/libc/manual/html_node/Argp-Example-3.html and
// http://nongnu.askapache.com/argpbook/step-by-step-into-argp.pdf
const char *argp_program_bug_address = "<daedel@ttu.ee>";
const char *argp_program_version = "version 1.0";

// Descriptor for argp.h, displayed with --help
static char argpDoc[] = "BQuery -- A program to query broadcast info via "
                        "user input\vProgram can be run without options to "
                        "use default parameters\n(Equiv. to 'hw3 -v -o')";

// argp_option ptr array to be used by argp.h
static struct argp_option options[] =
{
    {       0,    0, 0,                0, "Output Options"},
    {"verbose", 'v', 0,                0, "Display results in terminal"},
    {"quiet",   'q', 0,                0, "Hide results from terminal"},
    {"silent",  's', 0,     OPTION_ALIAS,                            0},
    {"muted",   'm', 0,                0, "Do not output results to file"},
    {       0,    0, 0,                0, "Redirect Options"},
    {"output", 'o', "FILE", OPTION_ARG_OPTIONAL,
     "Output results [to FILE]"},
    {"input",     0, "FILE",           0, "Select FILE for input"},
    {      0,     0, 0,       OPTION_DOC,
     "Default Input File: 'data.txt'\nDefault Output File: 'results.txt'"},
    {0}
};

// creates an argp struct to be parsed by argp_parse, which is a function of
// argp.h
static struct argp argp = {options, ParseOpt, 0, argpDoc};

void ParseArgs(int argc, char **argv, arguments arguments)
{
	argp_parse(&argp, argc, argv, 0, 0, &arguments);
}

/**
 *  Options parser for argp.h, reads key and either passes response to 
 *  arguments struct pointer or passes back an error value to be read by
 *  argp.h, uses argp_state pointer to deal with argument count
 */
static error_t ParseOpt(int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;

    switch (key)
    {
        case 'v':                       // pass output to stdout 
            arguments->outputFlag = 1; 
            break;
        case 'q': case 's':             // hide output from stdout
            arguments->outputFlag = 0; 
            break;
        case 'm':                       // do not write to file
            arguments->fileFlag = 0;
            break;
        case 'o':                       // write to file, user-provided
            {                           // fname is optional arg
            arguments->fileFlag = 1;

            if (arg == NULL)
                arguments->fOutput = "output.txt";
            else
                arguments->fOutput = arg;
            }
            break;
        case 'i':                       // change input fname
            arguments->fInput = arg;
            break;

        case ARGP_KEY_ARG:       // argp.h defined keyword for arg #
            if (state->arg_num >= MAX_ARGS) // too many args
                argp_usage (state);

            arguments->args[state->arg_num] = arg; // keep treack of
                                                   // of current arg
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}
