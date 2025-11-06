#include <sstream>
#include <gtest/gtest.h>

#include "FigureArray.hpp"
#include "Triangle.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"

TEST(PointTest, Basic) {
    Point p(1.5, 2.5);
    EXPECT_DOUBLE_EQ(p.x, 1.5);
    EXPECT_DOUBLE_EQ(p.y, 2.5);
}

TEST(PointTest, IO) {
    Point p;
    std::stringstream ss("3.0 4.0");
    ss >> p;

    std::stringstream out;
    out << p;
    EXPECT_EQ(out.str(), "(3, 4)");
}

TEST(TriangleTest, Area) {
    Triangle t;
    std::stringstream ss("0 0 1 0 0 1");
    t.read(ss);
    EXPECT_NEAR(t.area(), 0.5, 0.001);
}

TEST(TriangleTest, Center) {
    Triangle t;
    std::stringstream ss("0 0 3 0 0 3");
    t.read(ss);
    Point center = t.center();
    EXPECT_NEAR(center.x, 1.0, 0.001);
    EXPECT_NEAR(center.y, 1.0, 0.001);
}

TEST(SquareTest, Area) {
    Square s;
    std::stringstream ss("0 0 2 0 2 2 0 2");
    s.read(ss);
    EXPECT_NEAR(s.area(), 4.0, 0.001);
}

TEST(SquareTest, Center) {
    Square s;
    std::stringstream ss("0 0 2 0 2 2 0 2");
    s.read(ss);
    Point center = s.center();
    EXPECT_NEAR(center.x, 1.0, 0.001);
    EXPECT_NEAR(center.y, 1.0, 0.001);
}

TEST(RectangleTest, Area) {
    Rectangle r;
    std::stringstream ss("0 0 4 0 4 2 0 2");
    r.read(ss);
    EXPECT_NEAR(r.area(), 8.0, 0.001);
}

TEST(RectangleTest, Center) {
    Rectangle r;
    std::stringstream ss("0 0 4 0 4 2 0 2");
    r.read(ss);
    Point center = r.center();
    EXPECT_NEAR(center.x, 2.0, 0.001);
    EXPECT_NEAR(center.y, 1.0, 0.001);
}

TEST(FigureArrayTest, AddAndTotalArea) {
    FigureArray arr;

    Triangle* t = new Triangle();
    std::stringstream ss1("0 0 1 0 0 1");
    t->read(ss1);
    arr.push_back(t);

    EXPECT_NEAR(arr.totalArea(), 0.5, 0.001);
}

TEST(FigureArrayTest, EmptyFigureArray) {
    FigureArray arr;
    EXPECT_DOUBLE_EQ(arr.totalArea(), 0.0);
}

TEST(IntegrationTest, AllFigures) {
    FigureArray arr;

    Triangle* t = new Triangle();
    std::stringstream ss1("0 0 1 0 0 1");
    t->read(ss1);
    arr.push_back(t);

    Square* s = new Square();
    std::stringstream ss2("0 0 2 0 2 2 0 2");
    s->read(ss2);
    arr.push_back(s);

    Rectangle* r = new Rectangle();
    std::stringstream ss3("0 0 4 0 4 2 0 2");
    r->read(ss3);
    arr.push_back(r);

    double total = arr.totalArea();
    EXPECT_GT(total, 5.0);
    EXPECT_LT(total, 13.0);
}