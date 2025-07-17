#include <iostream>
#include <string>
using namespace std;

template<class T,size_t N>
T* my_begin(T (&arr)[N]){
    return arr;
}

template<class T,size_t N>
T* my_end(T (&arr)[N]){
    return arr+N;
}

int main(){
    string s[]={"123456","23456","34567"};
    cout << *my_begin(s) <<endl;
    //cout << *my_end(s) << endl;    //错误，s是末尾，无任何值无法解引用
    cout << *(my_end(s)-1) << endl;
    return 0;
}