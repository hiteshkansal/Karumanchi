#include<iostream>
#include<string.h>

using namespace std;

int string_occur(char s[], int m, char t[], int n)
{
    int l[m+1][n+1];

    memset(l,0,sizeof(l));
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                l[i][j] = 1;
            else if(j==0)
                l[i][j] = 0;
            else if(s[i-1] == t[j-1])
                l[i][j] = l[i-1][j-1] + l[i][j-1];
            else
                l[i][j] = l[i-1][j];
        }
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<l[i][j]<<" ";
        cout<<endl;
    }
    return l[m][n];
}

int main()
{
    char t[] = "abadbd";
    char s[] = "abd";
    int n = strlen(t);
    int m = strlen(s);
    cout<<string_occur(s,m,t,n);
    return 0;
}
