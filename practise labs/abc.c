#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int n;
   printf("Enter the size of array::");
   scanf("%d",&n);
   int a[n],i;
   for(i=0;i<n;i++)
     a[i]=rand()%100;   //Generate number between 0 to 99

   printf("\nElements of the array::");
   for(i=0;i<n;i++)
   {
     printf("\nElement number %d::%d",i+1,a[i]);
   }
   return 0;
}
