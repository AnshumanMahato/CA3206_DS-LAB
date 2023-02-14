#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    node *next;
} node;

node *create_node()
{
    int val;
    node *newnode = (node *)malloc(sizeof(node));
    printf("Enter Value to be pushed: ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

node *top = NULL;

void push()
{
    node *temp = create_node();
    if (!top)
        top = temp;
    else
    {
        temp->next = top;
        top = temp;
    }
}

void pop()
{
    node *temp;
    if (!top)
        printf("\nStack is Empty. Nothing can be popped.\n\n");
    else
    {
        printf("\n%d has been popped.", top->data);
        temp = top;
        top = top->next;
        free(temp);
    }
}

void traverse()
{

    node *temp;
    if (!top)
        printf("\nStack is Empty. Nothing can be popped.\n\n");
    else
    {
        temp = top;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int ch, val;
    do
    {
        printf("\nStack Menu\n");
        printf("1.Push \n");
        printf("2.Pop \n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("\nEnter Choice(1-4):");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;
        case 4:
            printf("Exiting...\n\n");
            break;
        default:
            printf("Invalid Choice\n\n");
        }
    } while (ch != 4);

    return 0;
}
