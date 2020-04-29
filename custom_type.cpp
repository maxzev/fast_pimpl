#include "custom_type.hpp"
#include <iostream>

CustomType::CustomType():a(1), b(2)
{
}

CustomType::~CustomType() = default;

void CustomType::Foo() const
{
    std::cout<< "Foo "<< a << std::endl;
}

size_t CustomType::Size()const
{
    return sizeof a + sizeof b;
}
