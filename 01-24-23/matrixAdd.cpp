#include<stdio.h>
#include<stdlib.h>

void input(int **mat,int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			scanf("%d",*(mat+i)+j);
		}
	}
}

void print(int **mat,int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%d ",*(*(mat+i)+j));
		}
		printf("\n");
	}
}

void printSum(int **matA,int **matB,int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%d ",*(*(matA+i)+j) + *(*(matB+i)+j));
		}
		printf("\n");
	}
}

int main(){
	int row,col, **a,**b,i,j;
	printf("Enter row and columns for the matrices:");
	scanf("%d%d",&row,&col);
	
	a = (int **)malloc(row*sizeof(int *));
	b = (int **)malloc(row*sizeof(int *));
	
	for(i=0;i<row;i++){
		a[i] = (int *)malloc(sizeof(int)*col);
		b[i] = (int *)malloc(sizeof(int)*col);
	}
	
	printf("Enter values in Matrix A:");
	input(a,row,col);
	
	printf("Enter values in Matrix B:");
	input(b,row,col);
	
	printf("Matrix A\n");
	print(a,row,col);
	
	printf("Matrix B\n");
	print(b,row,col);
	
	printf("Matrix A + Matrix B\n");
	printSum(a,b,row,col);
}
