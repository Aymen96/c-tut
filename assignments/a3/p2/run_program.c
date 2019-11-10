#include "run_program.h"
#include "unistd.h" // fork
#include <stdlib.h> // exit
#include <string.h> // memcpy
#include <sys/wait.h> // WEXITSTATUS, WIFEXITED, waitpid

#define ERROR_CODE 127

int run_program(char *file_path, char *arguments[])
{
    if(file_path == NULL || arguments == NULL) {
        return ERROR_CODE;
    }

    /* fork() in C
    * Negative Value: creation of a child process was unsuccessful.
    * Zero: Returned to the newly created child process.
    * Positive value: Returned to parent or caller. The value contains process ID of newly created child process.
    */
    int child_pid = fork();
    int status;
    if(child_pid == -1) {
        return ERROR_CODE;
    } else if (child_pid == 0) {
        // get length of args
        int len = 0;
        while(arguments[len++] != NULL);
        // prepare arguments vector
        char **argv = malloc(sizeof(char*) * (len + 1));
        argv[0] = file_path;
        memcpy(&argv[1], arguments, sizeof(char*) * len);
        execvp(argv[0], argv);
        // not accessible if everything goes well with the execution
        exit(ERROR_CODE);
    } else {
        if (waitpid(child_pid, &status, 0) == -1) {
            return ERROR_CODE;
        }
        // these funcs return status of child process
        // for later revision see http://openbook.rheinwerk-verlag.de/linux_unix_programmierung/Kap07-008.htm
        return WIFEXITED(status) ? WEXITSTATUS(status) : ERROR_CODE;
    }
    // remember to return ERROR_CODE on error.
    return ERROR_CODE;
}
