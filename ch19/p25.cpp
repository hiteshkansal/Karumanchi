#include<iostream>
using namespace std;

int subset(int a[], int n)
{
    int c =14;
    int s[n+1][c+1];
    for(int i=0;i<=c;i++)
        s[0][i] = 0;

    for(int i=1;i<=n;i++)
        s[i][0] = 0;
    s[0][0] = 1;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=c;j++)
        {
            if(j < a[i-1])
                s[i][j] = s[i-1][j];
            else
                s[i][j] = s[i-1][j] || s[i-1][j-a[i-1]];
        }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=c;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }
    return s[n][c];
}

int main()
{
    int a[] = {3,2,4,19,3,7,13,10,6,11};
    const int n = sizeof(a)/sizeof(a[0]);
    if(subset(a,n))
        cout<<"yes!!!";
    else
        cout<<"No!!!";
    return 0;
}
