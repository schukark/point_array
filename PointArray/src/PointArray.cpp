#include <stdexcept>

#include "PointArray.h"

namespace taskPoint {

    PointArray::PointArray() : size_(0), arr_(nullptr), capacity_(0) {}

    PointArray::PointArray(const Point points[], const Uint n): size_(n), capacity_(n) {
        arr_ = new Point[n];

        for (Uint i = 0; i < n; i++) {
            arr_[i] = points[i];
        }
    }

    PointArray::PointArray(const PointArray& other): size_(other.size_), capacity_(other.capacity_) {
        arr_ = new Point[size_];

        for (Uint i = 0; i < size_; i++) {
            arr_[i] = other.arr_[i];
        }
    }

    PointArray::PointArray(PointArray&& other) noexcept {
        arr_ = other.arr_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.arr_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    PointArray::~PointArray() {
        delete[] arr_;
    }

    void PointArray::append(const Point& pt) {
        if (capacity_ <= size_) {
            resize(capacity_ * 2 + 1);
            capacity_ = capacity_ * 2 + 1;
        }
        arr_[size_++] = pt;
    }

    void PointArray::insert(const Point& pt, const Uint pos) {
        if (pos > size_) {
            throw std::out_of_range("Index out of range");
            return;
        }

        if (capacity_ <= size_) {
            resize(capacity_ *= 2 + 1);
            capacity_++;
        }

        size_++;

        for (Uint i = size_ - 1; i > pos; i--) {
            arr_[i] = arr_[i - 1];
        }

        arr_[pos] = pt;
    }

    void PointArray::remove(const Uint pos) {
        if (pos >= size_) {
            return;
        }

        for (Uint i = pos; i < size_; i++) {
            arr_[i] = arr_[i + 1];
        }

        size_--;
        if (!size_) arr_ = nullptr;
    }

    void PointArray::clear() {
        delete[] arr_;
        size_ = 0;
        capacity_ = 0;
        arr_ = nullptr;
    }

    PointArray::Uint PointArray::getSize() const {
        return size_;
    }

    void PointArray::resize(const Uint n) {
        if (n > capacity_) {
            Point* data = new Point[n];

            for (Uint i = 0; i < size_; i++) {
                data[i] = arr_[i];
            }

            delete[] arr_;
            arr_ = data;
        }

        capacity_ = n;
    }

    Point& PointArray::operator[](const PointArray::Uint index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range!");
        }

        return arr_[index];
    }

    const Point& PointArray::operator[](const PointArray::Uint index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range!");
        }

        return arr_[index];
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
        if (this != &other) {
            arr_ = other.arr_;
            size_ = other.size_;

            other.arr_ = nullptr;
            other.size_ = 0;
        }

        return *this;
    }
}