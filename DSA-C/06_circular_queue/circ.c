#include <stdio.h>
#define max 5

int queue[max];
int f = -1;
int r = -1;

void enqueue(int x)
{
    if (r == max - 1 && f == 0 || ((r + 1) % max == f))
    {
        printf("Queue is full");
        return;
    }

    if (f == -1)
    {
        f = 0;
        r = 0;
    }
    else
    {
        r = (r + 1) % max;
    }

    queue[r] = x;
}

void dequeue(void)
{
    if (f == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    if (f == r)
    {
        // Removing the last element
        f = -1;
        r = -1;
    }
    else
    {
        f = (f + 1) % max;
    }
}

void display(void)
{
    if (f == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    int i = f;

    while (1)
    {
        printf("Queue element: %d\n", queue[i]);

        if (i == r)
        {
            break;
        }

        i = (i + 1) % max;
    }
}

int main(void)
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printf("Initial queue:\n");
    display();

    enqueue(6);

    dequeue();
    dequeue();

    printf("\nAfter two dequeues:\n");
    display();

    enqueue(6);
    enqueue(7);

    printf("\nAfter adding 6 and 7:\n");
    display();

    return 0;
}