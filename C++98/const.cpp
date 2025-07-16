#include <iostream>
using namespace std;


int main(){
    //内存
    int x = 10;
    int y = 20;

    //普通指针
    int *p1 = &x;
    *p1 = 99;   //ok 改变目前所指内容的值
    p1 = &y;    //ok  改变指向内容

    //顶层const
    int * const p2 = &x;
    *p2 = 100; cout << x << endl;   //ok  改变目前所指内容的值
    // p2 = p1;                     //错误，不能改变指向内容
    //结论：顶层const修饰-指针变量本身不可改变，可以通过指针改变所指内容

    //底层const
    const int* p3 = &x;
    p3 = &y; cout << *p3 <<endl;    //ok 改变指向内容
    // *p3 = 999;                   //错误，不能改变目前所指内容的值
    //结论： 底层const修饰-指针变量本身可以改变，但是不能通过解引用去改变所指内容的值
    
    //即顶层const修饰指针不让它改变本身内容，固定遥控器对应那个电视；
    //底层const修饰指针可以让遥控器换多个电视，但无法去换电视的台。


    return 0;
}