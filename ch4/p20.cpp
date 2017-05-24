#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int s1=0,x=0,flag=1;
    string st;
    stack<char> s;
    cout<<"Enter sring containing only S and X: ";
    cin>>st;
    char *p = &st[0];
    while(*p!=NULL)
    {
        if(*p=='s')
            s1++;
        else
            x++;
        p++;
    }
    p= &st[0];
    if(s1!=x)
        cout<<"not Admissible"<<endl;
    else
    {
        while(*p!=NULL)
        {
            if(*p=='x')
            {
                if(s.empty())
                {
                    cout<<"Not admissible"<<endl;
                    flag=0;
                    break;
                }
                s.pop();
            }
            else
                s.push(*p);
            p++;
        }
        if(flag)
            cout<<"Admissible";
    }
    return 0;
}
