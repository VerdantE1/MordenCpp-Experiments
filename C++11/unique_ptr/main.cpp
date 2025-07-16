/***************************************************************************
 *  @file       main.cpp
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
 


class AA
{
public:
    std::string m_name;
    AA() { std::cout << m_name << " 调用构造函数AA().\n"; }
    AA(const std::string &name) : m_name(name) { std::cout << "调用构造函数AA(" << m_name << ").\n"; }
    ~AA() { std::cout << "调用了析构函数~AA(" << m_name << ").\n"; }
};




unique_ptr<AA> func() {
    return pp;
}



int main(int argc, char* argv[]){
    //原指针处理
    AA* ptr = new AA("阿萨姆");
    // delete ptr;   //容易忘

    //unique_ptr的初始化方法
    unique_ptr<AA> u_ptr(new AA("2号"));   //初始化方式1
    unique_ptr<AA> u_ptr2 = make_unique<AA>("3号"); //初始化方式2 make_unique是临时对象，右值，移动语义


    //unique_ptr删除了拷贝语义和赋值语义
    unique_ptr<AA> u_ptr3 = make_unique<AA>("ASD");
    //auto it = u_ptr3;   // 错误,u_ptr3是左值，拷贝或赋值语义。而拷贝和赋值

    //返回裸指针
    // cout << u_ptr3.get() << endl;

    //释放控制权
    u_ptr3.release();
    func();

    //释放控制权2
    u_ptr3.reset();
    u_ptr3.reset(nullptr); 
    u_ptr3.reset(new AA("123")) ;//释放的同时，指向新的资源


    //交换控制权
    u_ptr3.swap(u_ptr2);
    


    return 0;
 }