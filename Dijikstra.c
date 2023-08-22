#include <stdio.h>
#include <stdlib.h>

int minVal(int arr[], int n, int chk[]){
    int m=0;
    for (int i=0; i<n; i++){
        if ((arr[i]<arr[m] || m==0) && chk[i]==0){
            m=i;
        }
    }
    return m;
}

int main(){
    int n, src;
    char c[100];
    printf("\nEnter number of Nodes: ");
    scanf("%d", &n);
    int adj[100][100];
    int visited[100], dist[100], pred[100];
    int count=1, maxD=0;
    printf("\nEnter Adjacency Matrix(comma seperated values in single line for one row):\n");
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d, ", &adj[i][j]);
            maxD+=adj[i][j];
        }
    }
    printf("\nEnter Source node: ");
    scanf("%d", &src);
    for (int i=0; i<n; i++){
        if (i==src){
            visited[i]=1; //Visited
            dist[i]=0;
            pred[i]=i;
        }
        else{
            visited[i]=0; //Not Visited
            dist[i]=+maxD+1; //Infinity
            pred[i]=-1;  //No predecessor
        }
        
    }
    count=1;
    while (count<=n){
        for (int i=0; i<n; i++){
            if (visited[i]==0 && adj[src][i]!=0){ //Check if node is visited and reachable
                if (dist[src]+adj[src][i]<dist[i]){ 
                    dist[i]=dist[src]+adj[src][i];
                    pred[i]=src;
                }
            }
        }
        
        src=minVal(dist, n, visited); //Getting new source
        visited[src]=1; //Changing visitation status
        count++; 
    }
    printf("\nShortest Path:");
    for (int i=0; i<n; i++){
        printf("\n%d, %d", i, dist[i]);
    }
}