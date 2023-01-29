#include<iostream>

using namespace std;

int size,top=-1,*stk;

void push(int);
int pop();
void traverse();

int main(){
	cout<<"Enter the size of stack:";
	cin>>size;
	stk = new int[size];
	int ch;
	do{
		cout<<"Stack Menu";
		cout<<"\n1 Push Value";
		cout<<"\n2 Pop Value";
		cout<<"\n3 Show Stack";
		cout<<"\n4 Peek Top Value";
		cout<<"\n5 Exit";
		cout<<"\n\nEnter Choice: ";
		cin>>ch;
		switch(ch){
			case 1: if(top == size-1)
						cout<<"Stack Overflow\n\n";
					else{
						int val;
						cout<<"Enter Value to be pushed: ";
						cin>>val;
						push(val);
						cout<<'\n';
					}break;
					
			case 2: if(top == -1)
						cout<<"Stack is Empty. Nothing can be popped.\n\n";
					else{
						int val = pop();
						cout<<val<< " has been popped from stack.\n\n";
					}break;
			case 3: if(top == -1)
						cout<<"Stack is Empty.\n\n";
					else{
						cout<<"Current Stack is: ";
						traverse();
						cout<<"\n";
					}
					break;
			case 4: if(top == -1)
						cout<<"Stack is Empty.\n\n";
					else
						cout<<"Top value is "<<stk[top]<<"\n\n";
					break;
			case 5: cout<<"Exiting...\n\n";break;
			default:cout<<"Invalid Choice\n\n";
		}
	}while(ch!=5);
	return 0;
}

void push(int val){
	stk[++top] = val;
}

int pop(){
	return stk[top--];
}

void traverse(){
	int i=top;
	while(i!=-1){
		cout<<stk[i--]<<' ';
	}
	cout<<'\n';
}
