#include<iostream>
#include<stdlib.h>

#define max 5

using namespace std;

class Lin_Queue{
    public:
    int arr[max];
    int front;
    int rear;

    Lin_Queue(){
    
    front = 0;
    rear = 0;
    }

    int isFull(){
        if (rear == max - 1)
            return 1;
        else
            return 0;
        
    }

    int isEmpty(){
        if (front == rear)
            return 1;
        else
            return 0;
        
    }

    void insert(int item){

        if (!isFull())
        {
            rear++;
            arr[rear] = item;
        }

        else
        {
            cout << "Queue is full" << endl;
        }
    }

    int del(){
        if (!isEmpty())
        {
            front++;
            return arr[front];
        }

        else
        {
            cout << "The Queue is underflow" << endl;
            return -1;
        }
    }

    void print(){
        if (!isEmpty())
        {
            for (int i = front + 1; i <= rear; i++)
            {
                cout << arr[i] << "   ";
            }
        }

        else
        {
            cout << "The Queue is Empty" << endl;
        }   
    }
};

int main()
{

    Lin_Queue Q1;


    while (1)
    {
    	cout<<endl;
        cout << " 1. Enqueue \n 2. Dequeue \n 3. Display \n 5. isEmpty\n 6. isFull\n 0. Exit" << endl;
        cout << "Enter your choice" << endl;
        int n;
        int x;
        int y;
        cin >> n;

        switch(n){

            case 1:
            	//system("CLS");
                int item;
                cout << "Enter the item" << endl;
                cin >> item;
                Q1.insert(item);
                break;

            case 2:
            	//system("CLS");
                Q1.del();
                break;

            case 3:
            	//system("CLS");
                cout << "The Queue is" << endl;
                Q1.print();
                break;      

            case 0:
            	//system("CLS");
                exit(1);  
                break;
            case 5:
                x=Q1.isEmpty();
                if (x==1)
               {
                  cout<<"The Queue is Empty \n";
               }
              else if(x==0)
               {
                 cout<<"The Queue is not Empty \n";
              }
              break;
            case 6:
                y=Q1.isFull();
                if (y==1)
               {
                cout<<"The Queue is Full \n";
               }
               else if(y==0)
               {
                 cout<<"The Queue is not Full \n";
               }
               break;    

            default:
            	system("CLS");
                cout << "Choose the options correctly";
                break;        
        }
    } 
    return 0;
}