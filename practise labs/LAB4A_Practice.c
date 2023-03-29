#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void input(char arr[][10],int n){
    int i;
    for(i = 0;i<n;i++){
        scanf("%s",arr[i]);
    }
}

void search(char arr[],char patt[]){
    int flag = 0,i,j;
    int n = strlen(arr);
    int m = strlen(patt);
    if(strcmp(arr,patt) == 0)
    return;
    for(i = 0; i<=n-m;i++){
        int j;
        for(j = 0;j<m;j++){
            if(arr[i+j]!=patt[j])
            break;
        }
        if(j==m){
            printf("%s is found in %s at index %d\n",patt,arr,i);
            return;
        }
    }
}

void main(){
    int n,m,i,j;
    printf("Enter the number of words you want to give : ");
    scanf("%d",&n);
    char arr[n][10];
    printf("Enter the words now : ");
    input(arr,n);
    printf("[ ");
    for(i = 0; i < n;i++){
        printf("\"%s\"",arr[i]);
        if(i!=n-1)
        printf(" , ");
    }
    printf("]\n");
    printf("Enter the quantity of words to be searched : ");
    scanf("%d",&m);
    char patt[m][10];
    printf("Enter the patterns to search : ");
    input(patt,m);
    printf("[ ");
    for(i = 0; i < m;i++){
        printf("\"%s\"",patt[i]);
        if(i!=m-1)
        printf(" , ");
    }
    printf("]\n");
    for(i = 0;i<n;i++){
        for(j = 0;j<m;j++){
            search(arr[i],patt[j]);
        }
    }
}
