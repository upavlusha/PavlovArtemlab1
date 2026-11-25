#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
    long long a;
    long long b;

    void reduce();

public:
    Fraction(long long numerator, long long denominator);
    Fraction(const Fraction& f);
    Fraction() = delete;

    long long getNumerator() const;
    long long getDenominator() const;
    Fraction add(const Fraction& f) const;
    Fraction multiply(const Fraction& f) const;
    Fraction divide(const Fraction& f) const;
    void print() const;
};

#endif
