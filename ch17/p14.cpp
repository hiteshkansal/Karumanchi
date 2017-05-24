#include<iostream>
#include<map>
using namespace std;

int main()
{
    char item[]= {'d','a','e','t','k'};
    float weight[] = {12,5,3,10,6};
    float profit[] = {10.0,12.4,15,25,9};
    float capacity = 38;
    int n = sizeof(weight)/sizeof(weight[0]);
    float density[n];
    int total=0;
    float tp=0;
    for(int i=0; i<n; i++)
    {
        density[i] = profit[i]/weight[i];
        total += weight[i];
        tp+=profit[i];
    }
    multimap<float,int> m;
    for(int i=0; i<n; i++)
        m.insert( {density[i],i});

    multimap<float,int> :: reverse_iterator it;
    it = m.rbegin();
    float result=0.0;
    while(capacity>0)// || it!= m.rend())
    {
        // cout<<"iterator: "<<it->second<<endl;
        if(total<=capacity)
        {
            result=tp;
            capacity-=total;
            break;
        }
        if(weight[it->second]<=capacity)
        {
            capacity-=weight[it->second];
            result += profit[it->second];
        }
        else
        {
            result += (capacity/weight[it->second]*profit[it->second]);
            capacity=0;
        }
        it++;
    }
    cout<<"Total profit: "<<result<<endl;
    cout<<"Capacity remaining: "<<capacity;
    return 0;
}
