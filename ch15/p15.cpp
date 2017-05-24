#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

void interleaving(char a[], char b[],char str[], int m, int n, int i)
{
    if(m==0 && n==0)
        cout<<str<<endl;
    if(m)
    {
        str[i] = a[0];
        interleaving(a+1,b,str,m-1,n,i+1);
    }
    if(n)
    {
        str[i] = b[0];
        interleaving(a,b+1,str,m,n-1,i+1);
    }
}

int main()
{
    char a[] = "ab";
    char b[] = "cd";
    int n = strlen(a);
    int m = strlen(b);
    char *str = new char[m*n+1];
    str[m+n] = '\0';
    interleaving(a,b,str,m,n,0);
    free(str);
    return 0;
}
