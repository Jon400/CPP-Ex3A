#include "Fraction.hpp"
#include <stdexcept>
#include <sstream>

using namespace ariel;

/*
Inline implementation of the Fraction class
*/

ariel::Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

ariel::Fraction::Fraction(float f)
{
}

Fraction& ariel::Fraction::operator=(const Fraction & r)
{
    return *this;
}


Fraction& ariel::Fraction::operator=(const float & f)
{
    return *this;
}

Fraction ariel::Fraction::operator+(const Fraction & r) const
{
    return Fraction();
}

Fraction ariel::Fraction::operator+(const float & f) const
{
    return Fraction();
}

Fraction ariel::operator+(const float & f, const Fraction & r)
{
    return Fraction();
}

Fraction ariel::Fraction::operator-(const Fraction & r) const
{
    return Fraction();
}

Fraction ariel::Fraction::operator-(const float & f) const
{
    return Fraction();
}

Fraction ariel::operator-(const float & f, const Fraction & r)
{
    return Fraction();
}

Fraction ariel::Fraction::operator*(const Fraction & r) const
{
    return Fraction();
}

Fraction ariel::Fraction::operator*(const float & f) const
{
    return Fraction();
}

Fraction ariel::operator*(const float & f, const Fraction & r)
{
    return Fraction();
}

Fraction ariel::Fraction::operator/(const Fraction & r) const
{
    return Fraction();
}

Fraction ariel::Fraction::operator/(const float & f) const
{
    return Fraction();
}

bool ariel::Fraction::operator==(const Fraction & r) const
{
    return false;
}

bool ariel::Fraction::operator==(const float & f) const
{
    return false;
}

bool ariel::operator==(const float & f, const Fraction & r)
{
    return false;
}

Fraction ariel::operator/(const float & f, const Fraction & r)
{
    return Fraction();
}

bool ariel::Fraction::operator>(const Fraction & r) const
{
    return false;
}

bool ariel::Fraction::operator>(const float & f) const
{
    return false;
}

bool ariel::operator>(const float & f, const Fraction & r)
{
    return false;
}

bool ariel::Fraction::operator<(const Fraction & r) const
{
    return false;
}

bool ariel::Fraction::operator<(const float & f) const
{
    return false;
}

bool ariel::operator<(const float & f, const Fraction & r)
{
    return false;
}

bool ariel::Fraction::operator>=(const Fraction & r) const
{
    return false;
}

bool ariel::Fraction::operator>=(const float & f) const
{
    return false;
}

bool ariel::operator>=(const float & f, const Fraction & r)
{
    return false;
}

bool ariel::Fraction::operator<=(const Fraction & r) const
{
    return false;
}

bool ariel::Fraction::operator<=(const float & f) const
{
    return false;
}

bool ariel::operator<=(const float & f, const Fraction & r)
{
    return false;
}

Fraction& ariel::Fraction::operator++()
{
    return *this;
}

Fraction ariel::Fraction::operator++(int dummy)
{
    return Fraction();
}

Fraction& ariel::Fraction::operator--()
{
    return *this;
}

Fraction ariel::Fraction::operator--(int dummy)
{
    return Fraction();
}

std::ostream& ariel::operator<<(std::ostream & output, const Fraction & r)
{
    return output;
}

std::ostream &ariel::operator<<(std::ostream & output, const float & f)
{
    return output;
}

std::istream& ariel::operator>>(std::istream & input, Fraction & r)
{
    return input;
}

std::istream &ariel::operator>>(std::istream & input, float & f)
{
    return input;
}
