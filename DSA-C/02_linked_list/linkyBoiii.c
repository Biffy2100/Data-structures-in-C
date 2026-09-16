#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int element;
    struct Node *next;
} Node;

Node *createNode(int e)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->element = e;
    n->next = NULL;
    return n;
}

void insertAtEnd(Node *head, int e)
{

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *n = createNode(e);

    temp->next = n;
}

void insertAtMiddle(Node *head, int e, int pos)
{
    Node *new = createNode(e);

    Node *temp = head;

    for(int i = 0; i < pos-1 && temp->next != NULL;i++){
        temp = temp->next;
    }

    new->next = temp->next;
    temp->next = new;
}

void insertAtBeginning(Node **head, int e)
{
    Node *new = createNode(e);

    new->next = *head;
    *head = new;
}

void removeFirstNode()
{
}

void removeAtMiddle()
{
}

void removeLastNode(Node *head)
{

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    Node *temp2 = temp->next;
    free(temp2);

    temp->next = NULL;
}

void display(Node *head)
{

    Node *temp = head;

    while (temp->next != NULL)
    {

        printf("%d\t", temp->element);
        temp = temp->next;
    }
}

int main()
{

    Node *head = createNode(1);

    for (int i = 0; i < 5; i++)
    {
        int x;
        scanf("%d", &x);
        insertAtEnd(head, x);
    }

    display(head);

    return 0;
}