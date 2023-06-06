#include <iostream>

template <typename T>
class Array {
public:
    Array(int size=0);
    ~Array();

    // Get the size of this array.
    size_t size() const;
    // Returns TRUE if array is emtpy; returns FALSE if array is not empty.
    bool isEmpty() const;
    // Returns the value at a given index.
    T* atIndex(size_t) const;
    // Pushes an item on the end of this array.
    void push(T* item);
    // Inserts an element at a given index.
    void insert(T* element, size_t index);
    // Inserts an element at index 0, pushing the rest of the array down.
    void preppend(T* item);
    // Removes the last element of the array then returns it.
    T* pop();
    // Deletes the element at a given index. Shrinks the array accordingly.
    void eliminate(size_t index);
    // Finds an item and returns its index. Returns -1 if it's not found.
    size_t find(T* element) const;
    // Searches for a given item, then removes it.
    void remove(T* element);

private:
    size_t          _size;
    size_t          _capacity;
    T*              _data[];

    // Resize the array.
    // If the new size is greater than the current size, then double it.
    // If the new size is less than 1/2 the current size, then shrink it by 1/2.
    void resize(size_t newCapacity);
    // Scans the array for null pointers and shrinks the array by removing them.
};