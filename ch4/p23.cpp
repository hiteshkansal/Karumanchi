#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> st;
    int n,p;
    cout<<"How many elemnt: ";
    cin>>n;
    int a[n],s[n];
    for(int k=0;k<n;k++)
        cin>>a[k];
    for(int i=0;i<n;i++)
    {
        while(!st.empty())
        {
            if(a[i]>a[st.top()])
                st.pop();
            else
                break;
        }
        if(st.empty())
            p=-1;
        else
            p= st.top();
        s[i] = i-p;
        st.push(i);
    }
        for(int i=0;i<n;i++)
    cout<<s[i]<<" ";
    return 0;
}

