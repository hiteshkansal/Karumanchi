#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char *str = "hitesh";
    int n = strlen(str);
    char* s = new char[n];
    strcpy(s,str);
    int i;
    n--;
    char temp;
    cout<<str<<endl;
    for(i=0;i<n;i++,n--)
    {
        temp = s[i];
        s[i] = s[n];
        s[n] = temp;
    }
    cout<<s;
    return 0;
}
