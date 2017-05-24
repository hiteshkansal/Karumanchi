#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int n,i,span=1,maxs=1;
    cout<<"Enter no. of element in array: ";
    cin>>n;
    int a[n],index = n-1;
    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=n-1;i>=0;i--)
    {
        if(a[index]>=a[i-1])
        {
            span++;
            index = i;
            if(span>=maxs)
            maxs=span;
        }
        else
        {
            span =1;
            index--;
        }
    }
    cout<<"Max span is: "<<maxs;
    return 0;
}
