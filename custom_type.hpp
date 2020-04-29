#ifndef THIRD_PARTY_TYPE_H
#define THIRD_PARTY_TYPE_H

#include <stddef.h>

/*
 * CustomType implementation that we want to hide.
 */

class CustomType
{
    private:
        int a = 1;
        int b = 2;
    public:
        CustomType();
        ~CustomType();

        void setA(int v) { a = v; }
        void Foo()const;
        size_t Size()const;
};


#endif // THIRD_PARTY_TYPE_H
