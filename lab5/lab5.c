#include <stdio.h>
#include <limits.h>
int vertices,edges;
 
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < vertices; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 
int printMST(int parent[], int n, int graph[vertices][vertices]) {
    int i;
    printf("Edge   Weight\n");
    for (i = 1; i < vertices; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
 
void primMST(int graph[vertices][vertices]) {
    int parent[vertices]; 
    int key[vertices], i, v, count; 
    int mstSet[vertices]; 
 
    for (i = 0; i < vertices; i++)
        key[i] = INT_MAX, mstSet[i] = 0;
 
    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
 
        for (v = 0; v < vertices; v++){
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }
    printMST(parent, vertices, graph);  //Printing
}

void main(){
	int i,j;
	printf("Enter No of Vertices : ");
	scanf("%d",&vertices);
	int graph[vertices][vertices];
	printf("Enter Matrix value : \n");
	for(i=0;i<vertices;i++){
		for(j=0;j<vertices;j++){
			scanf("%d",&graph[i][j]);	
		}
	}
	primMST(graph);
}

