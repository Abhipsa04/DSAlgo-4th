// Sum of Digits of Number Using Recursion
#include <iostream>
using namespace std;
int recursum(int n)
{
    if(n==0)
    {
        return 0;
    }
    return(n%10+recursum(n/10));
}
int main()
{
    int x;
    cout<<"Enter The Digit : ";
    cin>>x;
    int r=recursum(x);
    cout<<"The Sum of the Digits of the number is : "<<r;
}