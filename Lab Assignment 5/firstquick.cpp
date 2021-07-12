
#include <iostream>

using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int paritition (int arr[],int low,int high)
{
   int pivot = arr[low];
   int  i=low-1;
   int j=high+1;
   while(i<j){
       do{
           i=i+1;
       }while(arr[i]<=pivot);
       do{
           j=j-1;
       }while(arr[j]>pivot);
       if(i<j){
               swap(&arr[i],&arr[j]);

            }
       
       
   } 
   arr[low]=arr[j];
   arr[j]=pivot;
   return j;
   
}
void quicksort(int arr[],int low,int high)
{
    if(low<high){
        int j= paritition(arr,low,high);
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
    }
}

int main()
{
    cout<<"enter the size : ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter the elements :\n";
    for(int k=0;k<n;k++){
        cin>>arr[k];
        
    }
   quicksort(arr,0,n-1);
   cout<<"Sorted Array :\n";
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
        
    }

    return 0;
}