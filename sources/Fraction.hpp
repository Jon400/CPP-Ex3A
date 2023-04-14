namespace ariel
{
    class Fraction{
        private:
            int numerator; // represents the numerator in the fraction
            int denominator; // represents the denominator in the fraction
        public:
            Fraction(int, int); // constructor
            Fraction operator+(const Fraction&) const; // addition operator for fractions
            Fraction operator=(const float&) const; // assignment operator for floats; 
            friend Fraction operator+(const Fraction&, const float&); // addition operator for fractions and floats
            friend Fraction operator+(const float&, const Fraction&); // addition operator for fractions and floats
            //friend Fraction operator+(const float&, const float&); // addition operator for floats
            //friend operator+(const float&, const Fraction&); // addition operator for fractions and floats
            ~Fraction() = default; // default destructor
    };

    int gcd(int, int); // returns the greatest common divisor of a and b, to be used to find the reduced form of a fraction
}