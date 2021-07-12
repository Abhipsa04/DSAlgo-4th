# include<iostream>
using  namespace std;
int recGCD(int x ,int y)
{
    if(y==0)
      return x;
    return recGCD(y,x%y);
}
int main()
{
    int a , b , gcd ;
    cout<<"Enter The Two Numbers : ";
    cin>>a>>b;
    gcd=recGCD(a,b);
    cout<<" The GCD of the Numbers are : "<< gcd;
}