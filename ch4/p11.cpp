#include<iostream>
#include<stack>
using namespace std;

void insertat(stack<int> &s, int data)
{
    int temp;
    if(s.empty())
    {
        s.push(data);
        return;
    }
    temp = s.top();
    s.pop();
    insertat(s,data);
    s.push(temp);
}
void reverses(stack<int> &s)
{
    int data;
    if(s.empty())
        return;
    data = s.top();
    s.pop();
    reverses(s);
    insertat(s, data);
}

void prints(stack<int> &s)
{
    int a;
    while(!s.empty())
    {
        a= s.top();
        cout<<a<<endl;
        s.pop();
    }
}
int main()
{
    stack<int> s;
    for(int i=0;i<5;i++)
        s.push(i+1);
    reverses(s);
    cout<<"Stack after reverse: \n";
    prints(s);
    return 0;
}
