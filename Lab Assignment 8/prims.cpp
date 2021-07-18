#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int V;
int graph[100][100];
int graph_res[100][100]={0};
int ans=0;

int minKey(int key[], bool mstSet[]){
    int min= INT_MAX, min_index;
	
	//cout<<endl;
	/*for(int i=0;i<V;i++){
		cout<<key[i]<<" ";
	}*/
	//cout<<endl;
    for (int i = 0; i < V; i++)
		
        if (mstSet[i] == false && key[i] < min) 
			
            min = key[i], min_index = i; 
			//cout<<"min : "<<min<<endl;
	  
    return min_index;
}

void print(int parent[]){
    for(int i=1;i<V;i++){
        cout<<char(parent[i]+65)<<" - "<<char(i+65)<<" \t"<<graph[i][parent[i]]<<endl;
		ans+=graph[i][parent[i]];
    }
}

void primsAlgo(){
    int parent[V];
    int key[V];
    bool mstSet[V];
    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    parent[0]=-1;
    key[0]=0;
    for(int i=0;i<V-1;i++){
		
        int u=minKey(key,mstSet);
		//cout<<"u is : "<<u<<endl;
        mstSet[u]=true;
        for(int j=0;j<V;j++){
            if(graph[u][j] && mstSet[j]==false && graph[u][j]<key[j]){
                parent[j]=u;
                key[j]=graph[u][j];
				
				
				//cout<<key[j];
				//cout<<endl;
				
            }
			
        }

    }
    print(parent);
	cout<<endl;
	for(int k=1;k<V;k++){
		
		graph_res[parent[k]][k]=graph[k][parent[k]];
		graph_res[k][parent[k]]=graph[k][parent[k]];
		//cout<<endl;
		
	}
	cout<<endl;
}
int main(){
    
    fstream infile;
	infile.open("graphprim.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}
	
	infile>>V;
	for(int i=0 ; i<V ; ++i)
	{
		for(int j=0 ; j<V ; ++j)
		{
			infile>>graph[i][j];
		}
	}
	
	cout<<endl;
	cout<<"The Input Graph is: "<<endl;
	for(int i=0 ; i<V ; ++i)
	{
		for(int j=0 ; j<V ; ++j)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	primsAlgo();
	cout<<"the weight is : "<<ans<<endl;
	cout<<"The Output Graph is: "<<endl;
	for(int i=0 ; i<V ; ++i)
	{
		for(int j=0 ; j<V ; ++j)
		{
			cout<<graph_res[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
    
    
}