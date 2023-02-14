#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct queue
{
	int q[SIZE];
	int front;
	int rear;
};

void insert(struct queue *q, int val)
{
	if (q->rear == SIZE - 1)
		printf("Queue is full\n");
	else
	{
		if (q->front == -1)
		{
			q->front++;
		}
		q->q[q->rear++] = val;
	}
}

void del(struct queue *q)
{
	int val;
	if (q->front == -1)
		printf("Queue is Empty\n");
	else
	{
		val = q->q[q->front++];
		if (q->front == q->rear)
		{
			q->front = -1;
			q->rear = -1;
		}

		printf("%d is deleted from queue\n", val);
	}
}

void traverse(struct queue *q)
{
	int i;
	if (q->front == -1)
		printf("Queue is Empty\n");
	else
	{
		printf("Queue is :\n");
		i = q->front;
		while (i < q->rear)
		{
			printf("%d ", q->q[i++]);
		}
	}
}

int main()
{
	struct queue *q;
	q = (struct queue *)malloc(sizeof(struct queue));
	q->front = -1;
	q->rear = 0;
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
			printf("Enter Value to be pushed: ");
			scanf("%d", &val);
			insert(q, val);
			printf("\n");
			break;

		case 2:
			del(q);
			break;
		case 3:
			traverse(q);
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
