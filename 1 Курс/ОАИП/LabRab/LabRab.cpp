#include <iostream>
using namespace std;

int main()
{
    double x, y, f, a, s;
    int k;
    cout << "Vvedite x "; cin >> x;
    cout << "Vvedite y "; cin >> y;
    cout << "Viberite f: 1 - sh(x), 2 - x^2, 3 – exp(x) "; cin >> k;
    switch (k)
    {
    case 1: f = sinh(x); break;
    case 2: f = pow(x, 2); break;
    case 3: f = exp(x); break;
    default: cout << "Ne vuibrana funkciya "; return 1;
    }

    if ((x / y) < 0)
    {
        s = pow((pow(f, 2) + y), 3);
    }
    else if ((x / y) > 0)
    {
        s = log(fabs(f / y) + x / y);
    }
    else
    {
        s = pow(fabs(sin(y)), 3);
    }
    cout << "RESULT = " << s << endl;
    cin;
    return 0;
}
