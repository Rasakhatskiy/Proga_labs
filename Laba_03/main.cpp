#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include "Point.h"

std::vector<Point> RecApeend(Point* point, std::vector<Point>* points, std::vector<Point>* group);
double average;


int main() {

    int N;
    std::cout << "Enter number of points" << std::endl;
    std::cin >> N;

    std::vector<Point> Points;
    for (int i = 0; i < N; ++i)
    {
        Point p;
        p.Input();
        Points.push_back(p);
    }

    average = 0;
    {
        int n = 0;
        for (int i = 0; i < Points.size(); ++i) {
            for (int j = i + 1; j < Points.size(); ++j) {
                average += Points[i].DistanceTo(Points[j]);
                n++;
            }
        }
        average /= 1.0 * n;
        //average = std::pow(average, 1.0 / 2);
        average /= 3.0;
    }

    std::vector<std::vector<Point>> Groups;
    std::vector<Point> group;

    for (int i = 0; i < Points.size(); i++)
    {
        if(Points[i].IsOccupied) continue;
        group.clear();
        group.push_back(Points[i]);
        group = RecApeend(&Points[i], &Points, &group);
        int size = group.size();
        if(group.size() > 1)
        {
            Groups.push_back(group);
        }
        else
        {
            Points[i].IsOccupied = false;
        }
    }

    for(auto &i : Points)
    {
        if(!i.IsOccupied)
        {
            std::vector<Point> vec;
            vec.push_back(i);
            Groups.push_back(vec);
        }
    }

    int n = 1;
    for(auto &i : Groups)
    {
        std::cout << "Group " << n++ << std::endl;
        for (auto &j : i)
        {
            std::cout << "\t";
            j.Output();
            std::cout << "\n";
        }
        std::cout << std::endl;
    }

    system("pause");
    return 0;
}

std::vector<Point> RecApeend(Point* point, std::vector<Point>* points, std::vector<Point>* group)
{
    for (auto &i : *points)
    {
        Point* ppoint = nullptr;

        if(i.IsOccupied) continue;
        if(i == *point) continue;

        double distance = point->DistanceTo(i);
        if(distance <= average)
        {
            ppoint = &i;
        }
        if(ppoint != nullptr)
        {
            ppoint->IsOccupied = true;
            point->IsOccupied = true;
            group->push_back(*ppoint);
            *group = RecApeend(ppoint, points, group);
            break;
        }

    }
    return *group;
}