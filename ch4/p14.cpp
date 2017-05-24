#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n,i=0,j,k,l;
    cout<<"Enter size of array: ";
    cin>>n;
    int a[n];
    j=n;
    for(i=0; i<n; i++)
    {
        a[i]=0;
    }
    i=-1;
    while(i<=j)
    {
        int ch,v;
        cout<<"Which stack u wanna enter: \n"<<"1 for stack one.\n"<<"2 fo stack 2.\n"<<"3 for print \n"<<"0 for exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            if(i+1==j)
            {
                cout<<"Stack is full. u can only print by pressing 3."<<endl;
                break;
            }
            cout<<"Enter value: ";
            cin>>v;
            i++;
            a[i]=v;
            break;

        case 2:
            if(i+1==j)
            {
                cout<<"Stack is full. u can only print by pressing 3."<<endl;
                break;
            }

            cout<<"Enter value: ";
            cin>>v;
            j--;
            a[j]=v;
            break;

        case 3:
            k=i;
            l=j;
            cout<<"Stack 1 is: ";
            for(; k!=-1; k--)
                cout<<a[k]<<" ";
            cout<<"\nStack 2 is: ";
            for(; l!=n; l++)
                cout<<a[l]<<" ";
            cout<<endl;
            break;

        case 0:
            exit(0);

        default:
            cout<<"Wrong input.\n";
        }
    }
    return 0;
}
