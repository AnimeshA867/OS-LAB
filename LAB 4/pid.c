#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    // Get the process ID
    pid = getpid();

    // Print the process ID
    printf("Process ID: %d\n", pid);

    return 0;
}
