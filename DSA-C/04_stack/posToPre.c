#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char c[])
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    strcpy(stack[++top], c);
}

char *pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return NULL;
    }

    return stack[top--];
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void pos_pre(char pos[], int n)
{
    for (int i = 0; i < n; i++)
    {
        char tkn = pos[i];

        if (isalnum(tkn))
        {
            char operand[2];
            operand[0] = tkn;
            operand[1] = '\0';

            push(operand);
        }
        else if (isOperator(tkn))
        {
            char *op1 = pop();
            char *op2 = pop();

            char exp[MAX];

            exp[0] = tkn;
            exp[1] = '\0';

            strcat(exp, op2);
            strcat(exp, op1);

            push(exp);
        }
    }

    printf("Prefix Expression: %s\n", pop());
}

int main()
{
    char pos[] = "AB+C*";

    printf("Postfix Expression: %s\n", pos);

    pos_pre(pos, strlen(pos));

    return 0;
}