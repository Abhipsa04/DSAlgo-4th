#include<iostream>
#include<stdlib.h>

#define max 20

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

