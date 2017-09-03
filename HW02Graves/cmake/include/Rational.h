/**
Rational.h
Contains source for rational class

created by shadySource
*/
#include <cstdio>
class Rational{

    int numerator, denominator; //numerator, denominator

public:
    Rational operator+(Rational secondRational)
    {
        int tempNumerator(numerator * secondRational.denominator+denominator*secondRational.numerator);
        int tempDenominator(denominator*secondRational.denominator);
        return Rational(tempNumerator, tempDenominator);
    }

    Rational operator-(Rational secondRational)
    {
        int tempNumerator(numerator * secondRational.denominator-denominator*secondRational.numerator);
        int tempDenominator(denominator*secondRational.denominator);
        return Rational(tempNumerator, tempDenominator);
    }

    Rational operator*(Rational secondRational)
    {
        int tempNumerator(numerator * secondRational.numerator);
        int tempDenominator(denominator*secondRational.denominator);
        return Rational(tempNumerator, tempDenominator);
    }

    Rational operator/(Rational secondRational)
    {
        int tempNumerator(numerator * secondRational.denominator);
        int tempDenominator(denominator*secondRational.numerator);
        return Rational(tempNumerator, tempDenominator);
    }

    Rational operator+(int integer)
    {
        int tempNumerator(numerator + denominator * integer);
        int tempDenominator(denominator);
        return Rational(tempNumerator, tempDenominator);
    }

    Rational operator-(int integer)
    {
        int tempNumerator(numerator - denominator * integer);
        int tempDenominator(denominator);
        return Rational(tempNumerator, tempDenominator);
    }

    Rational operator*(int integer)
    {
        int tempNumerator(numerator * integer);
        int tempDenominator(denominator);
        return Rational(tempNumerator, tempDenominator);
    }

    Rational operator/(int integer)
    {
        int tempNumerator(numerator);
        int tempDenominator(denominator * integer);
        return Rational(tempNumerator, tempDenominator);
    }

    int getNumer()
    {
        return numerator;
    }

    int getDenom()
    {
        return denominator;
    }

    void print()
    {
        printf("%d/%d\n", numerator, denominator);
    }

    int GreatestCommonFactor(int x, int y, int z)
    {
        z = x % y;
        if (y && z)
        {
            return GreatestCommonFactor(y,z,0);
        }
        else
        {
            return y;
        }
        return y&&(z=x%y) ? GreatestCommonFactor(y,z,0) : y;
    }

    void Reduce() //reduce
    {
        int factor(GreatestCommonFactor(numerator, denominator, 0));
        numerator/=factor;
        denominator/=factor;
    }

    Rational() :numerator(0),denominator(1) {}
    Rational(int Numerator, int Denominator) :numerator(Numerator), denominator(Denominator) {}
};