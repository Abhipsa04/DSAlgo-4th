#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int x[10];
int mat[10][10];
int cnt=0;


bool place(int k, int i){
	for(int j=1;j<=k-1;j++){
		if(x[j]==i or abs(k-j)==abs(i-x[j]))
			return false;
	}
	return true;
}

void NQueen(int k,int n){
	for(int i=1;i<=n;i++){
		if(place(k,i))
		{
			x[k]=i;
			if(k==n){
				cnt++;
			for(i=1;i<=n;i++)
				cout<<x[i]<<" ";
				cout<<endl;
					}
			else
				NQueen(k+1,n);
		}
		
	}
}

int main(){
	int n;
	cout<<"Enter queens number: ";
	cin>>n;
	
	
	cout<<"The queens position are: "<<endl<<endl;
	NQueen(1,n);
    if(cnt==0){
        cout<<"No possible Positions "<<endl;
    }
	else 
     cout<<"The counts are:"<<cnt<<endl;
	return 0;
}