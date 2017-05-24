#include<iostream>

using namespace std;
int f[100];
void prefix(char p[], int m)
{
    int i=1, j=0;
    f[0]=0;
    while(i<m)
    {
        if(p[i]==p[j])
        {
            f[i] = j+1;
            i++;
            j++;
        }
        else if(j>0)
            j = f[j-1];
        else
        {
            f[i] = 0;
            i++;
        }
    }
}

int KMP(char t[], int n, char p[], int m)
{
    int i=0,j=0;
    prefix(p,m);
    while(i<n)
    {
        if(t[i]==p[j])
        {
            if(j==m-1)
                return i-j;
            else
            {
                i++;
                j++;
            }
        }
        else if(j>0)
            j = f[j-1];
        else
            i++;
    }
    return -1;
}

int main()
{
    char p[] = "mous";
    char t[] = "anonymous";
    int m = sizeof(p)/sizeof(p[0]);
    int n = sizeof(t)/sizeof(t[0]);
    cout<<KMP(t,n-1,p,m-1);
    return 0;
}
