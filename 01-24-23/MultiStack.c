#include<stdio.h>
#include<stdlib.h>

int *stk,len,top1,top2;

void push(int val,int flag);
int pop(int flag);
void traverse(int flag);

int main(){
	int ch,val;
	printf("Enter full size for the stacks:");
	scanf("%d",&len);
	stk = (int *)malloc(len*sizeof(int));
	top1=-1;
	top2=len;
	do{
		printf("\nStack Menu\n");
		printf("1.Push to stack A \n");
		printf("2.Push to stack B\n");
		printf("3.Pop from stack A\n");
		printf("4.Pop from stack B\n");
		printf("5.Display stack A\n");
		printf("6.Display stack B\n");
		printf("7.Exit\n");
		printf("\nEnter Choice(1-7):");
		scanf("%d",&ch);
		switch(ch){
			case 1: if(top1 + 1 == top2)
						printf("Stack Overflow\n\n");
					else{
						printf("Enter Value to be pushed: ");
						scanf("%d",&val);
						push(val,1);
						printf("\n");
					}break;
			
			case 2: if(top1 + 1 == top2)
						printf("Stack Overflow\n\n");
					else{
						printf("Enter Value to be pushed: ");
						scanf("%d",&val);
						push(val,-1);
						printf("\n");
					}break;
					
			case 3: if(top1 == -1)
						printf("StackA is Empty. Nothing can be popped.\n\n");
					else{
						val = pop(1);
						printf("%d has been popped from stack.\n\n",val);
					}break;
			case 4: if(top2 == len)
						printf("StackB is Empty. Nothing can be popped.\n\n");
					else{
						val = pop(-1);
						printf("%d has been popped from stack.\n\n",val);
					}break;
			case 5: if(top1 == -1)
						printf("StackA is Empty.\n\n");
					else{
						printf("Current StackA is: ");
						traverse(1);
						printf("\n");
					}
					break;
			case 6: if(top2 == len)
						printf("StackB is Empty.\n\n");
					else{
						printf("Current StackB is: ");
						traverse(-1);
						printf("\n");
					}break;
			case 7: printf("Exiting...\n\n");break;
			default:printf("Invalid Choice\n\n");	
			}
		}while(ch!=7);
	
	return 0;
}

void push(int val,int flag){
	if(flag==1)
		stk[++top1] = val;
	else if(flag == -1)
		stk[--top2] = val;
}

int pop(int flag){
	if(flag==1)
		return stk[top1--];
	else if(flag == -1)
		return stk[top2++];
}

void traverse(int flag){
	int i;
	if(flag==1){
		for(i=top1;i>-1;i--)
			printf("%d ",stk[i]);
	}
	else if(flag == -1)
		for(i=top2;i<len;i++)
			printf("%d ",stk[i]);
}
