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
   				{cout<<""<<endl;
                }
  			else{
  				//cout<<"The Element is popped:"<<endl;
                int x=a[top];
  				top--;
                return x;
			}
		   }

		void print(){
  			int j=0;
  			for(j=0;j<=top;j++)
   			cout<<a[j]<<" ";
  			cout<<endl;
		}

		int peek(){
  			
            if(top==-1)
            {//cout<<"PEEK IS null "<<endl;
              return -665;}
            else
             {//cout<<"PEEK IS "<<a[top]<<endl;
                return a[top];}
		}

};
class Queue
{
    Stack s1;
    Stack s2;
    public:
    void enqueue(int x){
        while(s1.isfull()){
            cout<<"Queue is Full Can't Insert!!";
            return;
        }
        while(!s1.isempty()){
            s2.push(s1.peek());
            s1.pop();

        }
        s1.push(x);
        while(!s2.isempty()){
            s1.push(s2.pop());
        }
    }
    int dequeue(){
        if(s1.isempty()){
            cout<<"Queue is Empty";
            return 0;
        }
        
        int x=s1.peek();
        cout<<endl<<"The element is deleted: "<<x<<endl;
        s1.pop();
        return x;
    }
    void show(){
		s1.print();
	}
};


int main(void){
    system("CLS");
 	Queue a;
 	int m=1;
 	while(m!=0){
  			cout<<endl<<"ENTER CHOICE "<<endl<<"1 Enqueue Element"<<endl<<"2 Dequeue Element"<<endl<<"3 Display"<<endl<<"0 TO CLOSE THE PROGRAM"<<endl;
  			cin>>m;
  			cout<<endl<<endl;
  		switch(m){
   		case 1:
   			//system("CLS");
   			cout<<"Enter the element which you want to push: "<<endl;
   			int data;
   			cin>>data;
    		a.enqueue(data);
    		break;
   		case 2:
   			//system("CLS");
    		
    		a.dequeue();
    		break;
    	case 3:
    		system("CLS");
    		cout<<"The elements are: ";
    		a.show();
    		break;
   		case 0:
    		cout<<"CLOSING THE PROGRAM....";
    		break;        
		}
	}
}
