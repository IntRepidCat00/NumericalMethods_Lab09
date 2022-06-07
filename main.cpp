#include "Polynom.h"

int main()
{
    Polynom p1("Linear Polynom", 1), p2("Square Polynom", 2), p3("Cubic Polynom", 3);
    double point{0};
    std::cout << "Enter point" << std::endl;
    std::cin >> point;
    p1.printTable();
    std::cout << "=== " << p1.getName() << " ===" << std::endl;
    p1.calcPolynom();
    p1.printPolynom();
    p1.polyInPoint(point);
    std::cout << "=== " << p2.getName() << " ===" << std::endl;
    p2.calcPolynom();
    p2.printPolynom();
    p2.polyInPoint(point);
    std::cout << "=== " << p3.getName() << " ===" << std::endl;
    p3.calcPolynom();
    p3.printPolynom();
    p3.polyInPoint(point);
    return 0;
}
