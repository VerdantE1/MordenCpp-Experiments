/***************************************************************************
 *  @file       DebugDelete.cpp
 *  @author     Baiqiang Long
 *  @date       2025 7月 17
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

# pragma

#include <iostream>

class DebugDelete {
public:
    DebugDelete(std::ostream& s = std::cerr):os(s){}

    template<class T>
    void operator() (T* p){
        std::cout << "Unique_ptr is deleting this resources" << std::endl;
        delete p;
    }
    
private:
    std::ostream& os;    
};




