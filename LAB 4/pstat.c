#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    int pid;
    pid = fork();
    if (pid == 0)
    {
        printf("I am the child, my pid is %d\n", getpid());
        printf("My parent's pid is %d\n", getppid());
        sleep(10);
        printf("I am the child, my pid is %d\n", getppid());
        printf("My parent's pid is %d\n", getppid());
    }
    else
    {
        sleep(10);
        printf("I am the parent, my pid is %d\n", getpid());
        printf("My parent's pid is %d\n", getppid());
        for (;;)
            ;
    }
    return 0;
}