#include <stdexcept>

#include "Point.h"

namespace taskPoint
{
	Point::Point(int x, int y) : x_(x), y_(y)
	{
	}

	Point& Point::operator+=(const Point& other)
	{
		throw std::runtime_error("Not implemented!");
	}

	Point& Point::operator-=(const Point& other)
	{
		throw std::runtime_error("Not implemented!");
	}

	Point Point::operator-(const Point& right)
	{
		throw std::runtime_error("Not implemented!");
	}

	Point operator+(const Point& left, const Point& right)
	{
		Point first1(left);
		return first1 += right;
	}

	Point operator-(const Point& left, const Point& right)
	{
		Point first1(left);
		return first1 -= right;
	}

	Point Point::operator-()
	{
		throw std::runtime_error("Not implemented!");
	}

	bool Point::operator==(const Point& right)
	{
		throw std::runtime_error("Not implemented!");
	}


	void Point::shift(int xSh, int ySh)
	{
		// todo
		throw std::runtime_error("Not implemented!");
	}


	int Point::getX() const
	{
		return x_;
	}

	int Point::getY() const
	{
		return y_;
	}

	void Point::setX(int x)
	{
		x_ = x;
	}

	void Point::setY(int y)
	{
		y_ = y;
	}
}
