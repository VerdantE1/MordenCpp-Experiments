/***************************************************************************
 *  @file       Blob.h
 *  @author     Baiqiang Long
 *  @date       2025 7月 16
 *  @remark     This code is for the exercises from C++ Primer 5th Edition
 *  @note
 ***************************************************************************/
 #pragma once

#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

using namespace std;
template <typename T>
class Blob 
{
public:
    typedef T value_type;
    typedef vector<int>::size_type size_type;
private:
    std::shared_ptr<std::vector<int>> data;    

public:
    Blob();
    Blob(std::initializer_list<T> li);
    
    //Number of elements in the Blob
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    //Change of Blob
    void push_back(const T& t) {data->push_back(t);}         
    void push_back(T && t) {data->push_back(std::move(t));}  //support rval
    void pop_back() {data->pop_back();}

    //Element Access
    T& back() {return data->back();}
    T& operator[](size_type i){return (*data)[i];}

    //Element Acess Read-Only
    const T& back() const {return data->back();};
    const T& operator[](size_type i) const {return (*data)[i];}

private:
    void check(size_type i,const std::string &msg) const;
};

template <typename T>
inline Blob<T>::Blob(): data(std::make_shared<vector<int>>()){}

template <typename T>
inline Blob<T>::Blob(std::initializer_list<T> li): data(std::make_shared<vector<int>>(li)){}

template <typename T>
inline void Blob<T>::check(size_type i, const std::string &msg) const
{
    if(i==data->size())
        throw std::out_of_range(msg);
}
