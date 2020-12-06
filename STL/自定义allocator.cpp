/*
 * Copyright (C) 2020-2020 RTFSC All rights reserved.
 * Author:zengyong
 * Date:2020-12-06
 * Description:具体接口实现
 */

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <vector>

namespace MyAllocator {

template<class T>
inline T* _allocate(ptrdiff_t size, T*)
{
    std::new_handler oldHandler = std::set_new_handler(nullptr);
    T* tem = static_cast<T*>(::operator new(static_cast<size_t>(size * sizeof(T))));
    std::set_new_handler(oldHandler);
    return tem;
}

template<class T>
inline void _deallocate(T* buffer)
{
    ::operator delete(buffer);
} 

template<class T1, class T2>
inline void _construct(T1* p, const T2& val)
{
   new (p) T1(val);
}

template<class T>
inline void _destroy(T* p)
{
    p->~T();
}

template<class T>
class allocator {
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    // rebind alloctor
    template<class U>
    struct rebind {
        typedef allocator<U> other;
    };

    pointer allocate(size_type n, const void* hint = nullptr)
    {
        std::cout << "allocate()" << std::endl;
        return _allocate((difference_type)n, (pointer)0);
    }

    void deallocate(pointer p, size_type n)
    {
        std::cout << "deallocate()" << std::endl;
        _deallocate(p);
    }

    void construct(pointer p, const_reference value)
    {
        std::cout << "construct()" << std::endl;
        _construct(p, value);
    }

    void destroy(pointer p)
    {
        std::cout << "destroy()" << std::endl;
        _destroy(p);
    }

    pointer address(reference x)
    {
        std::cout << "address()" << std::endl;
        return static_cast<pointer>(&x);
    }

    const_pointer const_address(const_reference x)
    {
        std::cout << "const_address()" << std::endl;
        return static_cast<const_pointer>(&x);
    }

    size_type max_size() const
    {
        std::cout << "max_size()" << std::endl;
        return size_type(UINT_MAX / sizeof(value_type));
    }
};

}

class Test {
public:
    int x;
    Test(int a2 = 0) : x(a2) {}
    ~Test() {}
};

int main()
{
    std::cout << "--------------------------------------" << std::endl;
    MyAllocator::allocator<int> a1;
    int *p = a1.allocate(1);
    *p = 1;
    std::cout << *p << std::endl;
    std::cout << *(a1.address(*p)) << std::endl;
    std::cout << a1.max_size() << std::endl;
    a1.deallocate(p, 1);

    std::cout << "--------------------------------------" << std::endl;
    Test *t = new Test;
    MyAllocator::allocator<Test> a2;
    int x = 4;
    a2.construct(t, x);
    std::cout << t->x << std::endl;
    a2.destroy(t);

    std::cout << "--------------------------------------" << std::endl;
    std::vector<int, MyAllocator::allocator<int>> myVec;
    myVec.push_back(1);
    std::cout << myVec.back() << std::endl;
    return 0;
}
