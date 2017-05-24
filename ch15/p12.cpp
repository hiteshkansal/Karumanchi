#include<iostream>
#include<string.h>

using namespace std;

void remove_repeated(char str[])
{
    int n=strlen(str);
    int i,j=0;
    for(i=1; i<=n; i++)
    {
        while(str[i]==str[j] && j>=0)
        {
            i++;
            j--;
        }
        j++;
        str[j]=str[i];
    }
    str[j+1]= '\0';
    cout<<str;
}

int main()
{
    char a[] = "abbbccb";
    remove_repeated(a);
    return 0;
}
