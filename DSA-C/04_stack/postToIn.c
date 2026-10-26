#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
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

void postToInfix(char post[], int n)
{
    for (int i = 0; i < n; i++)
    {
        char tkn = post[i];

        if (isalnum(tkn))
        {
            char operand[2];

            operand[0] = tkn;
            operand[1] = '\0';

            push(operand);
        }
        else if (isOperator(tkn))
        {
            char *op2 = pop();
            char *op1 = pop();

            char exp[MAX];

            exp[0] = '(';
            exp[1] = '\0';

            strcat(exp, op1);

            int len = strlen(exp);
            exp[len] = tkn;
            exp[len + 1] = '\0';

            strcat(exp, op2);

            strcat(exp, ")");

            push(exp);
        }
    }

    printf("Infix Expression: %s\n", pop());
}

int main()
{
    char post[] = "AB+C*D-";

    printf("Postfix Expression: %s\n", post);

    postToInfix(post, strlen(post));

    return 0;
}