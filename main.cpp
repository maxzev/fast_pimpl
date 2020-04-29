#include <iostream>
#include "my_type.hpp"

// See my_type.hpp for use case details.
int main()
{
    MyType t;
    t.Foo();

    {
        MyType t2(5);
        t2.Foo();

        t = t2;
        t.Foo();
    }

    std::cout<< t.Size() << std::endl;

    return 0;
}
