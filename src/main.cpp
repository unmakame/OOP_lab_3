#include <iostream>

#include "FigureArray.hpp"
#include "Triangle.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"

int main() {
    FigureArray figures;

    std::cout << "=== Создан треугольник ===" << std::endl;
    Figure* triangle = new Triangle();
    std::cin >> *triangle;
    figures.push_back(triangle);

    std::cout << "\n=== Создан квадрат ===" << std::endl;
    Figure* square = new Square();
    std::cin >> *square;
    figures.push_back(square);

    std::cout << "\n=== Создан прямоугольник ===" << std::endl;
    Figure* rectangle = new Rectangle();
    std::cin >> *rectangle;
    figures.push_back(rectangle);

    std::cout << "\n=== Все фигуры ===" << std::endl;
    figures.printAll();

    std::cout << "\n=== Итоговая площадь ===" << std::endl;
    std::cout << "Итоговая площадь: " << figures.totalArea() << std::endl;

    return 0;
}