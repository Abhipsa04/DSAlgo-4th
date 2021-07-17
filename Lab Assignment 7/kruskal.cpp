#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
int graph[100][100];
int graph_res[100][100]={0};
int res_size=0;
int set1[100];


int n;//number of vertices
int ans=0;
struct kruskal
{
	char u;//src edge
	char v;//dest edge
	int weight;//weight
};
kruskal  res[100];

int find(int i)
{	//cout<<"find passed index: "<<i<<endl;
	while(set1[i]>0)
		i=set1[i];
	//cout<<"find returned index: "<<i<<endl;
	return i;
}
void weighted_union(int i , int j)// Adding the edges of graph
{
	//cout<<"passed i j : "<<i<<" "<<j<<endl;
	int indx1=find(i) , indx2=find(j);
	i=indx1 , j=indx2;
	//cout<<indx1<<" "<<indx2<<endl;
	int temp=set1[i]+set1[j];
	//cout<<"temp :"<<temp<<endl;
	//cout<<set1[i]<<endl;
	//cout<<set1[j]<<endl;
	if(set1[i]>set1[j])
	{
		set1[i]=j;
		set1[j]=temp;
		//cout<<"inside changed set1"<<"["<<i<<"]"<<set1[i]<<endl;
		//cout<<"inside changed set1"<<"["<<j<<"]"<<set1[j]<<endl;
	}
	else
	{
		set1[j]=i;
		set1[i]=temp;
		//cout<<"inside changed set1"<<"["<<i<<"]"<<set1[i]<<endl;
		//cout<<"inside changed set1"<<"["<<j<<"]"<<set1[j];
		//cout<<endl;
	}
	/*for(int i=0;i<n;i++){
		cout<<set1[i]<<" ";
	}
	cout<<endl;*/
}
bool compare(kruskal x, kruskal y){
	return x.weight<y.weight;
}
void MST_kruskal(kruskal a[] , int size)
{
	for(int i=0 ; i<n ; ++i)
		set1[i]=-1;
	
    sort(a,a+size,compare);
	/*for(int i=0;i<size;i++)
	{
		cout<<a[i].u<<" ";
		cout<<a[i].v<<endl;
	}*/
	int k=0;
	for(int i=0 ; i<size ; ++i)
	{
		//cout<<a[i].u<<" ";
		//cout<<a[i].v<<endl;
		if(find(a[i].u-'A')!=find(a[i].v-'A'))
		{	
			cout<<a[i].u<<"->"<<a[i].v<<"->"<<a[i].weight<<endl;
			
			ans+=a[i].weight;
			res[res_size].u=a[i].u;
			res[res_size].v=a[i].v;
			res[res_size].weight=a[i].weight;
			++res_size;
			weighted_union(a[i].u-'A' , a[i].v-'A');
		}


	}
}
int main()
{
	fstream infile;
	infile.open("graph.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}
	
	infile>>n;//number of vertices
	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<n ; ++j)
		{
			infile>>graph[i][j];
		}
	}
	int k=0;
	kruskal graph_pair[100];
	cout<<"The input graph is"<<endl;
	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<n ; ++j)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
// Storing the graph in graph_pair
	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<=i ; ++j)
		{
			if(graph[i][j]) // if there is an edge between
			{
				graph_pair[k].u=i+'A';
				graph_pair[k].v=j+'A';
				graph_pair[k].weight=graph[i][j];
				++k;
			}
		}
	}
	
	
	int size=k;
	MST_kruskal(graph_pair , size);//passing graph to kruskal
	cout<<"Total weight"<< " "<<ans<<endl;//ans is defined globally and counts the total weight
	for(int i=0 ; i<res_size ; ++i)//the output graph is stored in graph_res
	{
		graph_res[res[i].u-'A'][res[i].v-'A']=res[i].weight;//printing the selected edges and corrresponding weight

	}
	cout<<"The output graph is"<<endl;//printing the adjacency matrix of output graph
	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<n ; ++j)
		{
			cout<<graph_res[i][j]<<" ";
		}
		cout<<endl;
	}
	

}