/***************************************************************************
 *  @file       BlobPtr.h
 *  @author     Baiqiang Long
 *  @date       2025 7月 16
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/

 #include<iostream>
 #include <memory>
 #include "Blob.h"


 template<class T>
 class Blob;

 
template<class T>
class BlobPtr{
public:
    using value_type = T;
    using size_type = std::size_t;
private:
    weak_ptr<Blob> wptr;    //cur address
    size_type = curr;       //cur postion
public:
    //constructor
    BlobPtr():curr(0){}
    BlobPrt(Blob& a,size_type sz=0):wptr(make_shared(a)),curr(sz){}

    //operator-prefix
    BlobPtr& operator++(){}
    BlobPtr& operator--(){}

    //operator-postfix
    BlobPtr& operator ++(int){}
    BlobPtr& operator --(int){}

    friend bool operator==<T>
    (BlobPtr<T>& a, BlobPtr<T>& b);

    friend bool operator < <T>
    (BlobPtr<T>& a, BlobPtr<T>& b);

    //to get reference
    T& operator*() const{ return }


    
}