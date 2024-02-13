#include <stdio.h>
#include <unistd.h>
int main()
{
    int pid;
    printf("The main program process ID is %d \n\n", (int)getpid());
    pid = fork();
    if (pid != 0)
    {
        printf("This is the parent process with id %d \n", (int)getppid());
        printf("This is the child process with id %d \n", (int)getpid());
    }
    else
    {
        printf("The child process with id %d\n\n", (int)getpid());
    }
    return 0;
}