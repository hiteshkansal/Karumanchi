#include<iostream>
using namespace std;

void mrge(int *a, int *temp,int left, int mid, int right)
{
//    cout<<"merge";
    int tpos = left,lpos = mid-1,sz = right-left+1;;
    while(left<=lpos && mid<=right)
    {
        if(a[left]>a[mid])
        {
            temp[tpos] = a[mid];
            tpos++;
            mid++;
        }
        else
        {
            temp[tpos] = a[left];
            tpos++;
            left++;
        }
    }
    while(left<=lpos)
    {
        temp[tpos] = a[left];
        tpos++;
        left++;
    }
    while(mid<=right)
    {
        temp[tpos] = a[mid];
        tpos++;
        mid++;
    }

    for(int i=0;i<sz;i++,right--)
        a[right] = temp[right];
}

void mergesort(int *a, int *temp,int left, int right)
{
    if(right>left)
    {
        int mid;
        mid = (left+right)/2;
        mergesort(a,temp,left,mid);
        mergesort(a,temp,mid+1,right);
        mrge(a,temp,left,mid+1,right);
    }
}

int main()
{
    int a[] = {4,67,2,5,7,1,9,33};
    int n=8,l=0,r=n-1;
    int temp[n];
    mergesort(a,temp,l,r);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
