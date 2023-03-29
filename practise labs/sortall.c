#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
	void bubblesort(int a[],int n)
	{
		int i=0,j=0,k,temp;
		
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(a[j]>a[j+1])
				{
					temp=a[j+1];
					a[j+1]=a[j];
					a[j]=temp;
				}
			}
			printf("\nValues after pass %d\n",i);
			for(k = 0; k<n; k++)
			printf("%d",a[k]);
		    
		}
	}
void printarray(int a[], int n)
{
int i;
for (i = 0; i < n; i++)
printf("%d ", a[i]);
printf("\n");
}
	void selectionsort(int a[], int n)
	{
		int i=0,j=0,k,temp;
		int min = a[0];
		for(i=0;i<n-1;i++)
		{
		for(j=i+1;j<n+1;j++)
		{
			 
			if(a[i]>a[j])
			{
				
			}
		}
	}
}
void main()
	{
		int ch,a[10],n,pos=0,i,j;
		while(1){
	printf("\n!!!!!!!!!!!!!!!!!!!!!");
    printf("\n1- Tell the size \n");
    printf("2- display elements before sort of array\n");
    printf("3- Sort using bubble sort\n");
    printf("4.Sort using selection sort\n");
    printf("5- Print array\n");
    printf("6- Want to go, choose this option\n");
    printf("Enter Choice\n");
    printf("!!!!!!!!!!!!!!!!!!!!\n");
		
		 while (scanf("%d", &ch) != 1) {
            printf("Incorrect choice. Enter an integer number. \n");        
            while (getchar() != '\n');
        }
		//printf("\n!!!!!!!!!!!");
	switch(ch){
			case 1:
				printf("enter the size of the array\n");
				scanf("%d", &n);
				for(i=0;i<n;i++)
				{
				printf("enter the elements for a[%d]\n", i);
				scanf("%d", &a[i]);					
				}
				break;
			case 2:
				printf("Elements are \n");
			        for(i =0;i<n;i++){
			    	printf("%d ",a[i]);}
			    	break;
			case 3:
				bubblesort(a,n);
				break;
			case 4: selectionsort(a,n);
			break;
			case 5: printarray(a,n);
			break;
			case 6:exit(0);
		default:
			printf("Wrong choice ");
	}
//return 0;
}
}


