#include <iostream>
#include <functional>
#include <vector>
#include <list>
using namespace std;

template<class Iterator,class T>
Iterator my_find(Iterator first,Iterator last,const T & value){
    for(;first != last ; ++first){
        if(*first == value) return first;
    }
    return last;
}


int main()
{
    vector<int> vi = {1,2,3,4,5};
    auto it = my_find(vi.begin(),vi.end(),3);
    
    if (it != vi.end())
        std::cout << "Found in vector: " << *it << std::endl;
    else
        std::cout << "Not found in vector" << std::endl;

    return 0;

}

