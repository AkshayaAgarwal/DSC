#include<stdio.h>
#include <time.h>
int main(){
	int ch,x,n,i,a[20],pos=0;
	int search(int a[],int n,int x){
		int l,r,mid;
		l=0,r=n-1;
		
		while(l<=r){
			mid= (l+r)/2;
			if (x==a[mid]){
				return mid;
			}
			else if (x<a[mid]){
				r = mid-1;
			}
			else {
				l=mid+1;
			}
		}
		return -1;
		
	}
    
    while(1){
	printf("\n!!!!!!!!!!!!!!!!!!!!!");
    printf("\n1- To enter random numbers in array\n");
    printf("2- Display the array\n");
    printf("3- Search the number\n");
    printf("4- Want to go, choose this option\n");
    printf("Enter Choice\n");
    printf("!!!!!!!!!!!!!!!!!!!!\n");
    
        while (scanf("%d", &ch) != 1) {
            printf("Incorrect choice. Enter an integer number. \n");        
            while (getchar() != '\n');
        }
         
    printf("--------------------------------------\n");
    switch(ch){
    	case 1:
			   printf("Enter the size of array::");
			   scanf("%d",&n);	
			   //int a[n],i;
			   for(i=0;i<n;i++)
			     a[i]=rand()%100;   //Generate number between 0 to 99
			
			   printf("\nElements of the array::");
			   for(i=0;i<n;i++)
			   {
			     printf("\nElement number %d::%d",i+1,a[i]);
			   }
	    	break;
		case 2:
	    	printf("Elements are \n");
	        for(i =0;i<n;i++){
	    	printf("%d ",a[i]);}
	    	break;
	    case 3:
	    	printf("what do you want to search search\n");
	    	scanf("%d",&x);
	    	pos = search(a,n,x);
	    	if (pos==-1){
	    		printf("Not found");
			}
			else{
				printf("The elements is %d and the position is %d",a[pos],pos+1);
				
			}
			break;
		case 4:exit(0);
		default:
			printf("Wrong choice ");
	    	
}
}
return 0;
}

