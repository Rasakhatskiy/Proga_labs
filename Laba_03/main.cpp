#include <iostream>
#include <vector>
#include <limits>
#include "Point.h"

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

    std::vector<std::vector<Point>> Groups;
    //pairs
    Point* point;
    double minDistance;

    //Points main loop
    for(auto &i : Points)
    {
        if(i.IsOccupied) continue;

        point = nullptr;
        minDistance = std::numeric_limits<double>::max();

        //find min distance
        for(auto &j : Points)
        {
            if(j.IsOccupied) continue;
            double distance = i.DistanceTo(j);
            if(distance < minDistance)
            {
                minDistance = distance;
                point = &j;
            }
        }
        //create pair
        if(point != nullptr)
        {
            std::vector<Point> pair;
            pair.push_back(i);
            pair.push_back(*point);
            Groups.push_back(pair);

            i.IsOccupied = true;
            point->IsOccupied = true;

            point = nullptr;
        }
    }

    for (auto &i : Groups)
    {
        for(auto &j : i)
        {
            j.Output();
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    system("pause");
    return 0;
}