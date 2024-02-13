#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("This program demonstrates the fork.\n");
    fork();
    fork();
    printf("Hey there delilah!\n");
}