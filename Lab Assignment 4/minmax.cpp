#include<iostream>
#include<limits.h>
using namespace std;

void MaxAndMin(int arr[],int low,int high,int &max,int &min){
	int max1=max;
	int min1=min;
	if(low==high){
		max=arr[low];
		min=arr[low];
	}
	else if(low==high-1){
		if(arr[low]>=arr[high]){
			max=arr[low];
			min=arr[high];
		}
		else{
			max=arr[high];
			min=arr[low];
		}
	}
	else{
		int mid = (low+high)/2;
		MaxAndMin(arr,low,mid,max,min);
		MaxAndMin(arr,mid+1,high,max1,min1);
		if(max<=max1){
			max=max1;
		}
		if(min>=min1){
			min=min1;
		}
	}	
}

int main(){
	int n;
	cout<<"Enter the limit of the array: "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the Array Elements: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max=INT_MIN;
	int min=INT_MAX;
	MaxAndMin(arr,0,n-1,max,min);
	
	cout<<"The maximum element of the array is: "<<max<<endl;
	cout<<"The minimum element of the array is: "<<min<<endl;
	return 0;
}


