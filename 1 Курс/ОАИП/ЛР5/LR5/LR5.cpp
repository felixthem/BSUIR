#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int sum(int* a, int m)
{
    int sm = 0;
    for (int i = 0; i < m; i++)
        sm += a[i];
    return sm;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int** mas, n, m, i, j;
    cout << "Введите количество строк:" << endl;
    cin >> n;
    cout << "Введите количество элементов в строке:" << endl;
    cin >> m;
    mas = new int* [n];
    for (i = 0; i < n; i++) {
        mas[i] = new int[m];
    }
    cout << "Изначальный вид матрицы:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            mas[i][j] = rand() % 21 - 10;
            cout << setw(5) << mas[i][j];
        }
        cout << endl;
    }
    for (i = n - 1; i; i--)
        for (j = 0; j < i; j++)
            if (sum(mas[j], m) > sum(mas[i], m))swap(mas[j], mas[i]);
    cout << endl << "Конечный вид матрицы:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << setw(5) << mas[i][j];
        }
        cout << endl;
    }
    return 0;
}