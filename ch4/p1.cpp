#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<char> st;
    string in;
    char *p;
    cout<<"Enter input ((){}[]): ";
    cin>>in;
    p=&in[0];

    while(*p!=NULL)
    {
        if(*p =='{' || *p =='[' || *p =='(')
            st.push(*p);

        else if(*p == '}' && st.top() == '{')
            st.pop();

        else if(*p == ']' && st.top() == '[')
            st.pop();

        else if(*p == ')' && st.top() == '(')
            st.pop();
            p++;
    }
    if(st.empty())
        cout<<"Balanced symbol";
    else
        cout<<"Non- balance.";
    return 0;
}
