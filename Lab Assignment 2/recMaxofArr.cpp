#include<iostream>
using namespace std;
int recMax(int A[], int n)
{
    if(n==1)
        return A[0];
    return max(A[n-1],recMax(A,n-1));

}
int main()
{
    int size ;
    cout<<" Enter The size of the Array : ";
    cin>>size;
    int arr[size];
    cout<<"Enter the Elements of the Array : "<<endl;
    for(int i = 0; i<size;i++)
    {
        cin>>arr[i];
    }
    cout<< "\n The Largest Element is : " << recMax(arr,size);
}