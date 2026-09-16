#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
    double x;
    int k;
    int n=1;
    cin >>x;
    cin >>k;
    double o = 1.0;
    double sum = o;
    double eps = pow(10.0, -k);
    while (abs(o)>eps)
    {
        o *= - (x * x) / ((2 * n - 1) * (2 * n));
        n++;
        sum+=o;
    }
    double cosx = cos(x);
    double diff = abs(sum - cosx);
    cout << fixed << setprecision(k);
    cout << "Приближение ряда:    " << sum << "\n";
    cout << "Библиотечный cos(x): " << cosx << "\n";
    cout << "Погрешность:         " << diff << "\n";
    cout << "Суммировано членов:  " << n << "\n";

    return 0;
}