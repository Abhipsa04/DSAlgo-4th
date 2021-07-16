#include<iostream>
using namespace std;


void heapAdjust(int arr[],int i,int n){
	int key=arr[i];
	//cout<<key<<endl;
	int j=2*i;
	while(j<=n)
	{
		if(j<n && arr[j]<arr[j+1]) j=j+1;
		if(arr[j]<=key) break;
			arr[j/2]=arr[j];
			j=j*2;
	}
	arr[j/2]=key;
}

void heapify(int arr[],int n){
	for(int i=n/2;i>=1;i--)
		heapAdjust(arr,i,n);
}

void heapSort(int arr[],int n)
{
	heapify(arr,n);
	int count=0;
	for(int i=n;i>=2;i--)
	{
		int temp=arr[1];
		arr[1]=arr[i];
		arr[i]=temp;
		
		heapAdjust(arr,1,i-1);
		count++;
		cout<<"pass "<<count<<": ";
		for(int t=1;t<n;t++)
		{
			
			cout<<arr[t]<<" ";
		}
		cout<<endl;
	}
}


int main()
{
	int n;
	cout<<"Enter the number of element: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	heapSort(arr,n);
	cout<<"The sorted array is: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}