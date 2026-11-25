#include "Fraction.h"

#include <climits>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

static long long product(long long x, long long y) {
    if (y != 0 && abs(x) > LLONG_MAX / abs(y)) {
        throw overflow_error("Слишком большое число");
    }
    return x * y;
}

Fraction::Fraction(long long numerator, long long denominator) : a(numerator), b(denominator) {
    if (b == 0) {
        throw invalid_argument("Знаменатель не может быть нулём");
    }
    if (a == LLONG_MIN || b == LLONG_MIN) {
        throw overflow_error("Слишком большое по модулю число");
    }
    reduce();
}

Fraction::Fraction(const Fraction& f) : a(f.a), b(f.b) {
}

void Fraction::reduce() {
    long long x = abs(a);
    long long y = abs(b);
    while (y != 0) {
        long long r = x % y;
        x = y;
        y = r;
    }
    a /= x;
    b /= x;
    if (b < 0) {
        a = -a;
        b = -b;
    }
}

long long Fraction::getNumerator() const {
    return a;
}

long long Fraction::getDenominator() const {
    return b;
}

Fraction Fraction::add(const Fraction& f) const {
    long long x = product(a, f.b);
    long long y = product(f.a, b);
    if ((y > 0 && x > LLONG_MAX - y) || (y < 0 && x < -LLONG_MAX - y)) {
        throw overflow_error("Слишком большая сумма");
    }
    return Fraction(x + y, product(b, f.b));
}

Fraction Fraction::multiply(const Fraction& f) const {
    return Fraction(product(a, f.a), product(b, f.b));
}

Fraction Fraction::divide(const Fraction& f) const {
    if (f.a == 0) {
        throw invalid_argument("Деление на нулевую дробь");
    }
    return Fraction(product(a, f.b), product(b, f.a));
}

void Fraction::print() const {
    if (b == 1) {
        cout << a;
    } else {
        cout << a << '/' << b;
    }
}
