#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char str[] = "hitesh";
    int s = 0, n = strlen(str)-1;
    while(s<n)
    {
        str[s]^=str[n];
        str[n]^=str[s];
        str[s]^=str[n];
        s++;
        n--;
    }
    cout<<str;
    return 0;
}
