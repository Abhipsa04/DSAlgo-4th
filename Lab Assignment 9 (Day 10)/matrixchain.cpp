#include<iostream>
#include<fstream>
using namespace std;
int m[100][100];
int s[100][100];

void matrixchainmultiplication(int p[] , int n)
{
	for(int i=1 ; i<n ; ++i)
	{
		m[i][i]=0;
	}
	for(int len=2 ; len<n ; ++len)
	{
		for(int i=1 ; i<n-len+1 ; ++i)
		{
			int j=i+len-1;
			m[i][j]=INT_MAX;
			for(int k=i ; k<=j-1 ; k++)
			{
				int cost=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				m[i][j]=min(cost , m[i][j]);
				s[i][j]=k;
			}
		}
	}
	cout<<m[1][n-1]<<endl;

}
void print_optimal_paranthesis(int i , int j)
{
   // cout<<"s[i][j] :"<<s[i][j]<<" ";
    //cout<<i<<" "<<j<<endl;
	static char name='A';
	if(i==j)
	{
       
		cout<<"A"<<i;
		
	} 
	else
	{
		cout<<'(';
		print_optimal_paranthesis(i , s[i][j]);
        
        
		print_optimal_paranthesis(s[i][j]+1 , j);
		cout<<')';
	}
}
int main()
{
	int n;
	/*fstream infile;
	infile.open("matri.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}
	infile>>n;*/
    cout<<"Enter the total number of Matrices : "<<endl;
    cin>>n;
    n++;
	int  p[n];
	/*for(int i=0 ; i<n ; ++i)
		infile>>p[i];*/
	cout<<"Enter the Valid Dimensions : "<<endl;
    for(int i=0 ; i<n ; ++i)
		cin>>p[i];
    int size=sizeof(p)/sizeof(p[0]);
	
	cout<<"Minimum number of multiplication:"<<endl;
	matrixchainmultiplication(p , size);
	cout<<"optimal paranthesis is"<<endl;
	print_optimal_paranthesis(1 , n-1);
}