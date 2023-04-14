namespace ariel
{
    class Fraction{
        private:
            int numerator; // represents the numerator in the fraction
            int denominator; // represents the denominator in the fraction
        public:
            Fraction(int, int); // constructor
            ~Fraction() = default; // default destructor
    };

    int gcd(int, int); // returns the greatest common divisor of a and b, to be used to find the reduced form of a fraction
}