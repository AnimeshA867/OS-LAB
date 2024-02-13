// Simulate Page Replacement algorithm
// LRU

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define FRAME_SIZE 3       // Size of the page frame
#define REF_STRING_SIZE 10 // Size of the reference string

int pageFrame[FRAME_SIZE]; // Array to represent the page frame
int pageFaults = 0;        // Counter to track page faults
int timeCounter = 0;       // Counter to track time of last use for each page

// Function to initialize the page frame
void initPageFrame()
{
    for (int i = 0; i < FRAME_SIZE; ++i)
    {
        pageFrame[i] = -1; // Initialize all frame entries to -1, indicating empty frame
    }
}

// Function to display the page frame
void displayPageFrame()
{
    printf("Page Frame: ");
    for (int i = 0; i < FRAME_SIZE; ++i)
    {
        if (pageFrame[i] == -1)
        {
            printf("- "); // Print '-' for empty frame
        }
        else
        {
            printf("%d ", pageFrame[i]); // Print the page number
        }
    }
    printf("\n");
}

// Function to check if a page is present in the page frame
bool isPagePresent(int pageNumber)
{
    for (int i = 0; i < FRAME_SIZE; ++i)
    {
        if (pageFrame[i] == pageNumber)
        {
            return true;
        }
    }
    return false;
}

// Function to find the least recently used page in the page frame
int findLRUPage()
{
    int index = 0;             // Index of the least recently used page
    int minTime = timeCounter; // Time of last use for the least recently used page

    for (int i = 0; i < FRAME_SIZE; ++i)
    {
        if (timeCounter - pageFrame[i] > minTime)
        {
            index = i;                            // Update the index of the least recently used page
            minTime = timeCounter - pageFrame[i]; // Update the time of last use
        }
    }

    return index;
}

// Function to simulate LRU page replacement algorithm
void lru(int refString[], int refStringSize)
{
    initPageFrame(); // Initialize the page frame
    printf("Simulation using LRU Page Replacement Algorithm:\n");

    for (int i = 0; i < refStringSize; ++i)
    {
        printf("Reference String: %d\n", refString[i]);
        ++timeCounter; // Increment the time counter for each reference
        if (!isPagePresent(refString[i]))
        {
            ++pageFaults;
            int replacementIndex = findLRUPage();       // Find the least recently used page to replace
            pageFrame[replacementIndex] = refString[i]; // Replace the page
        }
        displayPageFrame(); // Display the page frame after each reference
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main()
{
    int referenceString[] = {0, 1, 2, 0, 3, 0, 4, 2, 3, 1}; // Reference string
    int referenceStringSize = sizeof(referenceString) / sizeof(referenceString[0]);

    lru(referenceString, referenceStringSize); // Simulate LRU page replacement algorithm

    return 0;
}
