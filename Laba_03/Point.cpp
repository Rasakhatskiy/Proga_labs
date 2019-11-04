#include <cmath>
#include <iostream>
#include "Point.h"

int Point::n = 0;

double Point::DistanceTo(Point point)
{
    return std::sqrt(std::pow(point.X - this->X, 2) + std::pow(point.Y - this->Y, 2));
}


void Point::Input()
{
    std::cout << "Enter X & Y:";
    std::cin >> X >> Y;
    num = ++n;
    IsOccupied = false;
}

void Point::Output()
{
    std::cout << num <<  "(" << X << ";" << Y << ")";
}


Point::Point()
{
    X = 0;
    Y = 0;
    IsOccupied = false;
}

Point::Point(double x, double y)
{
    this->X = x;
    this->Y = y;
    IsOccupied = false;
}

