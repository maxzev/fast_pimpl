#ifndef MYTYPE_H
#define MYTYPE_H

#include "fast_pimpl.hpp"


/*
 * The idea is to use CustomType as a part of MyType but
 * hide the implementation of CustomType.
 * One of the possible ways you can use is Pimpl idiom. But usually
 * Pimpl is implemented using pointer and dynamic memory allocation
 * (or std::unique_ptr) that can lead to performance penalties.
 * If you want to avoid this indirection and penalties then FastPimpl
 * may help.
 */



class CustomType; // just forward declaration

class MyType
{
  private:
    utils::FastPimpl<CustomType, 8, 4> m_data;

  public:
    MyType();
    MyType(int v);
    MyType(const MyType &);
    MyType(MyType && );
    MyType& operator=(const MyType &);
    ~MyType();

    size_t Size() const;
    void Foo() const;

};

#endif // MYTYPE_H
