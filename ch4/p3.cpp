#include<iostream>
#include<stack>
#include<stdlib.h>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    stack<char> st;
    int a,b,r;
    string in;
    char *p;
    cout<<"Enter postfix expression(only digits, +,-,*,/,'(',')'): ";
    cin>>in;
    p=&in[0];
    while(*p!='\0')
    {
        if(isdigit(*p))
        {
            st.push(*p);
        }
        else
        {
            a = st.top()-'0';
            st.pop();
            b=st.top()-'0';
            st.pop();
            switch(*p)
            {
            case '+':
                st.push((char)(a+b+48));
                break;

            case '-':
                st.push((char)(b-a+48));
                break;

            case '*':
                st.push((char)(a*b+48));
                break;

            case '/':
                st.push((char)(b/a+48));
                break;

            default:
                cout<<"Wrong operator."<<endl;
            }
        }
        p++;
    }
    a=st.top();
    cout<<"Postfix expression evaluation is: "<<(int)(a-'0');

    return 0;
}
