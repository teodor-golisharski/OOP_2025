#include "Container.h"
#include <utility>

void Container::copyFrom(const Container& other)
{
    size = other.size;
    capacity = other.capacity;

    data = new Person * [capacity] {nullptr };

    for (size_t i = 0; i < other.size; i++)
    {
        data[i] = new Person(*other.data[i]);
    }
}

void Container::moveFrom(Container&& other)
{
    data = other.data;
    other.data = nullptr;

    capacity = other.capacity;
    size = other.size;

    other.capacity = 0;
    other.size = 0;
}

void Container::free()
{
    for (size_t i = 0; i < size; i++)
    {
        delete data[i];
    }
    delete[] data;
}

void Container::resize(size_t newSize)
{
    Person** newDataPtr = new Person * [newSize] {nullptr};

    for (int i = 0; i < capacity; i++)
        newDataPtr[i] = data[i];

    delete[] data;
    data = newDataPtr;

    capacity = newSize;
}

Container::Container()
{
    capacity = 8;
    data = new Person * [capacity] {nullptr};
    size = 0;
}

Container::Container(const Container& other)
{
    copyFrom(other);
}

Container& Container::operator=(const Container& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Container::Container(Container&& other) noexcept
{
    moveFrom(std::move(other));
}

Container& Container::operator=(Container&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Container::~Container()
{
    free();
}

void Container::add(const Person& obj)
{
    if (capacity == size)
        resize(capacity * 2);

    data[size++] = new Person(obj);
}
