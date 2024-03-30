#include <iostream>
#include <cmath>

class Rational {
private:
    int numerator;
    int denominator;

    // Helper function to compute the greatest common divisor (GCD)
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

public:
    // Constructor with default values (1/1)
    Rational(int num = 1, int denom = 1) {
        // Ensure non-zero denominator
        if (denom == 0) {
            std::cerr << "Error: Denominator cannot be zero. Setting to 1." << std::endl;
            denom = 1;
        }

        // Reduce the fraction to its simplest form
        int commonDivisor = gcd(std::abs(num), std::abs(denom));
        numerator = num / commonDivisor;
        denominator = denom / commonDivisor;
    }

    // Addition of two Rational numbers
    Rational add(const Rational& other) const {
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Rational(newNumerator, newDenominator);
    }

    // Subtraction of two Rational numbers
    Rational subtract(const Rational& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Rational(newNumerator, newDenominator);
    }

    // Multiplication of two Rational numbers
    Rational multiply(const Rational& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Rational(newNumerator, newDenominator);
    }

    // Division of two Rational numbers
    Rational divide(const Rational& other) const {
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Rational(newNumerator, newDenominator);
    }

    // Print Rational number in the form a/b
    void printFraction() const {
        std::cout << numerator << "/" << denominator;
    }

    // Print Rational number in floating-point format
    void printFloatingPoint() const {
        double result = static_cast<double>(numerator) / denominator;
        std::cout << result;
    }
};

int main() {
    Rational r1(4, 8); 
    Rational r2(2, 5);

    Rational sum = r1.add(r2);
    Rational difference = r1.subtract(r2);
    Rational product = r1.multiply(r2);
    Rational quotient = r1.divide(r2);

    std::cout << "Sum: ";
    sum.printFraction();
    std::cout << " ("; sum.printFloatingPoint(); std::cout << ")" << std::endl;

    std::cout << "Difference: ";
    difference.printFraction();
    std::cout << " ("; difference.printFloatingPoint(); std::cout << ")" << std::endl;

    std::cout << "Product: ";
    product.printFraction();
    std::cout << " ("; product.printFloatingPoint(); std::cout << ")" << std::endl;

    std::cout << "Quotient: ";
    quotient.printFraction();
    std::cout << " ("; quotient.printFloatingPoint(); std::cout << ")" << std::endl;

    return 0;
}
