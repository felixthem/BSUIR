// LR5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//#include <bits/stdc++.h>

using namespace std;

void DeleteRow(int** A, int k, int N, int M)
{
    for (int i = k; i < N - 1; i++)
    {
        for (int j = 0; j < M; j++)
        {
            A[i][j] = A[i + 1][j];
        }
    }
}

void DeleteColumn(int** A, int k, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = k; j < M - 1; j++)
        {
            A[i][j] = A[i][j + 1];
        }
    }
}

void MatrixInput(int** A, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }
}

void MatrixOutput(int** A, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N, M, x, y, min=0;
    cout << "Enter a matrix size:" << endl;
    cout << "N = ";
    cin >> N;
    cout << "M = ";
    cin >> M;
    int** A = new int* [N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new int[M];
    }
    cout << "Enter a matrix:" << endl;
    MatrixInput(A, N, M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (abs(A[i][j] > min))
            {
                min = abs(A[i][j]);
                x = i;
                y = j;
            }
        }
    }
    cout << "Target info:" << "\n";
    cout << "Found element: " << min << "\n";
    cout << "Row: " << x + 1 << "\n";
    cout << "Column: " << y + 1 << "\n";

    DeleteRow(A, x, N, M);
    DeleteColumn(A, y, N, M);

    cout << "Matrtix after the delete:" << endl;
    MatrixOutput(A, N - 1, M - 1);
    for (int i = 0; i < N; i++)
    {
        delete[] A[i];
    }
    delete[] A;
    system("pause");
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
