/*
 * Знайти і підключити до проекту сторонню бібліотеку для роботи з зображеннями.
 * Зчитати деяке зображення та: повернути його на 90 градусів за годинниковою стрілкою і зберегти;
 * знайти середнє значення кольору всіх пікселів зображення.
 */



#include <iostream>
#include "Magick++.h"

void Rotate(std::string path);
std::string GetExtension(std::string path);

int main()
{
    std::string path;
    while(std::cin >> path)
    {
        Rotate(path);
    }
    return 0;
}

//void Rotate(std::string path)
//{
//    std::cout << "Rotating " + path + "..." << std::endl;
//    Magick::Image image;
//    try
//    {
//        image.read(path);
//        image.rotate(90.0);
//
//        std::string ext = GetExtension(path);
//        path = path.substr(0, path.length() - ext.length());
//        path += "_rotated" + ext;
//
//        image.write(path);
//    }
//    catch(std::exception &error_ )
//    {
//        std::cout << "Caught exception: " << error_.what() << std::endl;
//        return;
//    }
//}

std::string GetExtension(std::string path)
{
    for (int i = path.length() - 1; i >= 0 ; --i)
    {
        if(path[i] == '.')
            return path.substr(i, path.length() - 1);
    }
    return "";
}