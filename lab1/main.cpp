#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    long double x;
    int k;
    const int maxK = numeric_limits<long double>::digits10;

    cout << "Введите x и k (от 2 до " << maxK << "): ";
    if (!(cin >> x >> k) || !isfinite(x) || k < 2 || k > maxK) {
        cout << "Некорректный ввод\n";
        return 1;
    }

    const long double pi = acos(-1.0L);
    long double t = remainder(x, 2 * pi);
    long double e = 0.5L;
    for (int i = 0; i < k; ++i) {
        e /= 10;
    }

    long double a = 1;
    long double s = 0;
    int n = 0;

    while (abs(a) >= e) {
        s += a;
        ++n;
        a = -a * t * t / ((2 * n - 1) * (2 * n));
    }

    cout << fixed << setprecision(k);
    cout << "Ряд Тейлора: " << s << '\n';
    cout << "Функция cos: " << cos(x) << '\n';
}
