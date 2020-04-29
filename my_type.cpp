#include "my_type.hpp"
#include "custom_type.hpp"
#include <iostream>


MyType::MyType() = default;
MyType::MyType(const MyType & ) = default;
MyType::MyType(MyType && )= default;
MyType& MyType::operator=(const MyType &) = default;
MyType::~MyType() = default;


MyType::MyType(int v)
{
    m_data->setA(v);
}

size_t MyType::Size() const
{
    return m_data->Size();
}

void MyType::Foo() const
{
    return m_data->Foo();
}
