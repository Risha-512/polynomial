#include "polynomial.h"
#include <algorithm>

Polynomial::Polynomial(int n, int c)
{ poly.insert(std::make_pair(n, Member(n, c))); }

Polynomial::Polynomial(const Polynomial &p)
{ poly = p.poly; }

Polynomial& Polynomial::clear()
{
    poly.clear();
    return *this;
}

int Polynomial::get_max_degree() const
{
    return std::max_element(poly.begin(), poly.end(),
            [](auto const &a, auto const &b)
            { return a.first < b.first; })->first;
}

int Polynomial::get_coeff_by_degree(int n) const
{ return poly.count(n) ? poly.find(n)->second.get_coeff() : 0; }

Polynomial& Polynomial::change_signs() const
{
    auto result = new Polynomial(*this);
    for (auto const &elem : result->poly)
        result->poly[elem.first] = Member(elem.first, -elem.second.get_coeff());

    return *result;
}

Polynomial& Polynomial::derivative() const
{
    auto result = new Polynomial();
    for (auto const &elem : poly)
    {
        auto d = elem.second.derivative();
        if (d.get_coeff())
            result->poly.insert(std::make_pair(elem.first, d));
    }

    return *result;
}

Polynomial& Polynomial::operator+(const Polynomial &p) const
{
    auto result = new Polynomial(*this);

    for (auto const &elem : p.poly)
    {
        int degree = elem.first;

        if (!poly.count(degree))
            result->poly.insert(elem);
        else
        {
            int coeff = get_coeff_by_degree(degree) + elem.second.get_coeff();
            if (!coeff)
                result->poly.erase(degree);
            else
                result->poly[degree].set_coeff(coeff);
        }
    }

    return *result;
}

Polynomial& Polynomial::operator*(const Polynomial &p) const
{
    auto result = new  Polynomial();

    for (auto const &elem1 : poly)
    {
        for (auto const &elem2 : p.poly)
        {
            int degree = elem1.first + elem2.first;
            int coeff = elem1.second.get_coeff() * elem2.second.get_coeff();

            if (!(coeff))
                continue;

            if (!result->poly.count(degree))
                result->poly.insert(std::make_pair(degree, Member(degree, coeff)));
            else
            {
                if (!(coeff += result->poly[degree].get_coeff()))
                    result->poly.erase(degree);
                else
                    result->poly[degree].set_coeff(coeff);
            }
        }
    }

    return *result;
}

Polynomial& Polynomial::operator-(const Polynomial &p) const
{ return Polynomial(*this) + p.change_signs(); }

bool Polynomial::operator==(const Polynomial &p) const
{ return poly == p.poly; }

std::string Polynomial::to_string()
{
    if (poly.empty())
        return "0";
    std::string result;

    for (auto const &elem : poly)
    {
        std::string member = elem.second.to_string();
        result += member[0] == '-' ? member : "+" + member;
    }

    if (result[0] == '+')
        result.erase(result.begin());

    return result;
}
