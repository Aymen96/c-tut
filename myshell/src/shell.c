#include <stdio.h>

int start_shell ()
{
    printf("MyShell Version 1.0 Created by Aymen Hachicha on 05/10/2019\n");
    printf("Shell started ..\n");
    return 0;
};

int quit_shell ()
{
    // here. I have to check if all processes are finished running
    // wait for all processes to finish computing
    // if argument specify otherwise kill all running processes and stop shell
    printf("Shell stopped. Bye :)\n");
    return 0;
};