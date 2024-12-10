#include <stdio.h>
#include <stdbool.h>

#define PROCESSES 5
#define RESOURCES 3

void calculate_need(int need[PROCESSES][RESOURCES], int max[PROCESSES][RESOURCES], int allocation[PROCESSES][RESOURCES])
{
    for (int i = 0; i < PROCESSES; i++)
    {
        for (int j = 0; j < RESOURCES; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void print_matrices(int processes[PROCESSES], int available[RESOURCES], int max[PROCESSES][RESOURCES], int allocation[PROCESSES][RESOURCES], int need[PROCESSES][RESOURCES])
{
    printf("\nMax Matrix:\n");
    for (int i = 0; i < PROCESSES; i++)
    {
        printf("P%d:\t", processes[i]);
        for (int j = 0; j < RESOURCES; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("\nAllocation Matrix:\n");
    for (int i = 0; i < PROCESSES; i++)
    {
        printf("P%d:\t", processes[i]);
        for (int j = 0; j < RESOURCES; j++)
        {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nNeed Matrix:\n");
    for (int i = 0; i < PROCESSES; i++)
    {
        printf("P%d:\t", processes[i]);
        for (int j = 0; j < RESOURCES; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable Resources:\n");
    for (int j = 0; j < RESOURCES; j++)
    {
        printf("Resource %d: %d\n", j + 1, available[j]);
    }
}

bool is_safe(int processes[PROCESSES], int available[RESOURCES], int max[PROCESSES][RESOURCES], int allocation[PROCESSES][RESOURCES])
{
    int need[PROCESSES][RESOURCES];
    calculate_need(need, max, allocation);

    print_matrices(processes, available, max, allocation, need);

    bool finish[PROCESSES] = {false};
    int safe_sequence[PROCESSES];
    int work[RESOURCES];

    for (int i = 0; i < RESOURCES; i++)
    {
        work[i] = available[i];
    }

    int count = 0;
    while (count < PROCESSES)
    {
        bool found = false;
        for (int i = 0; i < PROCESSES; i++)
        {
            if (!finish[i])
            {
                bool can_allocate = true;
                for (int j = 0; j < RESOURCES; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        can_allocate = false;
                        break;
                    }
                }

                if (can_allocate)
                {
                    for (int j = 0; j < RESOURCES; j++)
                    {
                        work[j] += allocation[i][j];
                    }

                    safe_sequence[count++] = processes[i];
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found)
        {
            printf("System is not in a safe state.\n");
            return false;
        }
    }

    printf("\nSystem is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < PROCESSES; i++)
    {
        printf("P%d ", safe_sequence[i]);
    }
    printf("\n");
    return true;
}

int main()
{
    int processes[PROCESSES] = {0, 1, 2, 3, 4};

    int available[RESOURCES] = {4, 2, 3};

    int max[PROCESSES][RESOURCES] = {
        {6, 4, 5},
        {5, 3, 2},
        {4, 2, 4},
        {3, 3, 2},
        {4, 2, 3}};

    int allocation[PROCESSES][RESOURCES] = {
        {2, 0, 1},
        {3, 1, 1},
        {1, 2, 1},
        {1, 1, 1},
        {0, 0, 1}};

    is_safe(processes, available, max, allocation);

    return 0;
}
