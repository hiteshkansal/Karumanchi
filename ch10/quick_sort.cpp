#include<iostream>
#include<stdlib.h>
using namespace std;

int partition1(int *a, int low, int high)
{

    int left = low, right = high, pivt = a[low];
    while(left<right)
    {
        while(a[left]<=pivt)
            left++;
        while(a[right]>pivt)
            right--;
        if(left<right)
            swap(a[left],a[right]);
    }
    a[low] = a[right];
    a[right] = pivt;
    return right;
}

void randomized(int *a, int l, int r)
{
    int ran = (rand()%(r-l+1))+l;
    int temp = a[l];
    a[l] = a[ran];
    a[ran] = temp;
}

void quicksort(int *a,int left, int right)
{
    if(right>left)
    {
        int pivot;
//        randomized(a,left,right);
        pivot = partition1(a,left,right);
        quicksort(a,left,pivot-1);
        quicksort(a,pivot+1,right);
    }
}

int main()
{
    int a[] = {4,67,12,5,7,1,9,33};
    int n= sizeof(a)/sizeof(a[0]);
//    srand(time(0));
    quicksort(a,0,n-1);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}

