#include<iostream>
using namespace std;

void dfs(int G[][6],int start,int n){
    static int visited[7]={0};
    if(visited[start]==0){
        char m=start+'A'-1;
        cout<<m<<" ";
        visited[start]=1;
        for(int j=1;j<n;j++){
            if(G[start][j]==1 && visited[j]==0)
                dfs(G,j,n);
        }
    }
}

int main(){
    int G[6][6]={
        {0,1,1,0,0,0},
        {1,0,0,1,1,0},
        {1,0,0,0,1,0},
        {0,1,0,0,1,1},
        {0,1,1,1,0,1},
        {0,0,0,1,1,0}
        
        };
        int n;
        char ch;
        cout<<"enter the vertix from where u want to start traversal: ";
        cin>>ch;
        n=ch-65+1;
        cout<<"\nDFS traversal: ";
        dfs(G,n,7);
        return 0;
}