#include <stdio.h>
#include <pthread.h>

void *threadFunction(void *args)
{
	while (1)
	{
		printf("I am a thread function. \n");
	}
}

int main()
{
	pthread_t id;
	int ret;
	ret = pthread_create(&id, NULL, &threadFunction, NULL);
	if (ret == 0)
	{
		printf("Thread created sucessfully.\n");
	}
	else
	{
		printf("Thread is not created.\n");
	}
	while (1)
	{
		printf("I am a main function");
	}
	return 0;
}
