#include<iostream>

using namespace std;

int main()
{
    int a[] = {5,2,15,9,10,3,16,6};
    int n = 8,temp,mini;
    for(int i=0; i<n; i++)
    {
        mini = i;
        for(int j=i+1; j<n; j++)
        {
            if(a[mini] > a[j])
                mini = j;
        }
        swap(a[mini],a[i]);
    }

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";

    return 0;
}
