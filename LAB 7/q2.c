// Simulate Page Replacement algorithm
// Optimal

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define FRAME_SIZE 3 // Size of the page frame
#define REF_STRING_SIZE 10 // Size of the reference string

int pageFrame[FRAME_SIZE]; // Array to represent the page frame
int pageFaults = 0; // Counter to track page faults

// Function to initialize the page frame
void initPageFrame() {
    for (int i = 0; i < FRAME_SIZE; ++i) {
        pageFrame[i] = -1; // Initialize all frame entries to -1, indicating empty frame
    }
}

// Function to display the page frame
void displayPageFrame() {
    printf("Page Frame: ");
    for (int i = 0; i < FRAME_SIZE; ++i) {
        if (pageFrame[i] == -1) {
            printf("- "); // Print '-' for empty frame
        } else {
            printf("%d ", pageFrame[i]); // Print the page number
        }
    }
    printf("\n");
}

// Function to check if a page is present in the page frame
bool isPagePresent(int pageNumber) {
    for (int i = 0; i < FRAME_SIZE; ++i) {
        if (pageFrame[i] == pageNumber) {
            return true;
        }
    }
    return false;
}

// Function to find the page in the page frame that will not be used for the longest time in the future
int findOptimalReplacementPage(int refString[], int startIndex) {
    int index = -1; // Index of the page to be replaced
    int farthestDistance = -1; // Farthest distance to the next occurrence of each page in the frame
    
    for (int i = 0; i < FRAME_SIZE; ++i) {
        int j;
        for (j = startIndex; j < REF_STRING_SIZE; ++j) {
            if (pageFrame[i] == refString[j]) {
                if (j > farthestDistance) {
                    farthestDistance = j; // Update the farthest distance for the current page in the frame
                    index = i; // Update the index of the page to be replaced
                }
                break;
            }
        }
        if (j == REF_STRING_SIZE) {
            return i; // If a page will not be referenced again, it is a good candidate for replacement
        }
    }
    
    return index;
}

// Function to simulate Optimal page replacement algorithm
void optimal(int refString[], int refStringSize) {
    initPageFrame(); // Initialize the page frame
    printf("Simulation using Optimal Page Replacement Algorithm:\n");
    
    for (int i = 0; i < refStringSize; ++i) {
        printf("Reference String: %d\n", refString[i]);
        if (!isPagePresent(refString[i])) {
            ++pageFaults;
            int replacementIndex = findOptimalReplacementPage(refString, i + 1); // Find the page to be replaced
            pageFrame[replacementIndex] = refString[i]; // Replace the page
        }
        displayPageFrame(); // Display the page frame after each reference
    }
    
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int referenceString[] = {0, 1, 2, 0, 3, 0, 4, 2, 3, 1}; // Reference string
    int referenceStringSize = sizeof(referenceString) / sizeof(referenceString[0]);
    
    optimal(referenceString, referenceStringSize); // Simulate Optimal page replacement algorithm
    
    return 0;
}
