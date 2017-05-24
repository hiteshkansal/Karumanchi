#include<iostream>
#include<queue>

using namespace std;
queue <int> q1,q2;

void psh(int v)
{
    if(q1.empty() && q2.empty())
        q1.push(v);

    else if(q1.empty())
        q2.push(v);

    else
        q1.push(v);
}

int pops()
{
    int i,n;
    if(q1.empty() && q2.empty())
    {
        cout<<"Under flow"<<endl;
        return 0;
    }
    else if(q1.empty())
    {
        n=q2.size();
        for(i=0; i<n-1; i++)
        {
            q1.push(q2.front());
            q2.pop();
        }
        cout<<q2.front()<<" deleted."<<endl;
        q2.pop();
    }
    else
    {
        n=q1.size();
        for(i=0; i<n-1; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        cout<<q1.front()<<" deleted."<<endl;
        q1.pop();
    }

}
void display()
{
    int i,n;
    if(q1.empty()&& q2.empty())
        cout<<"Stack is empty";

    else if(q2.empty())
    {
        n=q1.size();
        cout<<"stack element from bottom: ";
        for(i=0; i<n; i++)
        {
            cout<<q1.front()<<" ";
            q2.push(q1.front());
            q1.pop();
        }
    }
    else
    {
        n=q2.size();
        cout<<"stack element from bottom: ";
        for(i=0; i<n; i++)
        {
            cout<<q2.front()<<" ";
            q1.push(q2.front());
            q2.pop();
        }
    }
}

int main()
{
    psh(1);
    psh(2);
    psh(3);
    psh(4);

   // pops();
   // pops();
    display();
    return 0;
}
