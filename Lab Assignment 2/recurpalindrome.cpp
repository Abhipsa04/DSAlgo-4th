#include<iostream>
using namespace std;
int n; //global declaration for usimg the same value of n in both funtions.
int isPalindrome(int r)
{
    static int sum =0;// using static keyword to update the value of sum in every recursive call
    if(r!=0)
    {
        sum =sum*10+ r%10;//storing the reverse number
        isPalindrome(r/10);
    }
    else if (sum==n)
    {
        return 1;

    }
    else
        return 0;
}
int main()
{
    cout<<"Enter the Number to Check  if Palindrome or not : ";
    cin>>n;
    int pal = isPalindrome(n);
    if(pal==1)
    {
        cout<<"The Number is a palindrome";
    }
        if(pal==0)
    {
        cout<<"The Number is  not a palindrome";
    }

}