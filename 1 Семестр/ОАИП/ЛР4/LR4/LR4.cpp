#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int  i, j, k, n;
    int mas[10];
    j = 0;
    cout << "Введите число элементов массива: " << endl;
    cin >> k;
    if (k > 10) {
        cout << "Ошибка!" << endl;
        return 1;
    }
    else {
        //cout << "Первоначальный массив: " << endl;
        for (i = 0; i < k; i++) {
            cout << "Введите элемент массива [" << i << "]:";
            cin >> mas[i];
            //mas[i] = rand() % 101 - 50;
            cout << endl;
            cout << mas[i] << setw(5);
            cout << endl;
        }
        cout << endl;
        
        for (i = k - 1; i; i--)
            for (j = 0; j < i; j++)
                if (mas[j] >= 0 && mas[j + 1] < 0) swap(mas[j], mas[j + 1]);

        cout << "Измененный массив:" << endl;
        for (j = 0; j < k; j++) {
            cout << mas[j] << setw(5);
        }
    }
    return 0;
}