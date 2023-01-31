
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int arr[SIZE],front=-1,rear=-1;

void insertVal(int val){
	if((rear+1)%SIZE == front){
		printf("\nQueue is full.");
		return;
	}
		
	if(front == -1)
		front = rear = 0;
	else
		rear = (rear+1)%SIZE;
	arr[rear] = val;
		
}
void deleteVal(){
	if(front == -1){
		printf("\nQueue is empty.");
		return;
	}
	printf("\n%d has been deleted",arr[front]);
	if(front == rear){
		front =-1;
		rear=-1;
	}
	else
		front = (front+1)%SIZE;
}
void traverse(){
	if(front == -1){
		printf("\nQueue is empty.");
		return;
	}
	printf("\nQueue is : ");
	int i =front;
	printf("%d ",arr[i]);
	while(1){
		i=(i+1)%SIZE;
		printf("%d ",arr[i]);
		if(i==rear)
			break;
	}
}
int main(){
	int choice,item;
    while(1)
    {
    	printf("\nQueue Menu\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display all elements of the queue\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Input the elements for adding in queue:");
                   scanf("%d",&item);
                   insertVal(item);
                   break;
            case 2:deleteVal();
                    break;
            case 3:traverse();
                    break;
            case 4:
                    exit(0);
            default:
                    printf("Wrong choice\n");
        }

    }
}
