#include"queue.h"
#include<stack>
extern int n;

int main()
{
    cout<<"Enter size: ";
    cin>>n;
    int a[n];
    stack<int> st;

    for(int i=0;i<n;i++)
        enq(a,i+1);

    for(int i=0;i<n;i++)
        st.push(deq(a));

    for(int i=0;i<n;i++)
    {
        enq(a,st.top());
        st.pop();
    }
    display(a);
    return 0;
}
