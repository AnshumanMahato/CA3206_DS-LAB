#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    node *next, *prev;
} node;

node *create_node(int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = newnode->prev = NULL;
    return newnode;
}

node *create_list(int n)
{
    node *head = NULL, *curr, *temp;
    int i = 0, val;
    while (i < n)
    {
        printf("\nEnter %d value:", i++);
        scanf("%d", &val);
        temp = create_node(val);
        if (!head)
            head = curr = temp;
        else
        {
            curr->next = temp;
            temp->prev = curr;
            curr = temp;
        }
    }
    return head;
}

void display_frontlist(node *head)
{
    node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void display_rearlist(node *head)
{
    node *temp = head;
    while (temp->next)
        temp = temp->next;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}

int main()
{
    int n;
    node *head;
    printf("Enter Size of the list: ");
    scanf("%d", &n);
    head = create_list(n);
    printf("\nList from front:");
    display_frontlist(head);
    printf("\nList from rear:");
    display_rearlist(head);
    return 0;
}
