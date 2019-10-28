//
// Created by Maksym on 16-Oct-19.
//

#ifndef LABA3_DOT_H
#define LABA3_DOT_H


class Point
{
public:
    double X;
    double Y;
    bool IsOccupied;

    Point();
    Point(double x, double y);
    double DistanceTo(Point point);
    void Input();
    void Output();
};


#endif //LABA3_DOT_H
