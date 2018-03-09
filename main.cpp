#include <iostream>
using namespace std;

template <typename T> class m_vector
{
private:
    T *array;
    int capacity;
public:
    void push_back(T data)
    {
        T *result = new T[++this->capacity];

        for(int i = 0; i < this->capacity; i++)
        {
            if(i != this->capacity-1)
            {
                result[i] = this->array[i];
            }
            else
            {
                result[i] = data;
                break;
            }
        }
        delete[] this->array;
        this->array = result;
    }

    T pop_back()
    {
        return this->popIndex(this->capacity-1);
    }

    void clear()
    {
        while(capacity != 0)
            delete [] array;

    capacity = 0;
    array = new T[capacity];
    }

    T operator [](int index)
    {
        return this->array[index];
    }

    int size()
    {
        return this->capacity;
    }

    void pushIndex(T data, int i)
    {
        int oldSize = this->capacity;

        if (i > capacity)
            throw Exception();
        else    {

        this->capacity = ++this->capacity;

        T *result = new T[this->capacity];

        int arrIndex = 0;

        for(int index2 = 0; index2 < this->capacity; index2++)
        {
            if(index2 == i)
            {
                result[index2] = data;
                continue;
            }

            if(arrIndex != oldSize)
            {
                result[index2] = this->array[arrIndex++];
            }
        }
        delete[] this->array;
        this->array = result;
                }
    }

    T popIndex(int i)
    {
        if (i > capacity)
            throw Exception();
        else    {
        T *result = new T[--this->capacity];

        T resItem;

        int resIndex = 0;

        for(int index2 = 0; index2 < this->capacity+1; index2++)
        {
            T item = this->array[index2];

            if(i == index2)
            {
                resItem = item;
                continue;
            }
            result[resIndex++] = this->array[index2];
        }
        delete[] this->array;
        this->array = result;
        return resItem;
            }
    }

    m_vector()
    {
        this->capacity = 0;
        this->array = new T[this->capacity];
    }
    class Exception{};
};

void printVector(m_vector<int> vector)
{
    int size = vector.size();

    if(size == 0)
    {
        cout << "Vector is empty!" << endl;
        return;
    }

    for(int i = 0; i < vector.size(); i++)
    {
        cout << i << " Element: " << vector[i] << endl;
    }
    cout << "-----" << endl;
}

void printElement(m_vector<int> vector, int i){
    cout << i << " Element: " << vector[i] << endl << "-----" << endl;
}


int main()
{
    m_vector<int> vector;
    int size;

    cout << "Capacity: " << endl;
    cin >> size;


    for(int i = 0; i < size; vector.push_back(rand() % 100 + i++));
    printVector(vector);

    vector.push_back(5000);
    printVector(vector);

    try
    {
    vector.pushIndex(4000, 5);
    printVector(vector);
    }
    catch(m_vector<int>::Exception)
    {
        cout << "Index not found" << endl;
    }

    try
    {
    vector.popIndex(4);
    printVector(vector);
    }
    catch(m_vector<int>::Exception)
    {
        cout << "Index not found" << endl;
    }

    try
    {
    vector.pushIndex(4, 7);
    printVector(vector);
    }
    catch(m_vector<int>::Exception)
    {
        cout << "Index not found" << endl;
    }

    return 0;
}
