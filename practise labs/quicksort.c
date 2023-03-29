#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[20];
int n;
int random() {
    int i=0;
    printf("\nEnter the range of the array\n");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        a[i]=rand()%100; 
    }
    printf("\nThe elements of array are\n");
    for(i=0; i<n; i++) {
        printf("\nThe elements at a[%d] = %d", i,a[i]);
    }
    return n;
}
int manual() {
    int i=0;
    printf("\nEnter the length of array\n");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        printf("\nEnter the element for a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    printf("\nThe elements your entered are\n");
    for(i=0; i<n; i++) {
        printf("\nThe elements at a[%d] = %d", i,a[i]);
    }
    return n;
}
void quicksort(int a[], l,r){
	if(r-l<=)
}
void printarray(int a[], int n)
{
int i;
for (i = 0; i < n; i++)
printf("%d ", a[i]);
printf("\n");
}
int main() {
    int n,i,j,k,ch;
    while(1) {
        printf("\nPlease select your choice from the options below\n");
        printf("\n1.Enter the input randomly.\n2.Enter the input manually\n3.Print the sorted array.\n4.Print the array\n5.Exit\n");
        while (scanf("%d", &ch) != 1) {
            printf("Incorrect choice. Enter an integer number.\n");        
            while (getchar() != '\n');
        }
        printf("--------------------------------------\n");
        switch(ch) {
            case 1:
                n=random();
                break;
            case 2:
 				n=manual();
 				break;
 			case 3:
 				break;
 			case 4: printarray(a,n);
 				break;
 			case 5:exit(0);
			default:
			printf("Wrong choice");
	    	
		 }	
	 }
}

