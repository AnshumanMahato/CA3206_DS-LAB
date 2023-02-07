
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int arr[SIZE], front = -1, rear = -1;

void insert_rear(int val)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("\nDeque is full.");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;
    arr[rear] = val;
}

void insert_front(int val)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("\nDeque is full.");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else if (front == 0)
        front = SIZE - 1;
    else
        front--;
    arr[front] = val;
}
void delete_front()
{
    if (front == -1)
    {
        printf("\nDeque is empty.");
        return;
    }
    printf("\n%d has been deleted", arr[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % SIZE;
}
void delete_rear()
{
    if (front == -1)
    {
        printf("\nDeque is empty.");
        return;
    }
    printf("\n%d has been deleted", arr[rear]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = SIZE - 1;
    else
        rear--;
}
void traverse()
{
    if (front == -1)
    {
        printf("\nDeque is empty.");
        return;
    }
    printf("\nDeque is : ");
    int i = front;
    printf("%d ", arr[i]);
    while (1)
    {
        i = (i + 1) % SIZE;
        printf("%d ", arr[i]);
        if (i == rear)
            break;
    }
}
int main()
{
    int choice, item;
    while (1)
    {
        printf("\nDeque Menu\n");
        printf("1.Insert at Front\n");
        printf("2.Insert at Rear\n");
        printf("3.Delete from front\n");
        printf("4.Delete from rear\n");
        printf("5.Display all elements of the Deque\n");
        printf("6.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the elements for adding in Deque:");
            scanf("%d", &item);
            insert_front(item);
            break;
        case 2:
            printf("Input the elements for adding in Deque:");
            scanf("%d", &item);
            insert_rear(item);
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            traverse();
            break;
        case 6:
            printf("\nExiting...");
            exit(0);
        default:
            printf("Wrong choice\n");
        }
    }
}
