#include<iostream>
using namespace std;

int total_trees(int n)
{
    if(n<=1)
        return 1;
    else
    {
        int left, right, sum = 0;
        for(int i=1;i<=n;i++)
        {
            left = total_trees(i-1);
            right = total_trees(n-i);
            sum += left*right;
        }
    return sum;
    }
}

int main()
{
    cout<<total_trees(3);
    return 0;
}
