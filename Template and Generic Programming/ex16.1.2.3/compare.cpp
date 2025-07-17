#include <iostream>
#include <functional>
using namespace std;

template<class T,class Compare = less<T>>
bool compare(const T &a,const T &b,Compare comp = Compare()){
    return comp(a,b);
}

int main()
{
    cout << compare<int>(5,6) << endl;
    cout << compare(string("abc"),string("acb")) <<endl;
    
    return 0;
}