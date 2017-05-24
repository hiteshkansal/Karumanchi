#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include<iostream>
#include<stdlib.h>

using namespace std;
int frnt=-1,rear=-1,n;

int full()
{
    return ((rear+1)%n==frnt);
}
void enq(int *p,int v)
{
    if(full())
        cout<<"Q full."<<endl;
    else
    {
        rear=(rear+1)%n;
        p[rear] = v;
        if(frnt == -1)
            frnt=rear;
    }
}
int khali()
{
    return (frnt==-1);
}
int deq(int *p)
{
    if(khali())
    {
        cout<<"Q empty";
        return -1;
    }
    else
    {
        int temp;
        if(frnt==rear)
        {
            temp=p[frnt];
            cout<<temp<<" deleted."<<endl;
            frnt=rear=-1;
            return temp;
        }
        else
        {
            temp=p[frnt];
            frnt++;
            cout<<temp<<" deleted."<<endl;
            if(frnt==n&&rear!=n)
                frnt=0;
                return temp;
        }
    }
}
void display(int *a)
{
    if(khali())
        cout<<"Queue is empty."<<endl;
    else
    {
        int i=frnt;
        cout<<"queue is: ";
        for(i=frnt; i!=rear; i++)
        {
            cout<<a[i]<<" ";
            if(i==n-1)
                break;
        }
        if(i==rear)
            cout<<a[i]<<" ";
        if(i==n-1&&rear<frnt)
        {
            for(i=0; i<=rear; i++)
                cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}


#endif // QUEUE_H_INCLUDED
