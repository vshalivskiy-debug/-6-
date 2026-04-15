#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

// шаблонний клас розрідженого масиву
template <class T>
class SparseArray
{
private:
    vector<pair<int, T>> data; // індекс і значення
    int size;

public:
    // конструктор
    SparseArray(int s)
    {
        size = s;
    }

    // оператор індексації
    T& operator[](int index)
    {
        for (auto& p : data)
        {
            if (p.first == index)
                return p.second;
        }

        // якщо елемент не знайдено - створюємо новий
        data.push_back({ index, T() });
        return data.back().second;
    }

    // метод виведення елементів
    void show()
    {
        for (auto& p : data)
        {
            cout << "Iндекс: " << p.first << " Значення: " << p.second << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SparseArray<int> a(10);

    a[2] = 15;
    a[5] = 20;
    a[8] = 30;

    cout << "Integer array:" << endl;
    a.show();

    SparseArray<double> b(10);

    b[1] = 3.14;
    b[4] = 2.71;

    cout << endl << "Double array:" << endl;
    b.show();

    return 0;
}