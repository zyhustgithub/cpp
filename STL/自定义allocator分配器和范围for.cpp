#include <iostream>
#include <memory>

template <typename T, typename Allocator = std::allocator<T>>
class MyVector {
public:
    class iterator {
    public:
        iterator(T* ptr): ptr(ptr) {}
        iterator operator++()
        {
            ++ptr;
            return *this;
        }

        bool operator!=(const iterator& other) const
        {
            return ptr != other.ptr;
        }

        const T& operator*() const
        {
            return *ptr;
        }

    private:
        T* ptr;
    };

    iterator begin() const 
    {
        return iterator(m_elems);
    }
    
    iterator end() const
    {
        return iterator(m_size);
    }

public:
    MyVector() : m_elems(nullptr), m_size(nullptr), m_end(nullptr) {}
    ~MyVector()
    {
        std::cout << "~MyVector(): capacity = " << m_end - m_elems << std::endl;
        if (m_elems != nullptr) {
            while (m_elems != m_size) {
                m_alloc.destroy(--m_size);
            }
            m_alloc.deallocate(m_elems, capacity());
        }

        m_elems = nullptr;
    }

    void push_back(const T& value)
    {
        if (size() == capacity()) {
            reallocate();
        }
        m_alloc.construct(m_size++, value);
    }

    void pop_back()
    {
        if (size() > 0) {
            m_alloc.destory(--m_size);
        }
    }

    size_t size() const
    {
        return m_size - m_elems;
    }
    size_t capacity() const
    {
        return m_end - m_elems;
    }

    T& operator[](size_t idx)
    {
        return m_elems[idx];
    }

private:
    void reallocate()
    {
        size_t oldCapacity = capacity();
        size_t newCapacity = (oldCapacity == 0) ? 1 : (oldCapacity * 2);
        T* newElems = m_alloc.allocate(newCapacity);
        if (m_elems != nullptr) {
            std::cout << "reallocate(): capacity = " << m_end - m_elems << std::endl;
            std::uninitialized_copy(m_elems, m_size, newElems);
            while (m_elems != m_size) {
                m_alloc.destroy(--m_size);
            }
            m_alloc.deallocate(m_elems,oldCapacity);
        }
        m_elems = newElems;
        m_size = m_elems + oldCapacity;
        m_end = m_elems + newCapacity;
    }

private:
    static Allocator m_alloc;
    T* m_elems;
    T* m_size;
    T* m_end;
};

template <typename T, typename Allocator>
Allocator MyVector<T, Allocator>::m_alloc;

template <typename T, typename Allocator = std::allocator<T>>
void Display(MyVector<T, Allocator>& vec)
{
    std::cout << "size     = " << vec.size() << std::endl;
    std::cout << "capacity = " << vec.capacity() << std::endl;
}

int Test()
{
    MyVector<int> intVec;
    Display<int>(intVec);
    for (int idx = 1; idx <= 8; ++idx) {
        intVec.push_back(idx);
        Display<int>(intVec);
    }
    for (auto num : intVec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}

int main()
{
    Test();
    return 0;
}
