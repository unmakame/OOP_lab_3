#include "Square.hpp"

#include <iostream>

Square::Square() {}

void Square::read(std::istream& input) {
    points.clear();
    std::cout << "Введите 4 точки квадрата (формат: x y):" << std::endl;
    for (int i = 0; i < 4; i++) {
        Point p;
        std::cout << "Point " << (i + 1) << ": ";
        input >> p;
        points.push_back(p);
    }
}

void Square::print(std::ostream& output) const {
    output << "Квадрат ";
    int i = 0;
    for (i = 0; i < points.size(); ++i) {
        output << points[i] << " ";
    }
}

Point Square::center() const {
    return figureCenter(points);
}

double Square::area() const {
    return figureArea(points);
}

bool Square::operator==(const Figure& fig) const {
    const Square* other = dynamic_cast<const Square*>(&fig);

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