#include <stdexcept>

#include "PointArray.h"

namespace taskPoint {

PointArray::PointArray() : size_(0), arr_(nullptr) {}

PointArray::PointArray(const Point points[], Uint n): size_(n) {
    arr_ = new Point[n];

    for (Uint i = 0; i < n; i++) {
        arr_[i] = points[i];
    }
}

PointArray::PointArray(const PointArray& other): size_(other.size_) {
    arr_ = new Point[size_];

    for (Uint i = 0; i < size_; i++) {
        arr_[i] = other.arr_[i];
    }
}

PointArray::PointArray(PointArray&& other) noexcept : arr_(nullptr), size_(0) {
    arr_ = other.arr_;
    size_ = other.size_;

    other.arr_ = nullptr;
    other.size_ = 0;
}

PointArray::~PointArray() {
    delete[] arr_;
}

void PointArray::append(const Point& pt) {
    Point* data = new Point[size_ + 1];

    for (Uint i = 0; i < size_; i++) {
        data[i] = arr_[i];
    }

    delete[] arr_;
    arr_ = data;

    arr_[size_++] = pt;
}

void PointArray::insert(const Point& pt, Uint pos) {
    if (pos > size_) {
        throw std::out_of_range("Index out of range");
        return;
    }

    Point* data = new Point[size_ + 1];

    for (Uint i = 0; i < pos; i++) {
        data[i] = arr_[i];
    }

    for (Uint i = pos; i < size_; i++) {
        data[i + 1] = arr_[i];
    }

    delete[] arr_;
    arr_ = data;
    
    size_++;
    arr_[pos] = pt;
}

void PointArray::remove(Uint pos) {
    if (pos >= size_) {
        return;
    }

    Point* data = new Point[size_ - 1];

    for (Uint i = 0; i < pos; i++) {
        data[i] = arr_[i];
    }

    for (Uint i = pos; i < size_ - 1; i++) {
        data[i] = arr_[i + 1];
    }

    delete[] arr_;

    arr_ = data;
    size_--;

    if (!size_) arr_ = nullptr;
}

void PointArray::clear() {
    delete[] arr_;

    arr_ = nullptr;
    size_ = 0;
}

PointArray::Uint PointArray::getSize() const {
    return size_;
}

void PointArray::resize(Uint n) {
    Point* data = new Point[n];

    for (Uint i = 0; i < n; i++) {
        data[i] = arr_[i];
    }

    delete[] arr_;

    arr_ = data;
    size_ = n;
}

Point& PointArray::operator[](PointArray::Uint index) {
    if (index < size_)
        return arr_[index];
    else
        throw std::out_of_range("Index out of range");
}

const Point& PointArray::operator[](PointArray::Uint index) const {
    if (index < size_)
        return arr_[index];
    else
        throw std::out_of_range("Index out of range");
}

PointArray& PointArray::operator=(const PointArray& other) {
    if (this != &other) {
        delete[] arr_;

        size_ = other.size_;
        arr_ = new Point[size_];

        for (Uint i = 0; i < size_; i++) {
            arr_[i] = other.arr_[i];
        }
    }

    return *this;
}

PointArray& PointArray::operator=(PointArray&& other) noexcept {
    // todo
    if (this != &other) {
        arr_ = other.arr_;
        size_ = other.size_;

        other.arr_ = nullptr;
        other.size_ = 0;
    }

    return *this;
}

}