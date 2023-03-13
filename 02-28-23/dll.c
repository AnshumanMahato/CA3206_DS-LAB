#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
} node;

node *create_node()
{
    int val;
    node *newnode = (node *)malloc(sizeof(node));
    printf("\nEnter node value:");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = newnode->prev = NULL;
    return newnode;
}

node *start = NULL;
int nodes = 0;

void insert_first()
{
    node *newnode = create_node();
    if (!start)
        start = newnode;
    else
    {
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
}

void insert_last()
{

    node *ptr, *newnode = create_node();
    if (!start)
        start = newnode;
    else
    {
        ptr = start;
        while (ptr->next)
            ptr = ptr->next;
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

void insert_mid()
{
    int i, pos;
    node *ptr, *newnode = create_node();
    printf("Enter Postion for new node:");
    scanf("%d", &pos);
    if (!start)
        start = newnode;
    else
    {
        i = 0;
        ptr = start;
        while (i < pos)
        {
            ptr = ptr->next;
            i++;
        }
        newnode->next = ptr;
        newnode->prev = ptr->prev;
        ptr->prev->next = newnode;
        ptr->prev = newnode;
    }
}

void delete_first()
{
    node *temp;
    if (!start)
        printf("List is empty");
    else
    {
        temp = start;
        start = start->next;
        free(temp);
    }
}
void delete_last()
{
    node *temp;
    if (!start)
        printf("List is empty");
    else
    {
        temp = start;
        while (temp->next)
            temp = temp->next;
        temp->prev->next = NULL;
        free(temp);
    }
}
void delete_mid()
{
    int i, pos;
    node *temp;
    if (!start)
        printf("List is empty");
    else
    {
        printf("Enter postion to be deleted:");
        scanf("%d", &pos);
        i = 0;
        temp = start;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void display_frontlist()
{
    node *temp = start;
    printf("\nList from front:");
    if (!start)
        printf("List is empty");
    else
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
}

void display_rearlist()
{
    node *temp = start;
    printf("\nList from rear:");
    if (!start)
        printf("List is empty");
    else
    {
        while (temp->next)
            temp = temp->next;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
    }
}

int main()
{
    int ch, val;
    do
    {
        printf("\nDouble Linked List\n");
        printf("1.Insert at first\n");
        printf("2.Insert at last\n");
        printf("3.Insert at mid\n");
        printf("4.Delete at first\n");
        printf("5.Delete at last\n");
        printf("6.Delete at mid\n");
        printf("7.Display from first\n");
        printf("8.Display from last\n");
        printf("9.Exit\n");
        printf("\nEnter Choice(1-9):");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_first();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            insert_mid();
            break;
        case 4:
            delete_first();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            delete_mid();
            break;

        case 7:
            display_frontlist();
            break;
        case 8:
            display_rearlist();
            break;
        case 9:
            printf("Exiting...\n\n");
            break;
        default:
            printf("Invalid Choice\n\n");
        }
    } while (ch != 9);

    return 0;
}