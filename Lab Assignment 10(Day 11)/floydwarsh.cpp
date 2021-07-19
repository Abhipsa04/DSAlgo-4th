#include <iostream>
#include <climits>
#include <iomanip>
#include<fstream>
using namespace std;
 
// Total number of vertices in the  graph`
int N;
int graph[100][100];
int cost[100][100];
int path[100][100];
 
// Define infinity
#define I INT_MAX
 
// Recursive function to print path of given
// vertex `u` from source vertex `v`
void printPath( int v, int u)
{
    if (path[v][u] == v) {
        return;
    }
 
    printPath( v, path[v][u]);
    cout << path[v][u] << " ";
}
 
// Function to print the shortest cost with path
// information between all pairs of vertices
void printSolution()
{
    for (int v = 1; v <= N; v++)
    {
        for (int u = 1; u <= N; u++)
        {
            if (u != v && path[v][u] != -1)
            {
                cout << "The shortest path from " << v << "-->" << u << " is ("
                    << v << " ";
                printPath( v, u);
                cout << u << ")" << endl;
            }
        }
    }
}
 
// Function to run the Floyd–Warshall algorithm
void floydWarshall()
{
    // `cost[]` and `parent[]` stores shortest path
    // (shortest-cost/shortest route) information
   // int cost[N][N], path[N][N];
 
    // initialize `cost[]` and `parent[]`
    for (int v = 1; v <= N; v++)
    {
        for (int u = 1; u <= N; u++)
        {
            // initially, cost would be the same as the weight of the edge
            cost[v][u] = graph[v][u];
 
            if (v == u) {
                path[v][u] = 0;
            }
            else if (cost[v][u] != INT_MAX) {
                path[v][u] = v;
            }
            else {
                path[v][u] = -1;
            }
        }
    }
 
    // run Floyd–Warshall
    for (int k = 1; k <= N; k++)
    {
        for (int v = 1; v <= N; v++)
        {
            for (int u = 1; u <= N; u++)
            {
                // If vertex `k` is on the shortest path from `v` to `u`,
                // then update the value of `cost[v][u]` and `path[v][u]`
 
                if (cost[v][k] != INT_MAX && cost[k][u] != INT_MAX
                    && cost[v][k] + cost[k][u] < cost[v][u])
                {
                    cost[v][u] = cost[v][k] + cost[k][u];
                    path[v][u] = path[k][u];
                }
            }
 
            // if diagonal elements become negative, the
            // graph contains a negative-weight cycle
            if (cost[v][v] < 0)
            {
                cout << "Negative-weight cycle found!!";
                return;
            }
        }
    }
 
    // Print the shortest path between all pairs of vertices
    printSolution();
}
 
int main()
{
    // given adjacency representation of the matrix
	fstream infile;
	infile.open("warsh.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}
	
	infile>>N;
	


	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			infile>>graph[i][j];
		}
	}


	cout<<"The input graph is"<<endl;
	for(int i=1 ; i<=N ; ++i)
	{
		for(int j=1 ; j<=N ; ++j)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
    // Run Floyd–Warshall algorithm
    floydWarshall();
    cout<<"The Output matrix is: "<<endl;
	for(int i=1 ; i<=N ; ++i)
      	{
     			for(int j=1 ; j<=N ; ++j)
     			{
     				if(cost[i][j]==999)
     					cout<<"INF"<<"\t";
     				else cout<<cost[i][j]<<"\t";
     			}
     			cout<<endl;
      	}
 
    return 0;
}