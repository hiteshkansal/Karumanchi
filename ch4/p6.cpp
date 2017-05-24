#include<iostream>
#include<stack>
#include<stdlib.h>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    stack<int> st;
    stack<int> minm;
    do
    {
        cout<<"Enter 1 for push.\n"<<"Enter 2 for Pop.\n"<<"Enter 3 for get minimum.\n"<<"Enter 0 for exit\n";
        cin>>n;
        switch(n)
        {
        case 1:
            int v;
            cout<<"Enter value to push: ";
            cin>>v;
            if(st.empty())
            {
                st.push(v);
                minm.push(v);
            }
            else
            {
                st.push(v);
                if(minm.top()>=v)
                    minm.push(v);
            }
            break;

        case 2:
            if(st.empty())
            {
                cout<<"Underflow."<<endl;
                break;
            }
            if(minm.top() == st.top())
            minm.pop();
            st.pop();
            break;

        case 3:
            if(!minm.empty())
            cout<<"Minimum element is: "<<minm.top()<<endl;
            else
            cout<<"No element in stack."<<endl;
            break;
        case 0:
        exit(0);
        default:
            cout<<"wrong choice";
        }

    }
    while(1);
    return 0;
}
