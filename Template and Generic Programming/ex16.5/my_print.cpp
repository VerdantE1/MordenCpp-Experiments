#include <iostream>
#include <string>


// 支持任意类型，任意大小的数组类，进行print

using namespace std;


/* 此时arr是数组引用，它是一个数组类型,具备可遍历容器性质 */
template<class Arr>
void my_print1(const Arr& arr){
    for(auto & elem : arr){
        cout << elem <<" ";
    }
    cout << endl;
    return;
}

/* 此时arr会退化为数组指针，它是一个指针类型,不具备可遍历容器性质 */
template<class Arr>
void my_print2(const Arr arr){
    for(auto & elem : arr){
        cout << elem <<" ";
    }
    cout << endl;
    return;
}

/* 更严格的数组定义，数组引用 */
template<class Arr,size_t N>
void my_print3(const Arr (&arr) [N]){
     for(auto & elem : arr){
        cout << elem <<" ";
    }
    cout << endl;
    return;
}


/* 更严格的数组定义，数组指针，不可遍历 */
template<class Arr,size_t N>
void my_print4(const Arr (*arr) [N]){
     for(auto & elem : arr){
        cout << elem <<" ";
    }
    cout << endl;
    return;
}



int main(){
    std::string s[] = { "ssss", "aaa", "ssssss" };
    char c[] = { 'a', 'b', 'c', 'd' };
    int  i[] = { 1 };

    my_print1(i);
    my_print1(c);
    my_print1(s);

    //my_print2(s);     //错误，s是数组类型是可遍历容器，但my_print2接收后会退化为数组指针，而数组指针不是可遍历容器所以不能进行for(auto)
    my_print3(s);
    //my_print4(s);     //错误，同2
    return 0;
}