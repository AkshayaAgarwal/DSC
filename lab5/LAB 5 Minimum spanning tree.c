#include<stdio.h>
#include<stdlib.h>

int check(char input[]){
   int i = 0;
    while (input[i] != '\0') {
        if (!isdigit(input[i])) {
         return 0;
        }
        i++;
    }
    return 1;
}

void printMST(int parent[10], int n, int arr[10][10]){
	printf("\n\n   Edge  Weight\n");
	int i,min_Cost=0;
	for(i=2;i<=n;i++){
		printf("%d. %d - %d  %d\n",i-1,parent[i],i,arr[i][parent[i]]);
		min_Cost+=arr[i][parent[i]];
	}
	printf("\n\n The minimised cost acquired through minimum spanning tree is %d\n\n",min_Cost);
}

int minKey(int key[10],int visited[10],int n){
	
	int v;
	int min=INT_MAX,min_index;
	for(v=1;v<=n;v++){
		if(visited[v]==0 && key[v]<min){
			min=key[v];
			min_index=v;
		}
	}
	return min_index;
}



void primMST(int n,int arr[10][10]){
	int parent[n],key[n];
	int visited[n];
	
	int i,j,count;
	
	for(i=1;i<=n;i++){
		visited[i]=0;
		key[i]=INT_MAX;
	}
	
	key[1]=0;
	parent[1]=-1;
	
	for(count=1;count<=n-1;count++){
		int u = minKey(key,visited,n);
		visited[u]=1;
		int v;
		for(v=1;v<=n;v++){
			if(arr[u][v]!=0 && visited[v]==0 && arr[u][v]<key[v]){
				parent[v]=u;
				key[v]=arr[u][v];
			}
		}
	}
	printMST(parent,n,arr);
}
 

//Adjacency matrix
void adjMatrix (int arr[10][10] , int n);

void main() {
	
	int choice,arr[10][10];
	char input[20];
	
	do{ 
	    main :
	    fflush(stdin);
	    system("cls");
		printf("\nPress 1 to for working with minimum spanning tree\n");
		printf("\nPress 2 to go back to the world!\n");
		label1:
		printf("\nEnter your choice (1/2) : ");
		scanf("%s",&input);
		
		if(check(input)){
			choice = atoi(input);
		}
		else{
			printf("\nWrong Input! Please choose the correct input\n");
			sleep(1);
			goto label1;
		}
		
		
		  if(choice==1){
		  	   int count=0,n;

		       do{     
		               system("cls");
		               printf("\n Press 1 to input the values/graph ");
//					   printf("\n Press 2 to display the adjaceny matrix");
					   printf("\n Press 2 to display the minimum spanning tree");
					   printf("\n Press 3 to return to the main menu");
					   subchoice :
					   printf("\n\n Enter your choice (1/2/3) : ");
					   scanf("%d",&choice);
					   
					   if(choice==1){
					   	
					   	  count++;
					   	  label4:
					   	  fflush(stdin);
					   	  printf("\n Enter the number of nodes : ");
					   	  		scanf("%s",&input);
								if(check(input)){
		                    	n = atoi(input);
		                        }
		                else{
			                 printf("\nWrong Input!!\n");
		                   	sleep(1);
			                 goto label4;
	                      	}
						
//					   	  int arr[n][n];
					   	  adjMatrix(arr,n);
					   	
					   	
					   }
					   else if(choice==2){
					   	if(count==0){
					   		printf("\n Input the graph to print the values ");
						   }
						else{

							primMST(n,arr);
						}
					   }

					   else if(choice==3){
					   	printf("\n Redirecting to the main menu.");
					   	sleep(1);
					   	goto main;
					  }
					  else{
					  	printf("\n Wrong input  ");
					  	sleep(1);
					  	goto subchoice;
					  }
					  printf("\n Do you want to return to the submenu press 1: ");
					  scanf("%d",&choice);
			 }while(choice==1);
		  	 
		  }
		  else if(choice==2){
		  	printf("\n Exiting from the program!! ");
		  }
		  else{
		  	printf("\n Wrong Input! \n");
		  	sleep(2);
		  	goto label1;
		  }
		  _continue :
		  fflush(stdin);
		  printf("\n Do you want to continue if yes press 1\n");
		  	if(check(input)){
			choice = atoi(input);
		  }
		else{
			printf("\nWrong Input  \n");
			sleep(2);
			goto _continue;
		}
		  scanf("%d",&choice);

		
	}while(choice==1);
}


void adjMatrix (int arr[10][10] , int n){
	int i=0,j=0,max_edges = n * (n-1),origin,destin,weight;
	
	for(i=1;i<=n;i++)
	 for(j=1;j<=n;j++)
	   arr[i][j]=0;
	
	    for (i = 1; i <=(max_edges-n); i++) {
        printf("\n Enter edge %d( 0 0 ) to quit : ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin <= 0 || destin <= 0) {
            printf("Invalid edge!\n");
            i--;
        }else if(arr[origin][destin]!=0){
        	printf("\n Already assigned the edge! \n");
        	i--;
		}
		else if(origin==destin){
			printf("\n Invalid edge as this edge is a loop!\n");
			i--;
		}
		 else{
        	
        	printf("\n Enter the weight for the edge : ");
        	scanf("%d",&weight);
        	arr[origin][destin] = weight;
            arr[destin][origin] = weight;
		}
    }
    printf("\n The adjacency matrix showing the weights of the edges is given below : \n\n  ");
    for(i=1;i<=n;i++)
      printf(" %d",i);
      printf("\n");
    for(i=1;i<=n;i++){
    	printf("\n%d ",i);
    	for(j=1;j<=n;j++){
    		printf(" %d",arr[i][j]);
		}
	}
	printf("\n\n The adjacency matrix showing the edges is given below (where 1 represents the presence of an edge) : \n\n  ");
	    for(i=1;i<=n;i++)
      printf(" %d",i);
      printf("\n");
	    for(i=1;i<=n;i++){
    	printf("\n%d ",i);
    	for(j=1;j<=n;j++){
    		if(arr[i][j]!=0)
    		printf(" 1");
    		else
    		printf(" 0");
		}
	}
}
	

