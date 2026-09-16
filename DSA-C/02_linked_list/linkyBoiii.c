#include <stdbool.h>
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

void insertAtEnd(Node *head, int e);
void insertAtBeginning(Node **head, int e);
void insertAtMiddle(Node *head, int e, int pos);

void removeFirstNode(Node **head);
void removeAtMiddle(Node *head, int pos);
void removeLastNode(Node *head);

int ListLength(Node *head);
bool search(Node *head, int key);
void reverseList(Node *head);

void display(Node *head);

int main()
{

    int choice;
    Node *head = NULL;
    while (ll == 0)
    {
        printf("1.Insert at end\n");
        printf("2.Insert at beginning\n");
        printf("3.Insert at middle\n");

        printf("4.Remove first node\n");
        printf("5.Remove at middle\n");
        printf("6.Remove last node\n");

        printf("7.Search for an element\n");
        printf("8.Find Length of linked list\n");
        printf("9.Reverse the linked list\n");
        printf("10.Display the list\n");
        printf("11.Exit\n");
        printf("Select operation you want to perform: \n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter element: ");
            int element;

            scanf("%d", &element);

            if (head == NULL)
            {
                head = createNode(element);
            }
            else
            {
                insertAtEnd(head, element);
            }
            break;
        }

        case 2:
        {
            printf("Enter element: ");
            int element;
            scanf("%d", &element);

            if (head == NULL)
            {
                head = createNode(element);
            }
            else
            {
                insertAtBeginning(&head, element);
            }
            break;
        }
        case 3:
        {
            printf("Enter element: ");
            int element;
            scanf("%d", &element);
            printf("Enter position: ");
            int pos;
            scanf("%d", &pos);

            if (ListLength(head) > pos)
            {
                printf("Invalid Position");
                break;
            }
            else
            {
                insertAtMiddle(head, element, pos);
            }

            break;
        }
        case 4:
        {
            removeFirstNode(&head);
            break;
        }
        case 5:
        {
            int pos;
            printf("Enter position to remove element");
            scanf("%d", &pos);

            removeAtMiddle(head, pos);
            break;
        }
        case 6:
        {
            removeLastNode(head);
            break;
        }
        case 7:
        {
            int key;
            printf("Enter element to search for: ");
            scanf("%d", &key);

            if (search(head, key))
            {
                printf("Element is present in list\n");
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        }
        case 8:
        {
            printf("The length of the current list is %d\n", ListLength(head));
            break;
        }
        case 9:
        {
            // to implement
            // reverse()
            break;
        }
        case 10:
        {
            display(head);
            break;
        }
        case 11:
        {
            printf("Exiting the program thank you for traversing with us tonight!\n");
            break;
        }
        default:
        {
            break;
        }
        }
    }

    return 0;
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

    for (int i = 0; i < pos - 1 && temp->next != NULL; i++)
    {
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

void removeFirstNode(Node **head)
{

    if (*head == NULL)
    {
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void removeAtMiddle(Node *head, int pos)
{
    if (head == NULL)
        return;

    Node *temp = head;

    for (int i = 0; i < pos - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }

    Node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
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

int ListLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

bool search(Node *head, int key)
{
    Node *temp = head;
    bool found = false;

    while (temp->next != NULL)
    {
        if (temp->element == key)
        {
            found = true;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    return found;
}