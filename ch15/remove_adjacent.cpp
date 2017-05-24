#include<iostream>
#include<string.h>

using namespace std;
int remve(char a[], int n)
{
    if(n<=1)
        return n;
    if(a[n-1]==a[n-2])
    {
        while(a[n-1] == a[n-2] && n>1)
            n--;
        n--;
        return remve(a,n);
    }

    int r = remve(a,n-1);
    if(r>0 && a[r-1] == a[n-1])
        return r-1;
    a[r] = a[n-1];
    return r+1;
}

int main()
{
    char a[] = "abbcbbcdd";
    int n = strlen(a);
    int r = remve(a,n);
    a[r] = '\0';
    cout<<a;
    return 0;
}
