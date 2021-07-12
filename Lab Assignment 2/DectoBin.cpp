#include<iostream>
using namespace std;
int DectoBin(int n)
{
    if(n==0)
        return 0;
    else    
        return(n%2+10*DectoBin(n/2));
}
int main()
{
    cout<<"Enter the Decimal Number : ";
    int d , b ;
    cin>>d;
    b=DectoBin(d);
    cout<<"The binary of Decimal "<<d << " is " << b;

}