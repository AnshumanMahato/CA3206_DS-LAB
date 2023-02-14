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

node *front = NULL, *rear = NULL;

void insert()
{
    node *temp = create_node();
    if (!front)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void del()
{
    node *temp;
    if (!front)
        printf("Queue is Empty\n");
    else
    {
        printf("%d is deleted from queue\n", front->data);
        temp = front;
        front = front->next;
        free(temp);
    }
}

void traverse()
{
    node *temp;
    if (!front)
        printf("Queue is Empty\n");
    else
    {
        temp = front;
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
        printf("\nQueue Menu\n");
        printf("1.Insert \n");
        printf("2.Delete \n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("\nEnter Choice(1-4):");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            del();
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
