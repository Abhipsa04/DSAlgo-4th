#include<iostream>
using namespace std;
int isPrime(int x, int y)
{
    if(y==1)
        return 1;
    else{
        if(x%y==0)
            return 0;
        else 
            isPrime(x,y-1);
    }
}
int main()
{
    int n , prime ;
    cout<<"Enter the Number : ";
    cin>>n;
    prime = isPrime(n,n/2);
    if(prime==1)
        cout<<"The Number is Prime ";
    else
        cout<<"The Number is not Prime ";
}