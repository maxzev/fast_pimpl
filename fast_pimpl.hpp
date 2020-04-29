#ifndef FAST_PIMPL_H
#define FAST_PIMPL_H

#include <stddef.h>
#include <type_traits>
#include <utility>

/*
 * See my_type.hpp for use case details.
 *
 * Copy ctor, dtor etc. must be declared for T !
 * Also, if you provide wrong values of Size and Alignment you will get
 * compile time error => wrong values are safe (see validate func).
 */


namespace utils {


template<class T, size_t Size, size_t Alignment>
class FastPimpl
{
    private:

        typename std::aligned_storage<Size, Alignment>::type m_data;

        T* getStorage() noexcept
        {
            return reinterpret_cast<T*>(&m_data);
        }

        const T* getStorage()const
        {
            return reinterpret_cast<const T*>(&m_data);
        }



        template<size_t aSize, size_t aAlignment>
        void validate()
        {
            static_assert(Size == aSize, " Error: Wrong Size");
            static_assert(Alignment == aAlignment, "Error: Wrong Alignment");
        }


    public:
        template<class... Args>
        FastPimpl(Args&& ... args)
        {
            new (getStorage()) T(std::forward<Args>(args)...);
        }

        FastPimpl(const FastPimpl & rhs) { new (getStorage()) T(*rhs); }
        FastPimpl(FastPimpl&& rhs)       { new (getStorage()) T(std::move(*rhs)); }

        ~FastPimpl()
        {
            validate<sizeof(T), alignof(T)>();
            getStorage()->~T();
        }

        FastPimpl & operator=(const FastPimpl & rhs)
        {
            *getStorage() = *rhs;
            return *this;
        }

        FastPimpl & operator=(FastPimpl && rhs)
        {
            *getStorage() = std::move(*rhs);
            return *this;
        }

        T* operator->()
        {
            return getStorage();
        }

        const T* operator->()const noexcept
        {
            return getStorage();
        }

        T& operator*()
        {
            return *getStorage();
        }

        const T& operator*() const noexcept
        {
            return *getStorage();
        }
};


}// namespace

#endif // FAST_PIMPL_H
