#include<iostream>
#include<stack>

using namespace std;

void enq(stack<int> &s1,int v)
{
    s1.push(v);
}

void deq(stack<int> &s1, stack<int> &s2)
{
    if(!s2.empty())
        {
            cout<<s2.top()<<" deleted"<<endl;
            s2.pop();
        }
    else
        {
            if(s1.empty())
            return;

            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            cout<<s2.top()<<" deleted"<<endl;
            s2.pop();
        }
}
int main()
{
    stack<int> s1,s2;
    for(int i=0;i<5;i++)
        enq(s1,i+1);

    for(int i=0;i<3;i++)
        deq(s1,s2);
    enq(s1,6);
    deq(s1,s2);
    deq(s1,s2);
    deq(s1,s2);
    return 0;
}
