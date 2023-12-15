#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
struct Queue
{
    int cp;
    int size;
    int *ar;
    int front;
    Queue(int x)
    {
        cp=x;
        front =0;
        size=0;
        ar=new int[cp];
    }
    bool full(){
        return size==cp;
    }
    bool empty()
    {
        return size==0;
    }
    void enque(int x)
    {
        if(full()){
            cout<<"Queue is full "<<endl;
            return;
        };
        int newrear=rear();
        newrear=(newrear+1) % cp;
        ar[newrear]=x;
        size++;
    }
    void deque()
    {
        if(empty())
        {
            cout<<"Empty"<<endl;
            return;
        }
        front=(front+1)%cp;
        size--;
    }
    int rear()
    {
        if(empty())
        {
            return-1;
        }
        return (front+size-1)%cp;
    }
    int getfront()
    {
        if(empty())
        {
            return -1;
        }
        return front;
    }
    void print(){
        if(empty())
        {
            cout<<"Queue is EMPTY"<<endl;
            return;
        }
        for(int i=0;i<size;i++)
        {
            cout<<ar[(front+i)%cp]<<" ";
        }
        cout<<endl;

    }
};
int main()
{
    cout<<"Start\n";
    Queue q(5);
    bool flag=true;
    cout<<"Enter 1 for Enque \n";
    cout<<"Enter 2 for Deque \n";
    cout<<"Enter 3 for Size \n";
    cout<<"Enter 4 for Print \n";
    cout<<"     ******      "<<endl;
    while (flag)
    {
        int choice;cin>>choice;
        switch (choice)
        {
        case 1:
            int x;cout<<"Enter Num : ";cin>>x;
            q.enque(x);
            break;
        case 2:
            q.deque();
            break;
        case 3:
            cout<<"Size is : "<<q.size<<endl;
            break;
        case 4:
            q.print();
            break;
        default:
            flag=false;
            break;
        }
    }
    
    return 0;
}