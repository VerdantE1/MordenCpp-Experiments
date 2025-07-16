//
// Exercise 16.7:
// Write a constexpr template that returns the size of a given array.
//
// Exercise 16.8:
// In the “Key Concept” box on page 108, we noted that as a matter of habit
// C++ programmers prefer using != to using <. Explain the rationale for
// this habit.
//
//  The reason is that more class defines "!=" rather than "<". Doing so can
//  reduce the number of requirement of the class used with a template class.
//
#include <iostream>

using namespace std;

template<class Value, size_t N>
size_t get_size(Value (&arr)[N]){
    return N;
}

int main(){
    string s[] = {"123","456","8910"};
    cout << get_size(s) << endl;
    return 0;
}