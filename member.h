#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
private:
    int degree = 0;
    int coeff = 0;

public:
    Member()  = default;
    Member(int d, int c) : degree(d), coeff(c) { };

    // setters
    void set_degree(int d);
    void set_coeff(int c);

    // getters
    [[nodiscard]] int get_degree() const;
    [[nodiscard]] int get_coeff() const;

    // calculations
    [[nodiscard]] Member derivative() const;
    [[nodiscard]] int calculate(double x) const;

    // operator overload
    bool operator == (const Member &elem) const;

    [[nodiscard]] std::string to_string() const;
};

#endif //MEMBER_H
