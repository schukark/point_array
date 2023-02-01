#include <stdexcept>

#include "Point.h"

namespace taskPoint {
	Point::Point() : x_(0), y_(0) {}

	Point::Point(int x, int y) : x_(x), y_(y) {}

	Point& Point::operator+=(const Point& other) {
		x_ += other.x_;
		y_ += other.y_;
		return *this;
	}

	Point& Point::operator-=(const Point& other) {
		x_ -= other.x_;
		y_ -= other.y_;
		return *this;
	}

	Point Point::operator-(const Point& right) {
		return Point::Point(x_ - right.x_, y_ - right.y_);
	}

	Point operator+(const Point& left, const Point& right) {
		Point first1(left);
		return first1 += right;
	}

	Point operator-(const Point& left, const Point& right) {
		Point first1(left);
		return first1 -= right;
	}

	Point Point::operator-() {
		return Point(-x_, -y_);
	}

	bool Point::operator==(const Point& right) {
		return (x_ == right.x_) && (y_ == right.y_);
	}

	void Point::shift(int xSh, int ySh) {
		x_ += xSh;
		y_ += ySh;
	}

	int Point::getX() const { return x_; }
	int Point::getY() const { return y_; }

	void Point::setX(int x) { x_ = x; }
	void Point::setY(int y) { y_ = y; }
}
