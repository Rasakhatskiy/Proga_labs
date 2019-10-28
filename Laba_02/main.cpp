#include <iostream>
#include <algorithm>

std::string Sum(std::string s1, std::string s2);
std::string Sub(std::string s1, std::string s2);
bool IsSmaller(std::string s1, std::string s2);
std::string Mul(std::string s1, std::string s2);
std::string Div(std::string s1, std::string s2);

const int MAX_PRECISION = 20;

int main() {
    std::string str1, str2;
    char operation;

    std::cout << "N1 : ";
    std::cin >> str1;
    std::cout << "OP : ";
    std::cin >> operation;
    std::cout << "N2 : ";
    std::cin >> str2;
    std::string result;
    switch (operation)
    {
        case '+': result = Sum(str1, str2); break;
        case '-': result = Sub(str1, str2); break;
        case '*': result = Mul(str1, str2); break;
        case '/': result = Div(str1, str2); break;
        default: result = "unknown operation";
    }
    std::cout << result << std::endl;

    system("pause");
    return 0;
}

std::string Sum(std::string s1, std::string s2)
{

    bool firstNeg  = (s1[0] == '-');
    bool secondNeg = (s2[0] == '-');

    s1.erase(std::remove(s1.begin(), s1.end(), '-'), s1.end());
    s2.erase(std::remove(s2.begin(), s2.end(), '-'), s2.end());

    if(!firstNeg && secondNeg)
        return Sub(s1, s2);
    if(firstNeg && !secondNeg)
        return Sub(s2, s1);
    if(firstNeg && secondNeg)
        return "-" + Sum(s1, s2);

    std::string integerPartFirst;
    std::string integerPartSecond;

    std::string floatPartFirst;
    std::string floatPartSecond;

    int pointPos = 0;
    for (int i = 0; i < s1.length(); ++i)
    {
        if(s1[i] == '.')
        {
            pointPos = i; break;
        }
        integerPartFirst += s1[i];
        pointPos = i + 1;
    }
    for (int i = pointPos + 1; i < s1.length(); ++i)
    {
        floatPartFirst += s1[i];
    }

    for (int i = 0; i < s2.length(); ++i)
    {
        if(s2[i] == '.')
        {
            pointPos = i; break;
        }
        integerPartSecond += s2[i];
        pointPos = i + 1;
    }
    for (int i = pointPos + 1; i < s2.length(); ++i)
    {
        floatPartSecond += s2[i];
    }

    while (integerPartFirst.length() > integerPartSecond.length()) integerPartSecond = "0" + integerPartSecond;
    while (integerPartSecond.length() > integerPartFirst.length()) integerPartFirst = "0" + integerPartFirst;
    while (floatPartFirst.length() > floatPartSecond.length()) floatPartSecond += "0";
    while (floatPartSecond.length() > floatPartFirst.length()) floatPartFirst += "0";


    std::reverse(integerPartFirst.begin(), integerPartFirst.end());
    std::reverse(integerPartSecond.begin(), integerPartSecond.end());

    std::reverse(floatPartFirst.begin(), floatPartFirst.end());
    std::reverse(floatPartSecond.begin(), floatPartSecond.end());

    std::string result;

    bool add = false;
    for (int i = 0; i < floatPartFirst.length(); ++i)
    {
        int first = floatPartFirst[i] - '0';
        int second = floatPartSecond[i] - '0';
        int res = add ? first + second + 1 : first + second;
        if(res > 9)
        {
            add = true;
            result += std::to_string(res - 10);
        }
        else
        {
            add = false;
            result += std::to_string(res);
        }
    }
    result += '.';
    for (int i = 0; i < integerPartFirst.length(); ++i)
    {
        int first = integerPartFirst[i] - '0';
        int second = integerPartSecond[i] - '0';
        int res = add ? first + second + 1 : first + second;
        if(res > 9)
        {
            add = true;
            result += std::to_string(res - 10);
        }
        else
        {
            add = false;
            result += std::to_string(res);
        }
    }
    if(add) result += "1";

    while (result[result.length() - 1] == '0')
        result = result.substr(0, result.length() - 1);

    std::reverse(result.begin(), result.end());

    while (result[result.length() - 1] == '0' )
        result = result.substr(0, result.length()-1);

    if (result[result.length() - 1] == '.')
        result = result.substr(0, result.length()-1);


    if(result.length() == 0) result = "0";
    return result;
}

