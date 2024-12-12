
#include <stdio.h>

#define MAX 10

// Stack structure
typedef struct
{
    int data[MAX];
    int top;
} Stack;

// initialize stack
void init(Stack *s)
{
    s->top = -1;
}

// check if stack is full
int full(Stack *s)
{
    return s->top == MAX - 1;
}

// check if stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1;
}

// push item onto the stack
void push(Stack *s, int value)
{
    if (!full(s))
    {
        s->data[++(s->top)] = value;
    }
}

// check if numbers in the stack are in ascending order
int asc(Stack *s)
{
    for (int i = 0; i < s->top; i++)
    {
        if (s->data[i] > s->data[i + 1])
        {
            return 0; // not in ascending order
        }
    }
    return 1; // ascending order
}

int main()
{
    Stack stack;
    int number, choice;
    int exitFlag = 0; // track if the user chooses to exit

    printf("Miss Hatice's Number Order Checker\n");

    do
    {
        printf("\nMenu:\n");
        printf("1.Enter a new set of numbers.\n");
        printf("2.Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            init(&stack); // initialize/reset stack for new entry
            printf("Enter 10 numbers:\n");

            // push the taken numbers to stack
            for (int i = 0; i < MAX; i++)
            {
                printf("Enter number %d: ", i + 1);
                scanf("%d", &number);
                push(&stack, number);
            }

            // showing entered set of numbers
            printf("You entered: ");
            for (int i = 0; i <= stack.top; i++)
            {
                printf("%d ", stack.data[i]);
            }
            printf("\n");

            // check if numbers are in ascending order
            if (asc(&stack))
            {
                printf("Numbers are in the correct order.\n");
            }
            else
            {
                printf("Numbers are not in correct order.\n");
            }
            break;

        case 2:
            printf("Bye bye :) \n");
            exitFlag = 1; // setting exitFlag to true to stop the loop
            break;

        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    } while (!exitFlag); // loop until user chooses to exit

    return 0;
}