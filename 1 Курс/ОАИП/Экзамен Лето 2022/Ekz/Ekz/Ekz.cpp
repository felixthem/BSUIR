#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    char arr[] = "asdasd aaaaa aaa aaaaaaaaa";
    cout << "Vvedite stroky: ";
    cin.getline(arr, 256);
    char* p;
    int kol, num = 0, n = 0;

    p = strtok(arr, " ");
    kol = strlen(p);


    while (p != NULL)
    {
        n++;
        if (strlen(p) < kol)
        {
            kol = strlen(p);
            num = n;
        }
        p = strtok(NULL, " ");
    }
    cout << "Poradkovii nomer slova " << num << "\n";
    cout << "kol bukv " << kol << "\n";
    
    /*for (int i = 0; i < 5; i++)
    {
        cout << arr[i];
    }*/

    system("PAUSE");
    return EXIT_SUCCESS;
}