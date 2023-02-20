#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void main()
{ int a[10],i=0,n,f;
	printf("Enter any 3 numbers\n");
	for (i=0;i<3;i++)
	{
		scanf("%d", &a[i]);
	}
	printf("enter the number to be searched\n");
	scanf("%d", &n);
	for(i=0;i<3;i++)
	{
		if(a[i]==n)
		{
			f=1;
			break;
		}
			}
	if(f==1)
	{
		printf("Y\n");
	}
	else{
	printf("N\n");
	}
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		
	int random_number = rand() % 999;
	printf("random_number: %d\n");
	 
	}
}


