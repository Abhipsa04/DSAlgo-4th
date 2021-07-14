#include<iostream>
#include<fstream>
#include<strings.h>
#include "queueclass.cpp"
using namespace std;
int v;
int mat[10][10];
int vis[20]={0};
void BFS(int x){
    Lin_Queue q;
    vis[x]=1;
    q.insert(x);
    while(!q.isEmpty()){
        int u=q.del();
        cout<<u<<" ";
        
        for(int k=0;k<v;k++)
        {
        
            if(mat[u][k]==1)
            {  
                
                if(vis[k]==0)
                {
                    
                    vis[k]=1;
                    q.insert(k);
                    
                }
            }
        }
    }

}
int main(){
    fstream infile;
    infile.open("file1.txt",ios::in);
    if(!infile){
        cout<<"Error opening File \n";
        exit(0);

    }
    infile>>v;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            infile>>mat[i][j];
        }
    }
    cout<<endl;
    cout<<"The Graph is : \n";
    for(int i=0;i<v;i++)
    {
        cout<<i<<"-->";
        for(int j=0;j<v;j++){
            if(mat[i][j])
             cout<<j<<"-->";
        }
        cout<<endl;
    }
    
    int z;
    cout<<"Enter the root ";
    cin>>z;
    cout<<"BFS : \n";
    BFS(z);
    return 0;
}