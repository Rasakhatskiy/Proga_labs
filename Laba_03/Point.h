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
    int num;
    static int n;
    bool IsOccupied;

    Point();
    Point(double x, double y);
    double DistanceTo(Point point);
    void Input();
    void Output();
    inline bool operator ==(const Point& left) const
    {
        return left.X == X && left.Y == Y;
    }
};


#endif //LABA3_DOT_H
