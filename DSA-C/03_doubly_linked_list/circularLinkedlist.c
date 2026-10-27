#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int exponent;
    struct Node *next;
} Term;

Term *createNode(int c, int e)
{
    Term *t = malloc(sizeof(Term));
    if (t == NULL)
        return NULL;

    t->coeff = c;
    t->exponent = e;
    t->next = t;
    return t;
}

void insert(int c, int e, Term **head)
{
    Term *newt = createNode(c, e);
    if (newt == NULL)
        return;

    if (*head == NULL)
    {
        *head = newt;
        return;
    }

    Term *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    newt->next = *head;
    temp->next = newt;
}

Term *add(Term *head1, Term *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    Term *p1 = head1, *p2 = head2;
    Term *result = NULL;

    while (1)
    {
        if (p1->exponent > p2->exponent)
        {
            insert(p1->coeff, p1->exponent, &result);
            p1 = p1->next;
        }
        else if (p2->exponent > p1->exponent)
        {
            insert(p2->coeff, p2->exponent, &result);
            p2 = p2->next;
        }
        else
        {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                insert(sum, p1->exponent, &result);

            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1 == head1 || p2 == head2)
            break;
    }

    while (p1 != head1)
    {
        insert(p1->coeff, p1->exponent, &result);
        p1 = p1->next;
    }

    while (p2 != head2)
    {
        insert(p2->coeff, p2->exponent, &result);
        p2 = p2->next;
    }

    return result;
}

void display(Term *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    Term *temp = head;
    do
    {
        printf("%+dx^%d ", temp->coeff, temp->exponent);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main()
{
    Term *p1 = NULL, *p2 = NULL;
    int n, coeff, exp;

    printf("Enter number of terms in P1: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &coeff, &exp);
        insert(coeff, exp, &p1);
    }

    printf("Enter number of terms in P2: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &coeff, &exp);
        insert(coeff, exp, &p2);
    }

    printf("P1: ");
    display(p1);

    printf("P2: ");
    display(p2);

    Term *result = add(p1, p2);

    printf("Sum: ");
    display(result);

    return 0;
}
