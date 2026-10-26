#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define max 100

char stack[max][max];
int top = -1;

void push(char str[])
{
    strcpy(stack[++top], str);
}

char *pop()
{
    return stack[top--];
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '^');
}

void preToPost(char pre[], int n)
{
    int i = n - 1;

    while (i >= 0)
    {
        char tkn = pre[i];

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

            char exp[max];

            strcpy(exp, op1);
            strcat(exp, op2);

            int len = strlen(exp);
            exp[len] = tkn;
            exp[len + 1] = '\0';

            push(exp);
        }

        i--;
    }

    printf("Postfix Expression: %s\n", pop());
}

int main()
{
    char pre[] = "-*+ABCD";

    printf("Prefix Expression: %s\n", pre);

    preToPost(pre, strlen(pre));

    return 0;
}