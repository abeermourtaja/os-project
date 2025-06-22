#ifndef MYSHELL_H
#define MYSHELL_H

// Required system libraries for shell functionality
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <ctype.h>

// Macro constants for shell configuration
#define MAX_BUFFER 1024        // Maximum size for input command line
#define MAX_ARGS 64            // Maximum number of arguments per command
#define SEPARATORS " \t\n"     // Token separators: space, tab, newline
#define MAX_OPEN 10            // Maximum number of redirected input/output files
#define MAX_PATH 100           // Maximum length for file or directory path

// Structure to hold redirection information
typedef struct {
    char *filename;           // Name of the file used for redirection
    char opentype[3];         // Type of file opening: "a" (append), "r" (read), "w" (write)
    char open[3];             // Symbol used in command: ">>", "<", or ">"
} Redirect;

// External system variables
extern int errno;             // Error number set by system calls
extern char **environ;        // Array of environment variables

/*
 * Function declarations
 */

// Main execution function that receives a full command line
int Execute(char *buffer);

// Execute command with arguments, redirection info, and state flags
int Command_exec(char **args, const Redirect *Inputs, const Redirect *Outputs, int *states);

// Handle and display error messages
int Error(int errortype, char **args, const Redirect *IOputs, const int *states, char *msg);

// Parse the input buffer into arguments, input/output redirection, and states
int Command_strtok(char *buf, char **args, int *states, Redirect *Inputs, Redirect *Outputs);

// Built-in commands:

int Command_cd(char **args, const Redirect *Inputs, int *states);         // Handle 'cd'
void Command_clear(void);                                                 // Handle 'clr'
int Command_dir(char **args, const Redirect *Inputs, int *states);        // Handle 'dir'
int Command_echo(char **args, const Redirect *Inputs, int *states);       // Handle 'echo'
int list_environ(void);                                                   // Handle 'environ'
int show_pwd(void);                                                       // Handle 'pwd'
int Command_help(char **args, const Redirect *Outputs, int *states);      // Handle 'help'
int Command_bat(char **args, const Redirect *Inputs, const Redirect *Outputs, int *states); // Handle batch file execution

// Loop to read and execute commands (interactive or from file)
int Command_shell(FILE *inputfile, const Redirect *Outputs, const int *states);

// Delay function for process control
void Command_delay(int n);

// Get the absolute (full) path of a file or directory
void get_fullpath(char *fullpath, const char *shortpath);

#endif // MYSHELL_H

