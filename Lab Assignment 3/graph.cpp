#include<iostream>
#include <fstream>
#include<string>
using namespace std;

int main () {
	fstream infile; //create aa object of fstream class
	infile.open("fileex.txt", ios::in); //open a file in read mode


	if (!infile) { //to check whether the file is opened
	cout<<"\nError to open the file\n"<<endl;
	exit (1);
	}
	int n;
	infile>>n; //to read number of vertices from file
	int mat[10][10];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			infile>>mat[i][j]; //read a graph from file
		}
	}
	
	int e=0;
    for(int i =0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
            if(mat[i][j]) ++e;
    }
	cout<< "Tolal no. of edges "<<e/2<<endl;
    cout<< "Tolal no. of degree "<<e<<endl;
	
	char c;
    cout<<" Enter the vertex" <<endl;
    cin>>c;
    int v;
    if(c=='A')
        v=0;
    else if (c=='B')
        v=1;
    else if (c=='C')
        v=2;
    else if(c=='D')
        v=3;
    else
        cout<<"Does not Exist";
    for(int i=0 ; i<n ; ++i)
    {
        if(mat[v][i]) {
            switch (i)
            {
            case 0 :
                cout<<"A"<<" ";
                break;
            case 1 :
                cout<<"B"<<" ";
                break;
            case 2 :
                cout<<"C"<<" ";
                break;
            case 3 :
                cout<<"D"<<" ";
                break;
            default:
                cout<<"not Adjacent to any";
                break;
            }
        }
    }
	
	cout<<endl;
     cout<< "The graph is"<<endl;
     for(int i =0 ; i<n ; ++i)
     {
           cout<<i<<"--";
           for(int j=0 ; j<n ; ++j)
            {
                  if(mat[i][j]) cout<<j<<"--";
            }
            cout<<endl;
     }
	cout<<"THE Adjacency Matrix is :"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}

	return 0;
}