/***************************************************************************
 *  @file       main.cpp
 *  @author     Baiqiang Long
 *  @date       2025 7月 17
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note       这节引导你去写泛型算法。用类的类型成员来写泛型算法的入门。
 * 1.学到了用类的类型成员使得算法的泛型更高
 * 让算法能够适配不同的容器类型，提高了代码的泛型性和复用性。
 * 
 * 
 * 2.学到了用ranged-based for使得算法的泛型更高
 *    让算法能够遍历所有支持 begin()/end() 的容器，
 *    进一步提升了代码的通用性和简洁性。
 * 
 ***************************************************************************/



#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>


using namespace std;
//原始版本
//缺点1：写死了输出流是cout,只能输出到终端。
//缺点2：蓝图中的遍历容器代码
template<class Container>
void print1(Container& container){
   for(typename Container::size_type i =0 ;i != container.size(); ++i){
   cout << container[i] <<" ";
   }
   cout << endl;
   return ;
}


//优化版本一
//改变遍历局限，支持可遍历容器 ; 万能引用版
template<class Container>
void print2(Container& container){
   for(auto && it = container.begin(); it != container.end();++ it){
      cout << *it << " ";
   }
   cout << endl;
   return ;
}


//优化版本二
//改变遍历局限，支持可遍历容器;
template<class Container>
void print3(Container& container){
   for(auto it = container.begin(); it != container.end();++ it){
      cout << *it << " ";
   }
   cout << endl;
   return ;
}



//优化版本三
//支持多种输出流
template<class Container>
void print3(Container& container,ostream& os){
   for(auto it = container.begin(); it != container.end();++ it){
      os << *it << " ";
   }
   cout << endl;
   return ;
}



int main(int argc, char* argv[]){

   std::vector<int> v1 = { 1, 23, 6, 4, 5, 7, 4 };
   std::list<int> v2 = {1,23,6,4,5,6,7,4};
   print1(v1);
   // print1(v2);  //错误,list容器没有重置[]运算符

   print2(v1);
   print2(v2);

   
   print3(v2,std::cout);




   return 0;
}
