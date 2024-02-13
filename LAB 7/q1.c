//Simulate Page Replacement algorithm 
//FIFO

#include <stdio.h>
#include <stdbool.h>

#define FRAME_SIZE 3       // Size of the page frame
#define REF_STRING_SIZE 10 // Size of the reference string

int pageFrame[FRAME_SIZE]; // Array to represent the page frame
int pageFaults = 0;        // Counter to track page faults

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

// Function to replace the oldest page in the page frame with a new page
void replacePage(int pageNumber)
{
    int oldestPageIndex = 0; // Index of the oldest page
    for (int i = 1; i < FRAME_SIZE; ++i)
    {
        if (pageFrame[i] < pageFrame[oldestPageIndex])
        {
            oldestPageIndex = i; // Find the index of the oldest page
        }
    }
    pageFrame[oldestPageIndex] = pageNumber; // Replace the oldest page with the new page
}

// Function to simulate FIFO page replacement algorithm
void fifo(int refString[], int refStringSize)
{
    initPageFrame(); // Initialize the page frame
    printf("Simulation using FIFO Page Replacement Algorithm:\n");
    for (int i = 0; i < refStringSize; ++i)
    {
        printf("Reference String: %d\n", refString[i]);
        if (!isPagePresent(refString[i]))
        {
            ++pageFaults;
            replacePage(refString[i]); // Replace page if it's not present in the frame
        }
        displayPageFrame(); // Display the page frame after each reference
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main()
{
    int referenceString[] = {0, 1, 2, 0, 3, 0, 4, 2, 3, 1}; // Reference string
    int referenceStringSize = sizeof(referenceString) / sizeof(referenceString[0]);

    fifo(referenceString, referenceStringSize); // Simulate FIFO page replacement algorithm

    return 0;
}