std::string Sub(std::string s1, std::string s2)
{
    bool firstNeg = (s1[0] == '-');
    bool secondNeg = (s2[0] == '-');

    s1.erase(std::remove(s1.begin(), s1.end(), '-'), s1.end());
    s2.erase(std::remove(s2.begin(), s2.end(), '-'), s2.end());

    if(!firstNeg && secondNeg)
        return Sum(s1, s2);
    if(firstNeg && !secondNeg)
        return "-" + Sum(s1, s2);

    std::string integerPartFirst;
    std::string integerPartSecond;

    std::string floatPartFirst;
    std::string floatPartSecond;

    int pointPos = 0;
    for (int i = 0; i < s1.length(); ++i)
    {
        if(s1[i] == '.')
        {
            pointPos = i; break;
        }
        integerPartFirst += s1[i];
        pointPos = i + 1;
    }
    for (int i = pointPos + 1; i < s1.length(); ++i)
    {
        floatPartFirst += s1[i];
    }

    for (int i = 0; i < s2.length(); ++i)
    {
        if(s2[i] == '.')
        {
            pointPos = i; break;
        }
        integerPartSecond += s2[i];
        pointPos = i + 1;
    }
    for (int i = pointPos + 1; i < s2.length(); ++i)
    {
        floatPartSecond += s2[i];
    }

    bool firstBig;

    if(!IsSmaller(integerPartFirst, integerPartSecond) && !IsSmaller(integerPartSecond, integerPartFirst))
        if(!IsSmaller(floatPartFirst, floatPartSecond) && !IsSmaller(floatPartSecond, floatPartFirst)) firstBig = true;
        else firstBig = IsSmaller(floatPartSecond, floatPartFirst);
    else
        firstBig = IsSmaller(integerPartSecond, integerPartFirst);

    if(firstNeg && secondNeg)
        if(firstBig)
            return "-" + Sub(s2, s1);
        else
            return Sub(s2, s1);

    if(!firstBig)
        return "-" + Sub(s2, s1);

    while (integerPartFirst.length() > integerPartSecond.length()) integerPartSecond = "0" + integerPartSecond;
    while (integerPartSecond.length() > integerPartFirst.length()) integerPartFirst = "0" + integerPartFirst;
    while (floatPartFirst.length() > floatPartSecond.length()) floatPartSecond += "0";
    while (floatPartSecond.length() > floatPartFirst.length()) floatPartFirst += "0";


    std::reverse(integerPartFirst.begin(), integerPartFirst.end());
    std::reverse(integerPartSecond.begin(), integerPartSecond.end());

    std::reverse(floatPartFirst.begin(), floatPartFirst.end());
    std::reverse(floatPartSecond.begin(), floatPartSecond.end());

    std::string result;

    bool take = false;
    for (int i = 0; i < floatPartFirst.length(); ++i)
    {
        int first = floatPartFirst[i] - '0';
        int second = floatPartSecond[i] - '0';
        int res = take ? first - 1 : first;
        if (res == -1)
        {
            res = 9;
            take = true;
            result += std::to_string(res - second);
        }
        else
        {
            if(res < second)
            {
                result += std::to_string(res + 10 - second);
                take = true;
            }
            else
            {
                result += std::to_string(res - second);
                take = false;
            }
        }
    }
    result += '.';
    for (int i = 0; i < integerPartFirst.length(); ++i)
    {
        int first = integerPartFirst[i] - '0';
        int second = integerPartSecond[i] - '0';
        int res = take ? first - 1 : first;
        if (res == -1)
        {
            res = 9;
            take = true;
            result += std::to_string(res - second);
        }
        else
        {
            if(res < second)
            {
                result += std::to_string(res + 10 - second);
                take = true;
            }
            else
            {
                result += std::to_string(res - second);
                take = false;
            }
        }
    }
    while (result[result.length() - 1] == '0')
        result = result.substr(0, result.length() - 1);

    std::reverse(result.begin(), result.end());

    while (result[result.length() - 1] == '0' )
        result = result.substr(0, result.length()-1);

    if (result[result.length() - 1] == '.')
        result = result.substr(0, result.length()-1);

    if(result.length() == 0) result = "0";
    return result;
}

