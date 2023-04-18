#include "doctest.h"
#include "sources/Fraction.hpp"
#include <iostream>
#include <sstream>

using namespace ariel;

TEST_CASE("Fraction arithmetic")
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    CHECK(a + b == Fraction(5, 6));
    CHECK(a - b == Fraction(1, 6));
    CHECK(a * b == Fraction(1, 6));
    CHECK(a / b == Fraction(3, 2));
    CHECK(a + 1 == Fraction(3, 2));
    CHECK(a - 1 == Fraction(-1, 2));
    CHECK(a * 2 == Fraction(1, 1));
    CHECK(a / 2 == Fraction(1, 4));
    CHECK(1 + a == Fraction(3, 2));
    CHECK(1 - a == Fraction(1, 2));
    CHECK(2 * a == Fraction(1, 1));
    CHECK(2 / a == Fraction(4, 1));
    CHECK(++a == Fraction(3, 2));
    CHECK(a++ == Fraction(3, 2));
    CHECK(a == Fraction(5, 2));
    CHECK(--a == Fraction(3, 2));
    CHECK(a-- == Fraction(3, 2));
    CHECK(a == Fraction(1, 2));
    CHECK_FALSE(a==b);
    CHECK(a>b);
    CHECK_FALSE(a<b);
    CHECK(a>=b);
    CHECK_FALSE(a<=b);
}

TEST_CASE("Fraction and float arithmetic")
{
    Fraction a(1, 2);
    float b = 0.4332;

    CHECK(a + b == 0.9332);
    CHECK(a - b == 0.0668);
    CHECK(a / b == (Fraction(1, 2) / Fraction(0.4332f)));

    CHECK(b + a == 0.9332);
    CHECK(b - a == -0.067);
    CHECK(b / a == 0.8664);
}

TEST_CASE("Floats arithmetic")
{
    float a = 0.4332;
    float b = 0.5885;

    CHECK((a + b) == Fraction(511, 500));
    CHECK((a - b) == Fraction(31, -200));
    CHECK(a * b == Fraction(51, 200));
    CHECK(a / b == Fraction(92, 125));
}

TEST_CASE("IO not throwing exception")
{
    Fraction a(1, 2);
    Fraction b(1, 3);
    float c = 0.4332;
    std::stringstream ss("");

    CHECK_NOTHROW(ss << a);
    CHECK_NOTHROW(ss << c);
    CHECK_NOTHROW(ss >> a);
    CHECK_NOTHROW(ss << (b + c));
    CHECK_NOTHROW(ss << (a - b));
}

TEST_CASE("IO")
{
    Fraction a(1, 2);
    Fraction b(1, 3);
    float c = 0.4332f;

    std::stringstream ss;
    ss << a;
    CHECK(ss.str() == "1/2");
    ss.str("");

    ss << "1/3";
    ss >> a;
    CHECK(a == Fraction(1, 3));

    a = Fraction(1, 2);
    ss.str("");

    ss.clear();
    ss << "0.558";
    ss >> c;
    CHECK(c == Fraction(279, 500));

    c = 0.4332;

    ss.str("");
    ss.clear();
    ss << "";
    ss << (a + b);
    CHECK(ss.str() == "5/6");

    ss.str("");
    ss << "";
    ss << (a - c) << std::endl;
    CHECK(ss.str() == "67/1000\n");
}

TEST_CASE("Invalid fraction")
{
    CHECK_THROWS(Fraction(1, 0));
    CHECK_THROWS(Fraction(0, 0));
    CHECK_NOTHROW(Fraction(0, 1));
    CHECK_NOTHROW(Fraction(1, -1));
}

TEST_CASE("Invalid arithmetic operation")
{
    Fraction a(1, 2);
    Fraction b(1, 2);
    float c = 0.4332;
    
    CHECK_THROWS(c / (a -b));
    CHECK_THROWS(a / (a -b));
    CHECK_THROWS(a / 0);
}

TEST_CASE("Reduced form")
{
    Fraction a(288, 432);
    std::stringstream ss;

    ss << a;
    CHECK(ss.str() == "2/3");
}

TEST_CASE("Negative sign in fraction")
{
    Fraction a(-1, 2);
    Fraction b(1, -2);
    Fraction c(-1, -2);
    Fraction d(1, 2);
    std::stringstream ss;

    CHECK(a == b);
    CHECK(c == d);
    CHECK(a < d);

    ss << a;
    CHECK(ss.str() == "-1/2");
    ss.str("");
    ss.clear();

    ss << b;
    CHECK(ss.str() == "-1/2");
    ss.str("");
    ss.clear();

    ss << c;
    CHECK(ss.str() == "1/2");
    ss.str("");
    ss.clear();

    ss << d;
    CHECK(ss.str() == "1/2");
    ss.str("");
    ss.clear();
}

TEST_CASE("Commutative law")
{
    Fraction a(1, 2);
    Fraction b(1, 3);
    float c = 0.4332;

    CHECK(a + b == b + a);
    CHECK(a * b == b * a);
    CHECK(a + c == c + a);
    CHECK(a * c == c * a);
}

TEST_CASE("Distribution law")
{
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c(1, 4);
    float d = 0.4332;

    CHECK(a * (b + c) == a * b + a * c);
    CHECK((a + b) * c == a * c + b * c);
    CHECK(a * (b + d) == a * b + a * d);
    CHECK((a + b) * d == a * d + b * d);
}

TEST_CASE("Associative law")
{
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c(1, 4);
    float d = 0.4332;

    CHECK(a * (b * c) == (a * b) * c);
    CHECK(a + (b + c) == (a + b) + c);
    CHECK(a * (b * d) == (a * b) * d);
    CHECK(a + (b + d) == (a + b) + d);
}