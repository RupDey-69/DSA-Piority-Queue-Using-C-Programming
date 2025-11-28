// Priority Queue using Array

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Structure for priority queue element
struct element
{
    int value;
    int piority;
};

struct element pq[SIZE];
int count = 0;

// ENQUEUE OPERATION (Insert in sorted priority)
void Enqueue(int val, int piority)
{
    if (count == SIZE)
    {
        printf("Queue Overflow!\n");
        return;
    }

    int i = count - 1;

    // Shift elements to right based on priority (higher priority first)
    while (i >= 0 && pq[i].piority < piority)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    // Insert new element
    pq[i + 1].value = val;
    pq[i + 1].piority = piority;

    count++;
}

// DEQUEUE OPERATION (Remove highest priority element)
int Dequeue()
{
    if (count == 0)
    {
        printf("Queue Underflow!\n");
        return -1;
    }

    int removedValue = pq[0].value;

    // Shift elements left
    for (int i = 0; i < count - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    count--;

    printf("Deleted Element = %d\n", removedValue);
    return removedValue;
}

// DISPLAY FUNCTION
void display()
{
    if (count == 0)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Value: %d  Priority: %d\n", pq[i].value, pq[i].piority);
    }
}

int main()
{
    int choice, val, p;

    while (1)
    {
        printf("\n<----Queue Menu--->");
        printf("\n 1.Enqueue");
        printf("\n 2.Dequeue");
        printf("\n 3.Display");
        printf("\n 4.Exit");

        printf("\nEnter the Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Element: ");
            scanf("%d", &val);
            printf("Enter Priority: ");
            scanf("%d", &p);
            Enqueue(val, p);
            break;

        case 2:
            Dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice.....");
        }
    }

    return 0;
}
