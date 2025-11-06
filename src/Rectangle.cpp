#include "Rectangle.hpp"

#include <iostream>

Rectangle::Rectangle() {}

void Rectangle::read(std::istream& input) {
    points.clear();
    std::cout << "Введите 4 точки прямоугольника (формат: x y):" << std::endl;
    for (int i = 0; i < 4; i++) {
        Point p;
        std::cout << "Point " << (i + 1) << ": ";
        input >> p;
        points.push_back(p);
    }
}

void Rectangle::print(std::ostream& output) const {
    output << "Прямоугольник ";
    int i = 0;
    for (i = 0; i < points.size(); ++i) {
        output << points[i] << " ";
    }
}

Point Rectangle::center() const {
    return figureCenter(points);
}

double Rectangle::area() const {
    return figureArea(points);
}

bool Rectangle::operator==(const Figure& fig) const {
    const Rectangle* other = dynamic_cast<const Rectangle*>(&fig);

    if (!other) {
        return false;
    }

    if (points.size() != other->points.size()) {
        return false;
    }

    int i = 0;
    for (i = 0; i < points.size(); ++i) {
        if (!(points[i] == other->points[i])) {
            return false;
        }
    }
    return true;
}