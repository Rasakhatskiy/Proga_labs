/*
 * 8. Знайти всі пари "сусідніх" простих чисел, що не перевищують N, представлення яких у трійковій системі числення один
 * з одного утримуються шляхом запису цифр в зворотньому напряму (5 і 7, тобто 12:3 та 21:3)
 */

#include <iostream>
#include "MyVec.h"

MyVec<int> PrimeNumbers(int N);
std::string ToTrheeSystem(int decimal);
std::string ReverseString(std::string source);

int main() {


    int N;
    std::cout << "Enter N: ";
    std::cin >> N;

    if(N <= 1)
    {
        std::cout << "N have to be > 1\n";
        system("pause");
        return 0;
    }

    auto vector = PrimeNumbers(N);

    MyVec<std::pair<int, int>> resultPairs;

    int previousInt = vector.Get(0);
    std::string previousString = ToTrheeSystem(vector.Get(0));


    for (int i = 1; i < vector.GetSize() - 1; ++i)
    {
        int num = vector.Get(i);
        std::string threeSys = ToTrheeSystem(num);
        std::string reversedString = ReverseString(threeSys);

        if(previousString == reversedString)
            resultPairs.Add(std::pair<int, int>(previousInt, num));

        previousInt = num;
        previousString = threeSys;
    }


    std::cout << "Pairs from 1 to " << N << " :\n";
    for (int i = 0; i < resultPairs.GetSize(); ++i)
        std::cout << resultPairs.Get(i).first << " " << resultPairs.Get(i).second << std::endl;


    system("pause");
    return 0;
}

MyVec<int> PrimeNumbers(int N)
{
    MyVec<int> vector = MyVec<int>();
    for (int i = 1; i <= N; ++i)
    {
        int j;
        for (j = 2; j <= (i / 2); ++j)
        {
            if(i % j == 0)
            {
                j = i;
                break;
            }
        }
        if(i != j)
        {
            vector.Add(i);
        }
    }
    return vector;
}

std::string ToTrheeSystem(int decimal)
{
    std::string res = "";
    while(decimal > 0)
    {
        int t = decimal % 3;
        res  = std::to_string(t) + res;
        decimal /= 3;
    }
    return res;
}

std::string ReverseString(std::string source)
{
    std::string res;
    for (int i = source.length() - 1; i >= 0 ; --i)
    {
        res += source[i];
    }
    return res;
}
