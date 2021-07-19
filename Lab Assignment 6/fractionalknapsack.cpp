#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Item{
    public:
    int value;
    int weight;
    int ratio;
};
void merge(Item a[] , int l , int mid , int r , int n){
    int i=l , j=mid+1 , k=l ,  t=1;
    Item z[r+1];
    while( i<=mid && j<=r){
        if(a[i].ratio>=a[j].ratio)
            z[k++]=a[i++];
        else
            z[k++]=a[j++];
        }
    while(i<=mid) z[k++]=a[i++];
    while(j<=r) z[k++]=a[j++];
    
    for(int i=l ; i<=r ; ++i)
        a[i]=z[i];
}
void merge_sort(Item a[] , int l , int r , int n){
    int mid ;
    static int t=1;
    if(l<r){
         mid=(l+r)/2;
        merge_sort(a , l , mid , n);
        merge_sort(a , mid+1 , r , n);
        merge(a , l , mid , r , n);
       

}
}
/*bool compare(Item a, Item b){
    double x = (double)a.value/(double)a.weight;
    double y = (double)b.value/(double)b.weight;
    return x > y;
}*/

void fractionalKnapsack(int W, Item arr[], int n){
    merge_sort(arr,0,n-1,n);
    //sort(arr,arr+n,compare);
    cout<<"Weight"<<" "<<"Profit"<<endl;
    for(int j=0;j<n;j++){
        
        cout<<arr[j].weight<<" \t"<<arr[j].value<<endl;
    }
    int s=0;
    double ans=0.0;
    int i;
    for(i=0;i<n;i++){
        if(s + arr[i].weight <= W){
            ans = ans + arr[i].value;
            s = s + arr[i].weight;
        }
        else{
            break;
        }
    }
    
    if(i<=n-1){
        int x = W-s;
        ans = ans + ((double)x/(double)arr[i].weight*arr[i].value);
    }
    

    cout<<"The Maximum Profit is: "<<ans<<endl;
}

int main(){
    cout<<"Enter the number of element you want to enter: ";
    int n;
    int W;
    cin>>n;
    cout<<"Enter the KnapSack weight: ";
    cin>>W;
    Item arr[n];
    cout<<"Enter the profits: ";
    for(int i=0; i<n; i++){
        cin>>arr[i].value;
    }
    cout<<"Enter the Weights: ";
    for(int i=0;i<n;i++){
        cin>>arr[i].weight;
    }
    for(int i=0 ; i<n ; ++i)
    {
        arr[i].ratio=arr[i].value/arr[i].weight;
        
    }
    fractionalKnapsack(W,arr,n);
    cout<<endl;
    return 0;
}