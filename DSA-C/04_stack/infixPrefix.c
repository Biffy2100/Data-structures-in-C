#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

char peek()
{
    if (top == -1)
        return '\0';
    return stack[top];
}

// Function to determine operator precedence
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void in_pre(char inf[], int n)
{
    int k = 0;
    int i = n - 1;
    char pre_exp[MAX];

    for (int j = 0; j < MAX; j++)
        pre_exp[j] = '\0';

    while (i >= 0)
    {
        char tkn = inf[i];

        // If the token is an operand, add it to the output
        if (isalnum(tkn))
        {
            pre_exp[k++] = tkn;
        }
        // If the token is ')' push it to the stack
        else if (tkn == ')')
        {
            push(tkn);
        }
        // If the token is '(' pop from stack until ')' is found
        else if (tkn == '(')
        {
            while (top != -1 && peek() != ')')
            {
                pre_exp[k++] = pop();
            }

            if (top != -1 && peek() == ')')
            {
                pop(); // Remove ')' from stack
            }

        }
        // If an operator is encountered
        else
        {
            while (top != -1 && precedence(peek()) > precedence(tkn))
            {
                pre_exp[k++] = pop();
            }

            push(tkn);
        }

        i--;
    }

    // Pop all the remaining operators from the stack
    while (top != -1)
    {
        pre_exp[k++] = pop();
    }

    pre_exp[k] = '\0';

    // Reverse the result to get the final prefix expression
    int len = strlen(pre_exp);
    
    for (int j = 0; j < len / 2; j++)
    {
        char temp = pre_exp[j];
        pre_exp[j] = pre_exp[len - j - 1];
        pre_exp[len - j - 1] = temp;
    }

    printf("Prefix Expression: %s\n", pre_exp);
}

int main()
{
    char inf[] = "A+B*C-D";
    printf("Infix Expression: %s\n", inf);
    in_pre(inf, strlen(inf));
    return 0;
}