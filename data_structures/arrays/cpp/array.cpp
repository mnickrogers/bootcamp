#include "array.h"

template <typename T>
Array<T>::Array(int size) {
    _size = size;
    _capacity = size * 2;
    _data = new T[_capacity];
}

template <typename T>
Array<T>::~Array() {
    _size = 0;
    _capacity = 0;
    delete [] _data;
}

template <typename T>
size_t Array<T>::size() const {
    return 0;
}

template <typename T>
bool Array<T>::isEmpty() const {
    // If the size of the array is zero, then return true indicating that the array is empty.
    return _size == 0;
}

template <typename T>
T* Array<T>::atIndex(size_t index) const {
    assert(index < size);
    return _data[index];
}

template <typename T>
void Array<T>::push(T* element) {
    if (_size + 1 >= _capacity) {
        // Double the capacity when we hit capacity limits.
        resize(_capacity*2);
    }
    _data[_size] = element;
    _size += 1;
}

template <typename T>
void Array<T>::insert(T* element, size_t index) {
    if (_size + 1 >= _capacity) {
        // Double the capacity when we hit capacity limits.
        resize(_capacity*2);
    }

    // Size is number of elements. We want the index of the last element, so for a 0-indexed array, that's size-1.
    // Start at the end of the list and walk back, moving each element over.
    for (size_t i = _size - 1; i >= index; i--) {
        _data[i + 1] = data[i];
    }

    _data[index] = element;
}

template <typename T>
void Array<T>::preppend(T* element) {
    // Just insert the element at index 0.
    insert(element, 0);
}

template <typename T>
T* Array<T>::pop() {
    T *element = _data[_size];
    _size -= 1;
    return element;
}

template <typename T>
void Array<T>::eliminate(size_t index) {
    for (size_t i = index; i < _size - 2; i++) {
        _data[i] = _data[i + 1];
    }
    _size =- 1;
}