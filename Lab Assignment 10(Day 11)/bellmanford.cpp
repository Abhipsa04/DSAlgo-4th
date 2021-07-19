#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

struct edge{
	int src,dst,wt;
};
int V;

int graph[1000][1000];
//int parent[1000];
int dist[1000];
int output[1000][1000]={0};
edge Edges[1000];

bool bellmanFord(int E,int s)
{
	for(int i=0;i<V;i++){
		dist[i] = INT_MAX;
		//parent[i] = -1;
	}

	dist[s]=0;
	for(int i=1;i<=V-1;++i)// or i=0 to i<=v
	{
		for(int j=0;j<E;++j)
		{
			edge x = Edges[j];
			if(dist[x.src]!=INT_MAX && dist[x.src]+graph[x.src][x.dst]<dist[x.dst])
			{
				dist[x.dst]=dist[x.src]+graph[x.src][x.dst];
				//parent[x.dst]=x.src;
			}
		}
	}

    // Check if there is a negative weight cycle 
	for(int i=0 ; i<=E ; ++i)
	{
		edge x = Edges[i];
		if(dist[x.src]+graph[x.src][x.dst]<dist[x.dst]) return false;
	}
	return true;
		
}

int main()
{
	fstream infile;
	infile.open("bell.txt" , ios::in);
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
      cout<<"Input graph is"<<endl;
      int E=0;
      for(int i=0 ; i<V ; ++i)
      {
            for(int j=0 ; j<V ; ++j)
            {
            		if(graph[i][j])
            		{
            			Edges[E].src=i;
            			Edges[E].dst=j;
            			E++;
            		}
                  cout<<graph[i][j]<<" ";
            }
            cout<<endl;
      }
      cout<<"Number of edges"<<endl;
      cout<<E<<endl;
      cout<<"Edge list is"<<endl;
      for(int i=0 ; i<E ; ++i)
      {
      	cout<<(Edges[i].src)<<"->"<<(Edges[i].dst)<<endl;
        
      }
    cout<<"Shortest Path : "<<endl;
    // int s;
    // cout<<"Enter the source vertext"<<endl;
    // cin>>s;
    if(bellmanFord(E-1 , 0))
    {
    	for(int i=0 ; i<V ; ++i)
	    {
	    	if(i!=0){
             static char name ='A';
	         cout<<char(0+'S')<<"->"<<dist[i]<<"->"<<char(name)<<endl;
             name++;
             }
            else
              cout<<char(0+'S')<<"->"<<dist[i]<<"->"<<char('S')<<endl;  
	    }

    }
    else
    {
    	cout<<"Negative cycle is present"<<endl;
    }
}