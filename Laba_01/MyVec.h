#ifndef IDK_MYVEC_H
#define IDK_MYVEC_H


template  <typename T>
class MyVec
{
private:
    T * Array;
    int Size = 0;
public:
    MyVec()
    {
        Array = new T[Size];
    }

    void Add(T element)
    {
        T * temp = new T[Size + 1];
        for (int i = 0; i < Size; ++i)
            temp[i] = Array[i];
        temp[Size++] = element;

        delete[] Array;
        Array = temp;
    }

    T Get(int N)
    {
        if(Size <= 0) throw "Array is empty";
        if(N >=0 && N < Size)
        {
            return Array[N];
        }
        else
        {
            throw "Index is out of bounds";
        }
    }

    int GetSize()
    {
        return Size;
    }

};




#endif //IDK_MYVEC_H
