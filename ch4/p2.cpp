#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<char> st;
    string in;
    char *p;
    cout<<"Enter infix expression(only +,-,*,/,'(',')'): ";
    cin>>in;
    p=&in[0];
    cout<<"Postfix expression is: ";
    while(*p!='\0')
    {
        if(isalpha(*p) || isdigit(*p))
            cout<<*p;
        else if(*p == ')')
        {
            while(st.top()!= '(')
            {
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            if(*p == '+' || *p == '-')
            {
                if(st.empty())
                    st.push(*p);
                else
                {
                    while(!st.empty() && st.top() != '(')
                    {
                        cout<<st.top();
                        st.pop();
                    }
                    st.push(*p);
                }
            }
            else
            st.push(*p);
        }
        p++;
    }
    while(!st.empty())
    {
    cout<<st.top();
    st.pop();
    }
    return 0;
}
