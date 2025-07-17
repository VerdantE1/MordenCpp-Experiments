/***************************************************************************
 *  @file       Test1.cpp
 *  @author     Baiqiang Long
 *  @date       2025 7月 17
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/


#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "DebugDelete.h"
#include <memory>
using namespace std;

int main(int argc, char* argv[]){

    unique_ptr<int,DebugDelete> u_ptr (new int{5},DebugDelete());


   return 0;
}