
#include<iostream>
#include<limits.h>
#include<fstream>
using namespace std;
 

int s[100][100];
int MatrixChainMultiplication(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
 
    for (i=1; i<n; i++)
        m[i][i] = 0;    
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;  
 
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j]=k;    
                }
            }
        }
    }
 
    return m[1][n-1];   
 
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
    int n,i;
    cout<<"Enter number of matrices\n";
    cin>>n;
   /* fstream infile;
	infile.open("matri.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}
	infile>>n;*/
 
    n++;
 
    int arr[n];
 
    cout<<"Enter dimensions \n";
 
    for(i=0;i<n;i++)
    {
        cout<<"Enter d"<<i<<" :: ";
        cin>>arr[i];
    }
    /*for(int i=0 ; i<n ; ++i)
		infile>>arr[i];*/
    int size = sizeof(arr)/sizeof(arr[0]);
 
    cout<<"Minimum number of multiplications is "<<MatrixChainMultiplication(arr, size)<<endl;
    print_optimal_paranthesis(1,size-1);
 
    return 0;
}