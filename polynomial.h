#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "member.h"
#include <map>

class Polynomial
{
private:
    std::map<int, Member> poly;

public:
    Polynomial() = default;
    Polynomial(int n, int c);
    Polynomial(const Polynomial &p);

    Polynomial &clear();

    // get polynomial values
    [[nodiscard]] int get_max_degree() const;
    [[nodiscard]] int get_coeff_by_degree(int n) const;

    // calculations
    [[nodiscard]] Polynomial &change_signs() const;
    [[nodiscard]] Polynomial &derivative() const;

    // operator overload
    Polynomial &operator+(const Polynomial &p) const;
    Polynomial &operator*(const Polynomial &p) const;
    Polynomial &operator-(const Polynomial &p) const;
    bool operator==(const Polynomial &p) const;

    [[nodiscard]] std::string to_string();

};

#endif //POLYNOMIAL_H
