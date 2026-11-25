#include "Fraction.h"

#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    int a, b, c, d;
    cout << "Введите два числителя и знаменателя по порядку (a b c d): ";
    if (!(cin >> a >> b >> c >> d)) {
        cout << "Ожидалось четыре целых числа\n";
        return 1;
    }

    try {
        Fraction f(a, b);
        Fraction g(c, d);
        Fraction h(f);

        cout << "Первая дробь после сокращения: "
             << h.getNumerator() << '/' << h.getDenominator() << '\n';
        cout << "Сумма: ";
        h.add(g).print();
        cout << "\nПроизведение: ";
        h.multiply(g).print();
        cout << "\nЧастное: ";
        h.divide(g).print();
        cout << '\n';
    } catch (const exception& e) {
        cout << e.what() << '\n';
        return 1;
    }
}
