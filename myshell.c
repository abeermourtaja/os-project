#include "myshell.h"
int main(int argc, char *argv[]) {
    char buf[MAX_BUFFER];               // Input buffer
    char pwd[MAX_PATH];                 // Current path
    char shell_path[MAX_PATH] = "shell=";
    char readme_path[MAX_PATH] = "readme_path=";
    char newpath[MAX_PATH * 10];        // Updated PATH variable

    // Get current PATH, append current directory
    strcpy(newpath, getenv("PATH"));
    strcat(newpath, ":");

    // Get path of myshell executable
    if (strcmp(argv[0], "./myshell") && strcmp(argv[0], "myshell")) {
        int len = strlen(argv[0]);
        while (len && argv[0][len] != '/') len--;
        argv[0][len] = '\0';
        get_fullpath(pwd, argv[0]);
    } else {
        strcpy(pwd, getenv("PWD"));
    }

    strcat(newpath, pwd);
    setenv("PATH", newpath, 1);

    strcat(shell_path, pwd);
    strcat(shell_path, "/myshell");
    putenv(shell_path); // shell=/your/path/myshell

    strcat(readme_path, pwd);
    strcat(readme_path, "/readme");
    putenv(readme_path); // readme_path=/your/path/readme

    // If batch file given: run it directly
    if (argc > 1) {
        strcpy(buf, "myshell ");
        for (int i = 1; i < argc; i++) {
            strcat(buf, argv[i]);
            strcat(buf, " ");
        }
        Execute(buf);  // run batch file
    } else {
        // Interactive shell welcome message
        Command_clear();
                
        printf( "-------------------Welcome to our shell!-------------------\n" );
        printf( "-------------------Abeer, Tasneem, Taghreed-----------------\n\n" );

        printf("Type "  "help"  " to view manual.\n");
        printf("Type "  "exit"  " to terminate.\n");

        // Start main shell loop (takes input from stdin)
        Command_shell(stdin, NULL, NULL);
    }

    return 0;
}

