#include<iostream>
#define MAX 5

using namespace std;

class Stack{
 		int a[MAX];
 		int top;
 	public:	
 		Stack(){
			top=-1;
			}
		int isempty(){
  			if(top == -1)
   				return 1;
  			else
   				return 0;
		}

		int isfull(){
  			if(top==MAX-1)
   				return 1;
  			else
   				return 0;
		}

		void push(int n)
		{
  			if(isfull()==1)
   				cout<<"STACK IS FULL!! CAN'T ENTER MORE DATA "<<endl;
  			else{

   				top++;
   				a[top]=n; 
   			}
		}

		int pop(){
  			if(isempty()==1)
   				{cout<<"NOTHING TO POP"<<endl;
                return -669;}
  			else{
  				//cout<<"The Element is popped:"<<endl;
  				 int x=a[top];

                  top--;
                  return x;

			}
		}

		void print(){
  			int j=0;
  			for(j=top;j>=0;j--)
   			cout<<a[j]<<" ";
  			cout<<endl;
		}

		void peek(){
  			
            if(top==-1)
             cout<<"PEEK IS null "<<endl;
            else
             cout<<"PEEK IS "<<a[top]<<endl;
		}

};