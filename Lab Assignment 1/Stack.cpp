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

		void pop(){
  			if(isempty()==1)
   				cout<<"NOTHING TO POP"<<endl;
  			else{
  				cout<<"The Element is popped:"<<endl;
  				top--;
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


int main(void){
 	Stack ar;
 	int m=1;
     int x;
     int y;
 	while(m!=0){
  		cout<<endl<<"ENTER CHOICE "<<endl<<"1 Push Element"<<endl<<"2 Peek Element"<<endl<<"3 Pop Element"<<endl<<"4 Display"<<endl<<"5 isEmpty"<<endl<<"6 isFull"<<endl<<"0 TO CLOSE THE PROGRAM"<<endl;
  		cin>>m;
  		cout<<endl<<endl;
  	switch(m){
   	case 1:
   		//system("CLS");
   		cout<<"Enter the element which you want to push: "<<endl;
           				
   		int n;
   		cin>>n;
    	ar.push(n);
    	break;
   	case 2:
   		//system("CLS");
    	cout<<endl<<"The peek element is: "<<endl;
    	ar.peek();
    	break;
   	case 3:
   		//system("CLS");
    	ar.pop();
        ar.peek();
    	break;
    case 4:
    	//system("CLS");
    	cout<<"The stack is: ";
    	ar.print();
    	break;
    case 5:
        x=ar.isempty();
        if (x==1)
        {
            cout<<"The stack is Empty \n";
        }
        else if(x==0)
        {
            cout<<"The stack is not Empty \n";
        }
        break;
    case 6:
         y=ar.isfull();
        if (y==1)
        {
            cout<<"The stack is Full \n";
        }
        else if(y==0)
        {
            cout<<"The stack is not Full \n";
        }
        break;    
   	case 0:
    	//ar.show();
    	cout<<"CLOSING THE PROGRAM....";
    	break;        
}
  
}
return 0;
}