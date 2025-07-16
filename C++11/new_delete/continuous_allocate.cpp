/***************************************************************************
 *  @file       continuous_allocate.cpp
 *  @author     Baiqiang Long
 *  @date       2025 7月 16
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/



 #include<iostream>
 #include <vector>
 #include <string>
 #include <algorithm>
 #include <memory>
 using namespace std;
 
class Obj{
private:
    long long a;
    char b;
public:

    static void* operator new(size_t sz);
    static void operator delete(void* ptr);

    static void* operator new[](size_t sz);
    static void operator delete[](void* ptr);
 };

void* Obj::operator new(size_t sz){
    void* ptr = ::operator new(sz); //调用全局new
    cout << "[Obj::operator new] 申请 " << sz << " 字节, 地址: " << ptr << endl;
    return ptr;
}

void Obj::operator delete(void* ptr) {
        cout << "[Obj::operator delete] 释放地址: " << ptr << endl;
        ::operator delete(ptr);
    }

void* Obj::operator new[](size_t sz) {
        void* ptr = ::operator new[](sz);
        cout << "[Obj::operator new[]] 申请 " << sz << " 字节, 地址: " << ptr << endl;
        return ptr;
    }
void Obj::operator delete[](void* ptr) {
        cout << "[Obj::operator delete[]] 释放地址: " << ptr << endl;
        ::operator delete[](ptr);
    }

// 计算两个指针之间的字节差值
size_t address_diff(const void* a, const void* b) {
    return (size_t)((uintptr_t)a > (uintptr_t)b ? 
                    (uintptr_t)a - (uintptr_t)b : 
                    (uintptr_t)b - (uintptr_t)a);
}


int main(int argc, char* argv[]) {

    cout << "***** 逐次 new 5 个对象 *****" << endl;
    vector<Obj*> ptrs;
    for (int i = 0; i < 5; ++i) {
        Obj* p = new Obj();
        ptrs.push_back(p);
    }

    cout << "地址差值序列（字节）：" << endl;
    for (size_t i = 1; i < ptrs.size(); ++i) {
        size_t diff = address_diff(ptrs[i], ptrs[i-1]);
        cout << "ptrs[" << i << "] - ptrs[" << i-1 << "] = " << diff << endl;
    }

    for (auto p : ptrs) {
        delete p;
    }

    cout << "\n***** 一次性 new 5 个对象 *****" << endl;
    Obj* arr = new Obj[5];

    cout << "地址差值序列（字节）：" << endl;
    for (int i = 1; i < 5; ++i) {
        size_t diff = address_diff(&arr[i], &arr[i-1]);
        cout << "&arr[" << i << "] - &arr[" << i-1 << "] = " << diff << endl;
    }

    delete[] arr;

    return 0;
}