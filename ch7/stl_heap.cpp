#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
struct greater1
{
    bool operator()(const long& a,const long& b) const
    {
        return a<b;
    }
};

int main()
{
    vector<long> vec;
    vec.push_back(15);
    vec.push_back(14);
    vec.push_back(9);
    vec.push_back(25);

    make_heap(vec.begin(), vec.end(), greater1());
    for (unsigned i=0; i<vec.size(); i++)
   cout << ' ' << vec[i];
   cout<<endl;
    while (vec.size())
    {
        pop_heap(vec.begin(),vec.end(),greater1());
        long min = vec.back();
        vec.pop_back();
        cout << min <<endl;
    }

    return 0;
}
*/

int main () {
  int myints[] = {10,20,30,5,15};
  vector<int> v(myints,myints+5);

  make_heap (v.begin(),v.end());
  cout << "initial max heap   : " << v.front() << '\n';

  pop_heap (v.begin(),v.end());
  v.pop_back();
  cout << "max heap after pop : " << v.front() << '\n';

  v.push_back(99);
  push_heap (v.begin(),v.end());
  cout << "max heap after push: " << v.front() << '\n';

 // sort_heap (v.begin(),v.end());

  cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
   cout << ' ' << v[i];
   cout<<endl;
//Less<int>() for max heap & greater<int>() for min heap.
    make_heap(v.begin(),v.end(),less<int>());
    pop_heap(v.begin(), v.end(),less<int>());
    v.pop_back();
     for (unsigned i=0; i<v.size(); i++)
   cout << ' ' << v[i];

  cout << '\n';

  return 0;
}

/*
int main( )  {
   using namespace std;
   vector <int> v1;
   vector <int>::iterator Iter1, Iter2;

   int i;
   for ( i = 1 ; i <= 9 ; i++ )
      v1.push_back( i );

   // Make v1 a heap with default less than ordering
   random_shuffle( v1.begin( ), v1.end( ) );
   make_heap ( v1.begin( ), v1.end( ) );
   cout << "The heaped version of vector v1 is ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")." << endl;

   // Add an element to the back of the heap
   v1.push_back( 10 );
   push_heap( v1.begin( ), v1.end( ) );
   cout << "The reheaped v1 with 10 added is ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")." << endl;

   // Remove the largest element from the heap
   pop_heap( v1.begin( ), v1.end( ) );
   cout << "The heap v1 with 10 removed is ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")." << endl << endl;

   // Make v1 a heap with greater-than ordering with a 0 element
   make_heap ( v1.begin( ), v1.end( ), greater<int>( ) );
   v1.push_back( 0 );
   push_heap( v1.begin( ), v1.end( ), greater<int>( ) );
   cout << "The 'greater than' reheaped v1 puts the smallest "
        << "element first:\n ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")." << endl;

   // Application of pop_heap to remove the smallest element
   pop_heap( v1.begin( ), v1.end( ), greater<int>( ) );
   cout << "The 'greater than' heaped v1 with the smallest element\n "
        << "removed from the heap is: ( " ;
   for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
      cout << *Iter1 << " ";
   cout << ")." << endl;
   return 0;
}
*/
