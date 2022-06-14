#include <iostream>
#include <locale.h>
using namespace std;


void main() {
    setlocale(LC_ALL, "rus");
    int line, column, nomm = 0, nom = 0;

    cout << "Введите размер массива: ";
    cin >> line >> column;
    int** array_a = new int* [line];
    for (int i = 0; i < line; i++)
        array_a[i] = new int[column];

    cout << "Заполните массив" << endl;
    for (int i = 0; i < line; i++)
        for (int j = 0; j < column; j++)
            cin >> array_a[i][j];

    cout << "Массив:" << endl;
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++)
            cout << array_a[i][j];
        cout << endl;
    }

    int minLine = 0, maxLine = 0;
    int minVal = 0, maxVal = 0;
    for (int i = 0; i < line; i++)
    {
        for (int k = 0; k < column; k++)
        {
            if (array_a[i][k] < minVal)
            {
                minLine = k;
            }

            if (array_a[i][k] > maxVal)
            {
                maxLine = k;
            }
        }
    }

    int replace = 0;
    for (int i = 0; i < line; i++)
    {
        swap(array_a[minLine][i], array_a[maxLine][i]);
    }

    cout << "Массив после обработки:" << endl;
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < column; j++)
            cout << array_a[i][j];
        cout << endl;
    }

    cout << maxLine << "  " << minLine << endl;
}