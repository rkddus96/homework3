#include <iostream>

using namespace std;

template <typename T>
class SimpleVector
{
private:
    T* data;
    int currentSize;
    int currentCapacity;

public:
    void resize(int newCapacity)
    {
        if (newCapacity > currentCapacity)
        {
            T* newData = new T[newCapacity];
            for (int i = 0; i < currentSize; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            currentCapacity = newCapacity;
        }

    }

    SimpleVector() : currentSize(0), currentCapacity(10)
    {
        data = new T[currentCapacity];
    }

    SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity)
    {
        data = new T[currentCapacity];
    }

    SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity)
    {
        data = new T[currentCapacity];
        for (int i = 0; i < currentsize; i++)
        {
            data[i] = other.data[i];
        }
    }

    ~SimpleVector()
    {
        delete[] data;
    }

    void push_back(const T& value)
    {
        if (currentSize == currentCapacity)
        {
            currentCapacity = 5 + currentCapacity;
            resize(currentCapacity);
        }

        data[currentSize++] = value;
    }

    void pop_back()
    {
        if (currentSize != 0)
        {
            currentSize--;
        }

    }

    int size() const 
    {
        return currentSize;
    }

    int capacity() const 
    {
        return currentCapacity;
    }

    void sortData()
    {
        sort(data, data + currentSize);
    }

    T& operator[] (int index)
    {
        return data[index];
    }

};

int main()
{

}