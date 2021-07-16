
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Item{
    public:
    int value;
    int weight;
};

bool compare(Item *a, Item *b){
    double x = (double)a->value/(double)a->weight;
    double y = (double)b->value/(double)b->weight;
    return x > y;
}

void fractionalKnapsack(int W, Item* arr[], int n){
    
    sort(arr,arr+n,compare);
    cout<<"Weight"<<" "<<"Profit"<<endl;
    for(int j=0;j<n;j++){
        cout<<arr[j]->weight<<" "<<arr[j]->value<<endl;
    }
    int s=0;
    double ans=0.0;
    int i;
    for(i=0;i<n;i++){
        if(s + arr[i]->weight <= W){
            ans = ans + arr[i]->value;
            s = s + arr[i]->weight;
        }
        else{
            break;
        }
    }
    
    if(i<=n-1){
        int x = W-s;
        ans = ans + ((double)x/(double)arr[i]->weight*arr[i]->value);
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
    Item *arr[n];
    
    for(int i=0; i<n; i++){
        arr[i]=(Item*)malloc(sizeof(struct Item));
        cout<<"Enter the profits: ";
        cin>>arr[i]->value;
        cout<<"Enter the Weights: ";
        cin>>arr[i]->weight;
    }
    
    for(int i=0;i<n;i++){
        
    }
    fractionalKnapsack(W,arr,n);
    cout<<endl;
    return 0;
}