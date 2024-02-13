// Program that have two threads, one reads a words from keywords and another check for  valid word

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

char s[10];
void *check(void *parameter)
{
    int i;
    char *strings[] = {"NEPAL", "CANADA", "USA", "UK", "FRANCE", "BHUTAN", "CHINA", "JAPAN", "ITALY", "BRAZIL"};
    char *ch = (char *)parameter;

    for (i = 0; i < 10; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {

            printf("Valid country\n");
            return NULL; // Return only if the word is found
        }
    }

    // Return outside the loop if the word is not found
    printf("NOT valid country\n");
    return NULL;
}
void *string(void *parameter)
{
    printf("Enter country name (ALL CAPS):");
    scanf("%s", s);
    return NULL;
}

int main()
{
    pthread_t sthread_id;
    pthread_t cthread_id;
    pthread_create(&sthread_id, NULL, &string, NULL);
    pthread_join(sthread_id, NULL);
    pthread_create(&cthread_id, NULL, &check, NULL);
    pthread_join(cthread_id, NULL);
    return 0;
}
