#include <stdio.h>
#include <stdbool.h>

#define MEMORY_SIZE 100
#define NUM_BLOCKS 10

struct MemoryBlock
{
    int id;
    int size;
    bool allocated;
};

void bestFit(struct MemoryBlock memory[], int num_blocks, int processId, int processSize)
{
    int bestFitIndex = -1;
    int bestFitSize = MEMORY_SIZE + 1;

    for (int i = 0; i < num_blocks; ++i)
    {
        if (!memory[i].allocated && memory[i].size >= processSize && memory[i].size < bestFitSize)
        {
            bestFitIndex = i;
            bestFitSize = memory[i].size;
        }
    }

    if (bestFitIndex != -1)
    {
        memory[bestFitIndex].allocated = true;
        memory[bestFitIndex].id = processId;
        printf("Process %d of size %d allocated to memory block %d\n", processId, processSize, bestFitIndex);
    }
    else
    {
        printf("Process %d of size %d cannot be allocated.\n", processId, processSize);
    }
}

void printMemory(const struct MemoryBlock memory[], int num_blocks)
{
    printf("Memory Status:\n");
    for (int i = 0; i < num_blocks; ++i)
    {
        printf("Block %d: ", i);
        if (memory[i].allocated)
        {
            printf("Process %d (%d bytes)\n", memory[i].id, memory[i].size);
        }
        else
        {
            printf("Free (%d bytes)\n", memory[i].size);
        }
    }
}

int main()
{
    struct MemoryBlock memory[NUM_BLOCKS] = {
        {0, 10, false}, {0, 20, false}, {0, 30, false}, {0, 40, false}, {0, 50, false}, {0, 60, false}, {0, 70, false}, {0, 80, false}, {0, 90, false}, {0, 100, false}};

    int processes[][2] = {{1, 25}, {2, 55}, {3, 12}, {4, 70}};

    for (int i = 0; i < sizeof(processes) / sizeof(processes[0]); ++i)
    {
        bestFit(memory, NUM_BLOCKS, processes[i][0], processes[i][1]);
        printMemory(memory, NUM_BLOCKS);
    }

    return 0;
}
