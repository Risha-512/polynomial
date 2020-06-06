#include "member.h"
#include <cmath>

void Member::set_degree(int d)
{ degree = d; }

void Member::set_coeff(int c)
{ coeff = c; }

int Member::get_degree() const
{ return degree; }

int Member::get_coeff() const
{ return coeff; }

int Member::calculate(double x) const
{ return pow(x, degree) * coeff; }

Member Member::derivative() const
{ return degree ? Member(degree - 1, degree * coeff) : Member(0, 0); }

bool Member::operator==(const Member &elem) const
{ return coeff == elem.coeff && degree == elem.degree; }

std::string Member::to_string() const
{
    switch (coeff)
    {
        case 0:
            return "0";
        case 1:
        case -1:
            if (!degree)
                return std::to_string(coeff);
            else
                return (coeff < 0 ? "-" : "") + (degree == 1 ? "x" : "x^" + std::to_string(degree));
        default:
            return std::to_string(coeff) + (degree == 0
                ? ""
                : (degree == 1
                    ? "x"
                    : "x^" + std::to_string(degree)));
    }
}
