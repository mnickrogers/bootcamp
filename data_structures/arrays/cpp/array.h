#include <iostream>
#include <ostream>

template <typename T>
class Array {
public:
    Array(size_t size=0) {
        _size = size;
        _capacity = size * 2;
        _data = new T[_capacity];
    }
    ~Array() {
        _size = 0;
        _capacity = 0;
        delete [] _data;
    }

    // Get the size of this array.
    size_t size() const {
        return 0;
    }

    // Returns TRUE if array is emtpy; returns FALSE if array is not empty.
    bool isEmpty() const {
        // If the size of the array is zero, then return true indicating that the array is empty.
        return _size == 0;
    }

    // Returns the value at a given index.
    T* atIndex(size_t) const {
        assert(index < _size);
        return _data[index];
    }

    // Pushes an item on the end of this array.
    void push(T* item) {
        if (_size + 1 >= _capacity) {
            // Double the capacity when we hit capacity limits.
            resize(_capacity*2);
        }
        _data[_size] = element;
        _size += 1;
    }

    // Inserts an element at a given index.
    void insert(T* element, size_t index) {
        if (_size + 1 >= _capacity) {
            // Double the capacity when we hit capacity limits.
            resize(_capacity*2);
        }

        // Size is number of elements. We want the index of the last element, so for a 0-indexed array, that's size-1.
        // Start at the end of the list and walk back, moving each element over.
        for (size_t i = _size - 1; i >= index; i--) {
            _data[i + 1] = _data[i];
        }

        _data[index] = element;
    }

    // Inserts an element at index 0, pushing the rest of the array down.
    void preppend(T* item) {
        // Just insert the element at index 0.
        insert(element, 0);
    }

    // Removes the last element of the array then returns it.
    T* pop() {
        T *element = _data[_size];
        _size -= 1;
        return element;
    }

    // Deletes the element at a given index. Shrinks the array accordingly.
    void eliminate(size_t index) {
        for (size_t i = index; i < _size - 2; i++) {
            _data[i] = _data[i + 1];
        }
        _size =- 1;
    }

    // Finds an item and returns its index. Returns -1 if it's not found.
    size_t find(T* element) const {
        size_t index(-1);
        for (size_t i = 0; i < _size; i++) {
            if (_data[i] == element) {
                index = i;
                // We will return the index of the first match.
                break;
            }
        }
        return index;
    }

    // Searches for a given item, then removes it.
    void remove(T* element) {
        // 1st, find the index for this element. If the index is -1, return.
        size_t index = find(element);

        if (index == -1) {
            return;
        }

        // 2nd, remove the element at this index.
        eliminate(index);
    }

    // Override the index operator.
    T& operator[](size_t index) const {
        assert(index >= 0 && index <= _size);
        return _data[index];
    }

private:
    size_t          _size;
    size_t          _capacity;
    T*              _data[];

    // Resize the array.
    // If the new size is greater than the current size, then double it.
    // If the new size is less than 1/2 the current size, then shrink it by 1/2.
    void resize(size_t newCapacity) {
        T* newArray = new T[newCapacity];
        for (size_t i = 0; i < newCapacity; i++) {
            newArray[i] = _data[i];
        }
        delete [] _data;
        _data = newArray;
    }

    // Scans the array for null pointers and shrinks the array by removing them.
    // Basically garbage collection.
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array) {
    for (size_t i = 0; i < array->size(); i++) {
        os << array[i] << " ";
    }
    os << std::endl;
    return os;
}