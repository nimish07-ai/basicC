#include <stdio.h>

void makeSet(int n,int parent[],int rank[]){
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=1;
    }

}

int find(int val,int parent[]){
    if(parent[val] != val){
        parent[val]=find(parent[val],parent);
    }
    return parent[val];
}

void unionSet(int val1,int val2,int rank[],int parent[]){
    int p1=find(val1,parent);
    int p2=find(val2,parent);

    if (p1 != p2){

        if (rank[p1] < rank[p2]){
            parent[p1]=p2;
        }else if (rank[p1] > rank[p2]){
            parent[p2]=p1;
        }
        else{
            parent[p2]=p1;
            rank[p1]+=1;
        }

    }
}

void printPR(int parent[],int rank[],int n){
    printf("\nparent");
    for(int i=0;i<n;i++){
        printf(" %d",find(parent[i],parent));
    }
    printf("\n");
    printf("rank  ");
    for(int i=0;i<n;i++){
        printf(" %d",rank[i]);
    }
    printf("\n");
}


void main(){
    int parent[10];
    int rank[10];
    makeSet(10,parent,rank);

    unionSet(1,5,rank,parent);
    unionSet(3,7,rank,parent);
    unionSet(1,4,rank,parent);
    unionSet(5,7,rank,parent);
    unionSet(0,8,rank,parent);
    unionSet(6,9,rank,parent);
    unionSet(3,9,rank,parent);
    printPR(parent,rank,10);

}