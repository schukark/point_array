#include <gtest/gtest.h>

#include "Point.h"

using namespace taskPoint;

TEST(Point, constructor) {
    Point p1;
    EXPECT_EQ(0, p1.getX());
    EXPECT_EQ(0, p1.getY());

    const auto x = 1;
    const auto y = 2;
    Point p2(x, y);
    EXPECT_EQ(x, p2.getX());
    EXPECT_EQ(y, p2.getY());
}

TEST(Point, set) {
    Point p1;
    const auto x = 13;
    const auto y = 37;
    p1.setX(x);
    p1.setY(y);

    EXPECT_EQ(x, p1.getX());
    EXPECT_EQ(y, p1.getY());
}

TEST(Point, shift) {
    const auto x = 1;
    const auto y = 2;
    Point p1(x, y);

    const auto xSh = 15;
    const auto ySh = 16;
    p1.shift(xSh, ySh);
    EXPECT_EQ(x + xSh, p1.getX());
    EXPECT_EQ(y + ySh, p1.getY());
}

TEST(Point, add_equals) {
    const auto x1 = 1;
    const auto y1 = 2;
    Point p1(x1, y1);

    const auto x2 = 5;
    const auto y2 = 10;
    Point p2(x2, y2);

    p1 += p2;

    EXPECT_EQ(x2, p2.getX());
    EXPECT_EQ(y2, p2.getY());

    EXPECT_EQ(x1 + x2, p1.getX());
    EXPECT_EQ(y1 + y2, p1.getY());
}

TEST(Point, sub_equals) {
    const auto x1 = 1;
    const auto y1 = 2;
    Point p1(x1, y1);

    const auto x2 = 5;
    const auto y2 = 10;
    Point p2(x2, y2);

    p1 -= p2;

    EXPECT_EQ(x1 + x2, p1.getX());
    EXPECT_EQ(y1 + y2, p1.getY());
}

TEST(Point, equals) {
    const auto x = 1;
    const auto y = 2;
    Point p1(x, y);
    Point p2(x, y);
    Point p3(x+1, y);
    Point p4(x, y+1);

    EXPECT_EQ(true, p1 == p2);
    EXPECT_EQ(false, p1 == p3);
    EXPECT_EQ(false, p2 == p4);
}