std::string Mul(std::string s1, std::string s2)
{
    bool firstNeg  = (s1[0] == '-');
    bool secondNeg = (s2[0] == '-');

    s1.erase(std::remove(s1.begin(), s1.end(), '-'), s1.end());
    s2.erase(std::remove(s2.begin(), s2.end(), '-'), s2.end());

    if((firstNeg && !secondNeg) ||(!firstNeg && secondNeg))
        return "-" + Mul(s1, s2);

    if(firstNeg && secondNeg)
        return Mul(s1, s2);

    int firstDotPosition = 0;
    int secondDotPosition = 0;
    for (int i = 0; i < s1.length(); ++i)
    {
        if(s1[i] == '.')
        {
            firstDotPosition = s1.length() - 1 - i;
            break;
        }
    }
    for (int i = 0; i < s2.length(); ++i)
    {
        if(s2[i] == '.')
        {
            secondDotPosition = s2.length() - 1 - i;
            break;
        }

    }
    s1.erase(std::remove(s1.begin(), s1.end(), '.'), s1.end());
    s2.erase(std::remove(s2.begin(), s2.end(), '.'), s2.end());

    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());

    std::string result;
    for (int i = 0; i < s1.length() + s2.length(); ++i) result += (char)0;

    while(s1.length() > s2.length()) s2 += "0";
    while(s2.length() > s1.length()) s1 += "0";



    for (char &i : s1) i -= '0';
    for (char &i : s2) i -= '0';

    for (int i = 0; i < s1.length(); ++i)
    {
        int add = 0;
        for (int j = 0; j < s2.length(); ++j)
        {
            int first = s1[i];
            int second = s2[j];
            int third = result[i + j];
            int res = first * second + add;
            if(res > 9)
            {
                add = res / 10;
                res %= add * 10;
            }
            else
            {
                add = 0;
            }
            third += res;
            if(third > 9)
            {
                add += 1;
                third -= 10;
            }
            result[i + j] = (char)(third);
        }
        int t = result[i + s2.length()] + add;
        if(t > 9)
        {
            int r = t / 10;
            result[i + s2.length() + 1] = (char)r;
            t /= r * 10;
        }
        result[i + s2.length()] = (char)t;
    }
    for (char &i : result) i += '0';


    int dotpos = firstDotPosition + secondDotPosition;

    if(dotpos != result.length())
    {
        result.insert((unsigned)dotpos, 1, '.');
        while (result[result.length() - 1] == '0' )
        {
            if(result[result.length() - 2] != '.')
                result = result.substr(0, result.length() - 1);
            else break;
        }

        std::reverse(result.begin(), result.end());

        while (result[result.length() - 1] == '0' )
            result = result.substr(0, result.length() - 1);

        if(result[result.length() - 1] == '.' )
            result = result.substr(0, result.length() - 1);
    }
    else
    {
        while (result[result.length() - 1] == '0' )
            result = result.substr(0, result.length() - 1);
        std::reverse(result.begin(), result.end());
    }

    return result;
}

std::string Div(std::string s1, std::string s2)
{
    bool firstNeg  = (s1[0] == '-');
    bool secondNeg = (s2[0] == '-');

    s1.erase(std::remove(s1.begin(), s1.end(), '-'), s1.end());
    s2.erase(std::remove(s2.begin(), s2.end(), '-'), s2.end());

    if(Sub(s2, "1") == "0")
    {
        if(firstNeg && secondNeg) return s1;
        if(!firstNeg && secondNeg) return "-" + s1;
        if(firstNeg && !secondNeg) return "-" + s1;
        if(!firstNeg && !secondNeg) return s1;
    }

    if(Sub(s2, "0") == "0")
        return "NaN";

    if(Sub(s1, "0") == "0")
        return "0";

    if((firstNeg && !secondNeg) ||(!firstNeg && secondNeg))
        return "-" + Div(s1, s2);

    if(firstNeg && secondNeg)
        return Div(s1, s2);



    while (s1[0] == '0' ) s1 = s1.substr(1, s1.length() - 1);
    while (s2[0] == '0' ) s2 = s2.substr(1, s2.length() - 1);


    int usedPrecision = 0;
    std::string result = "0";
    std::string firstPart = "0";
    std::string secondPart = "0";

    bool remnant = false;
    while (true)
    {
        std::string buffer = Sub(s1, s2);
        if(buffer[0] == '-')
        {
            remnant = true;
            break;
        }

        firstPart = Sum(firstPart, "1");
        s1 = buffer;
        if(s1 == "0") break;
    }

    int zeros = 0;
    bool stop = false;
    bool countZeros = true;
    while(usedPrecision < MAX_PRECISION)
    {
        s1 = Mul(s1, "10");
        while (true)
        {
            std::string buffer = Sub(s1, s2);
            if(buffer[0] == '-')
                break;

            countZeros = false;
            secondPart = Sum(secondPart, "1");
            s1 = buffer;
            if(s1 == "0")
            {
                stop = true;
                break;
            }
        }
        if (stop) break;
        if (countZeros) zeros++;
        secondPart = Mul(secondPart, "10");
        usedPrecision++;
    }
    for (int i = 0; i < zeros; ++i)
    {
        secondPart = "0" + secondPart;
    }

    result = firstPart + "." + secondPart;

    while (result[result.length() - 1] == '0' ) result = result.substr(0, result.length() - 1);
    if (result[result.length() - 1] == '.' ) result = result.substr(0, result.length() - 1);

    return result;
}

bool IsSmaller(std::string s1, std::string s2)
{
    int n1 = s1.length(), n2 = s2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i=0; i<n1; i++)
        if (s1[i] < s2[i])
            return true;
        else if (s1[i] > s2[i])
            return false;

    return false;
}