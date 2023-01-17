#include<stdio.h>
#include<stdlib.h>

int main(){
	int *a,n,i,j,temp;
	printf("Enter Size of array: ");
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(int));
	printf("Enter %d values in array: ",n);
	for(i = 0; i< n; i++){
		scanf("%d",a+i);
	}
	
	printf("Array before sorting: ");
	for(i = 0; i< n; i++){
		printf("%d ",*(a+i));
	}
	
	//Bubble Sorting
	
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(*(a+j) > *(a+j+1)){
				temp = *(a+j);
				*(a+j) = *(a+j+1);
				*(a+j+1) = temp;
			}
		}
	}
	
	printf("\n\nArray after sorting: ");
	for(i = 0; i< n; i++){
		printf("%d ",*(a+i));
	}
}
