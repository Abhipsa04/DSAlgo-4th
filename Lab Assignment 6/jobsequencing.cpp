#include<bits/stdc++.h>
using namespace std;

// define the class for the job
class job
{
	public:
		int jobid;
		int deadline;
		int profit;
};
void merge(job a[] , int l , int mid , int r , int n){
    int i=l , j=mid+1 , k=l ,  t=1;
    job z[r+1];
    while( i<=mid && j<=r){
        if(a[i].profit>=a[j].profit)
            z[k++]=a[i++];
        else
            z[k++]=a[j++];
        }
    while(i<=mid) z[k++]=a[i++];
    while(j<=r) z[k++]=a[j++];
    
    for(int i=l ; i<=r ; ++i)
        a[i]=z[i];
}
void merge_sort(job a[] , int l , int r , int n){
    int mid ;
    static int t=1;
    if(l<r){
         mid=(l+r)/2;
        merge_sort(a , l , mid , n);
        merge_sort(a , mid+1 , r , n);
        merge(a , l , mid , r , n);
       

}
}

// our compare function to sort
/*bool mycompare(job *x,job *y)//boolean function
{
	//sort as per decreasing profit
	return x->profit>y->profit; 
}*/

int maxProfit(job** obj,int n){
	int max=0,profit=0;;
	//find maximum deadline
	for(int i=0;i<n;i++){
		if(i==0){
			max=obj[i]->deadline;
		}
		else{
			if(obj[i]->deadline>max)
				max=obj[i]->deadline;
		}
	}
	merge_sort(*obj,0,n-1,n);
	//sort(obj,obj+n,mycompare);
	// create array of max deadline size
	int store[max]={0};	// empty array initially
	bool slot[max]={false}; //all slots empty initially
	for(int i=0;i<n;i++)
	{	
		// now pick the job with max deadline and from 
		// that deadline traverse array back to find an empty slot
		for(int j=(obj[i]->deadline)-1;j>=0;j--)
		{
			if(slot[j]==false)	// slot is empty
			{	
				// count the total profit
				profit+=obj[i]->profit;
				store[j]=obj[i]->jobid;
				slot[j]=true;
				break;
			}
		}
	}
	// printing the job sequence
	cout<<"jobs sequence is:"<<"\t";
	for(int i=0;i<max;i++)
	{	
		if(slot[i])
			cout<<store[i]<<"  ";
	}
	return profit; //return profit
}

int main()
{	
	int n,size,max,totalprofit=0;
	cout<<"enter the no. of jobs:";
	cin>>n;
	job *obj[n]; //array of pointer to jobs(jobs namely) 
	// user input and finding maximum deadline
	for(int i=0;i<n;i++)
	{	
		obj[i]=(job*)malloc(sizeof(struct job));
		cout<<"enter jobid,deadline and profit of job "<<i+1<<endl;

		cin>>obj[i]->jobid;
		cin>>obj[i]->deadline;
		cin>>obj[i]->profit;
	}

	totalprofit=maxProfit(obj,n); //total profit
	cout<<"\ntotal profit is "<<totalprofit<<"\n";
	
	return 0;	
}